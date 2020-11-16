#include "uls.h"

static void get_attributes(t_lattrib **lattrib, struct stat sb, int i);
static void check_and_print_files(t_lattrib **lattrib, t_flags *flags, t_sorted_odj *sort, int num_of_current_dir);
static void check_and_open_dirs(t_lattrib **lattrib, t_flags *flags, t_sorted_odj *sort);
static void total_blocks(t_flags *flags, t_lattrib **lattrib, t_sorted_odj *sort);
static void print_dir_name(t_flags *flags, t_sorted_odj *sort, t_lattrib **lattrib, int num_of_current_dir);
static int get_dir_len(char *obj, t_flags *flags);

void mx_flag_l(t_flags *flags, t_sorted_odj *sort) {
        mx_alphabet_sort(flags->all_obj, flags->count_obj);
        mx_file_dir_sort(sort, flags);
        t_lattrib **lattrib = NULL;
        check_and_print_files(lattrib, flags, sort, -1);
        check_and_open_dirs(lattrib, flags, sort);
}

static void check_and_open_dirs(t_lattrib **lattrib, t_flags *flags, t_sorted_odj *sort) {
    DIR *d;
    char *dir_without_permission = NULL;
    struct dirent *dir;
    int i = 0;
    sort->len_of_files_array = 0;
    if (flags->count_obj != 0) {
        for (int j = 0; j < sort->len_of_dirs_array; j++) {
            d = opendir(sort->dirs[j]);
            sort->len_of_files_array = get_dir_len(sort->dirs[j], flags); // get number of files inside of dir
            if (sort->len_of_files_array == 0 && sort->len_of_dirs_array > 1) {
                if (j != 0) {
                    mx_printchar('\n');
                }
                mx_printstr(sort->dirs[j]);
                mx_printstr(":\n");
                if (d) {
                    closedir(d);
                    continue;
                }
            }
            if (d) {
                sort->files = (char **)malloc(sizeof(char *) * sort->len_of_files_array + 1);
                while ((dir = readdir(d)) != NULL) {
                    if (dir->d_name[0] != '.') { // case without '-a' and '-A'
                        sort->files[i] = mx_strdup(dir->d_name);
                        i++;
                    }
                }
                mx_alphabet_sort(sort->files, sort->len_of_files_array);
                check_and_print_files(lattrib, flags, sort, j);
                closedir(d);
                i = 0;
            }
            else {
                dir_without_permission = mx_memrchr(sort->dirs[j], '/', mx_strlen(sort->dirs[j]));
                if (dir_without_permission != NULL) {
                    dir_without_permission++;
                    mx_print_permission_error(dir_without_permission);
                    dir_without_permission = NULL;
                }
                else
                    mx_print_permission_error(sort->dirs[j]);
            }
        }
    }
    else {
            d = opendir(".");
            sort->len_of_files_array = get_dir_len(".", flags); // get number of files inside of dir
            sort->files = (char **)malloc(sizeof(char *) * sort->len_of_files_array);
            while((dir = readdir(d)) != NULL) {
                if (dir->d_name[0] != '.') { // case without '-a' and '-A'
                    sort->files[i] = mx_strdup(dir->d_name);
                    i++;
                }
            }
            mx_alphabet_sort(sort->files, sort->len_of_files_array);
            check_and_print_files(lattrib, flags, sort, -1);
            closedir(d);
    }
}

static void check_and_print_files(t_lattrib **lattrib, t_flags *flags, t_sorted_odj *sort, int num_of_current_dir) {
    struct stat sb;
    char *temp_path_name = NULL;

    if (sort->len_of_files_array > 0) {
        lattrib = (t_lattrib **)malloc(sizeof(t_lattrib *) * sort->len_of_files_array);
        for (int i = 0; i < sort->len_of_files_array; i++) {
            lattrib[i] = malloc(sizeof(t_lattrib));
            lattrib[i]->name = mx_strdup(sort->files[i]);
            if (num_of_current_dir == -1) {
                temp_path_name = mx_strnew(mx_strlen(sort->files[i]));
                mx_strcpy(temp_path_name, sort->files[i]);
            }
            else {
                temp_path_name = mx_strnew(mx_strlen(sort->dirs[num_of_current_dir]) + 1 + mx_strlen(sort->files[i]));
                mx_strcpy(temp_path_name, sort->dirs[num_of_current_dir]);
                mx_strcat(temp_path_name, "/");
                mx_strcat(temp_path_name, sort->files[i]);
            }
            lstat(temp_path_name, &sb);
            get_attributes(lattrib, sb, i);
            mx_get_acl_xattr(temp_path_name, lattrib, i);
            if (S_ISLNK(sb.st_mode)) { // get link to output name
                int links = 0;
                lattrib[i]->link_str = mx_strnew(sb.st_size);
                links = readlink(temp_path_name, lattrib[i]->link_str, sb.st_size);
            }
            mx_strdel(&temp_path_name);
        }
        if (flags->count_obj == 0)
            total_blocks(flags, lattrib, sort);
        if (sort->len_of_dirs_array != 0 && num_of_current_dir != -1)
            print_dir_name(flags, sort, lattrib, num_of_current_dir);
        mx_check_what_to_print(flags, lattrib, sort);
        if (num_of_current_dir == -1 && sort->len_of_dirs_array > 0)
            mx_printchar('\n');
        mx_strdel(&sort->files[sort->len_of_files_array - 1]);
        mx_del_strarr(&sort->files);
    }
}

static void get_attributes(t_lattrib **lattrib, struct stat sb, int i) {
    struct passwd *passwd; // get username
    struct group *groupid; // get group id name
    mx_specify_type_file(sb, lattrib, i);
    mx_print_permissions_list(lattrib, sb, i);
    lattrib[i]->id = sb.st_ino;
    lattrib[i]->links = sb.st_nlink;
    passwd = getpwuid(sb.st_uid);
    lattrib[i]->user = mx_strdup(passwd->pw_name);
    groupid = getgrgid(sb.st_gid);
    if (groupid == NULL)
        lattrib[i]->group = mx_itoa(sb.st_gid);
    else
        lattrib[i]->group = mx_strdup(groupid->gr_name);

    lattrib[i]->size = sb.st_size;
    mx_time_modif(sb, lattrib, i);
    lattrib[i]->bl = sb.st_blocks;
}

static void total_blocks(t_flags *flags, t_lattrib **lattrib, t_sorted_odj *sort) {
    int bl_sum = 0;

    for (int i = 0; i < sort->len_of_files_array; i++) {
        bl_sum += lattrib[i]->bl;
    }
    mx_printstr("total ");
    mx_printint(bl_sum);
    mx_printchar('\n');
}

static void print_dir_name(t_flags *flags, t_sorted_odj *sort, t_lattrib **lattrib, int num_of_current_dir) {
    if (num_of_current_dir != -1) {
        if (flags->count_obj != 1) {
            if (num_of_current_dir != 0)
                mx_printchar('\n');
            mx_printstr(sort->dirs[num_of_current_dir]);
            mx_printstr(":\n");
        }
        total_blocks(flags, lattrib, sort);
    }
}

static int get_dir_len(char *obj, t_flags *flags) {
    DIR *d;
    int len_of_array = 0;
    struct dirent *directory;
    d = opendir(obj);
    if (d) {
        while ((directory = readdir(d)) != NULL) {
            if (flags->switch_flags[0] == 1 || flags->switch_flags[6] == 1){
                if (flags->switch_flags[0] == 1) { // 'a' case
                    len_of_array++;
                }
                else if (flags->switch_flags[6] == 1 && (mx_strcmp(".", directory->d_name) != 0 && mx_strcmp("..", directory->d_name) != 0)) {
                    len_of_array++;
                }
            }
            else {
                if (directory->d_name[0] != '.') {
                    len_of_array++;
                }
            }
        }
        closedir(d);
    }
    return len_of_array;
}
