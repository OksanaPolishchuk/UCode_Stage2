#include "uls.h"

static t_result *one_obj(char *obj, t_flags *flags);
static char *trim(char *string, char **current_file);
static void add_inode_to_name_of_file(t_sorted_odj *sort);
static void two_and_more_obj(t_flags *flags);
static void add_to_array(int max_len_of_inode, struct dirent *directory, char **array, int i);

void mx_flag_i(t_flags *flags) {
    t_result *struct_result = NULL;
    if (flags->number_of_obj == 0) {
        struct_result = one_obj(".", flags);
        if (isatty(1))
            mx_output_by_size_of_wind(struct_result->result, struct_result->length);
        else
            mx_output_in_one_column(struct_result->result, struct_result->length);
        mx_strdel(&struct_result->result[struct_result->length - 1]);
        mx_del_strarr(&struct_result->result);
        free(struct_result);
    }
    else if (flags->number_of_obj >= 1) {
        two_and_more_obj(flags);
    }
}

static t_result *one_obj(char *obj, t_flags *flags) {
    t_result *struct_result = (t_result *)malloc(sizeof(t_result));
    int len_of_array = 0;
    int max_len_of_inode;
    int i = 0;
    char **array = NULL;
    DIR *d;
    struct dirent *directory;
    d = opendir(obj);
    if (d) {
        struct_result->permission = true;
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
        max_len_of_inode = mx_max_len_of_inode(obj, flags);
        d = opendir(obj);
        array = (char **)malloc(sizeof(char *) * len_of_array);
        while ((directory = readdir(d)) != NULL) {
            if (flags->switch_flags[0] == 1 || flags->switch_flags[6] == 1) {
                if (flags->switch_flags[0] == 1) { // '-a' case
                    add_to_array(max_len_of_inode, directory, array, i);
                    i++;
                }
                else if (flags->switch_flags[6] == 1 &&
                        (mx_strcmp(".", directory->d_name) != 0 &&
                        mx_strcmp("..", directory->d_name) != 0)) { // case '-A'
                    add_to_array(max_len_of_inode, directory, array, i);
                    i++;
                }
            }
            else {
                if (directory->d_name[0] != '.') { // case without '-a' and '-A'
                    add_to_array(max_len_of_inode, directory, array, i);
                    i++;
                }
            }
        }
        closedir(d);
        mx_alphabet_sort2(array, len_of_array);
        if (flags->switch_flags[7] == 1)
            mx_array_reverse(array, len_of_array);
        if (len_of_array != 0) {
            struct_result->result = (char **) malloc(sizeof(char *) * len_of_array);
            for (int k = 0; k < len_of_array; ++k) {
                struct_result->result[k] = mx_strdup(array[k]);
            }
        }
        struct_result->length = len_of_array;
        if (len_of_array != 0) {
            mx_strdel(&array[len_of_array - 1]);
            mx_del_strarr(&array);
        } else
            free(array);
    }
    else if (errno == 13) {
        struct_result->permission = false;
    }
    return struct_result;
}

static char *trim(char *string, char **current_file) {
    int count = 0;
    int index = 0;
    bool has_slash = false;
    char *res = NULL;
    int len = mx_strlen(string);
    for (int j = 0; j < len; ++j) {
        if (*string == '/') {
            has_slash = true;
            index = count;
        }
        string++;
        count++;
    }
    string -= count;
    res = mx_strnew(index);
    if (has_slash) {
        for (int i = 0; i <= index; i++) {
            *res = *string;
            res++;
            string++;
        }
        index++;
    }
    *current_file = mx_strdup(string);
    string -= index;
    res -= index;
    if (index == 0) {
        res = mx_strcpy(res, ".");
    }
    return res;
}

static void two_and_more_obj(t_flags *flags) {
    t_result *struct_result = NULL;
    t_sorted_odj *sort = (t_sorted_odj *)malloc(sizeof(t_sorted_odj));
    sort->len_of_dirs_array = sort->len_of_files_array = 0;
    mx_file_dir_sort(sort, flags);
    if (sort->len_of_files_array != 0) {
        mx_alphabet_sort(sort->files, sort->len_of_files_array);
        if (flags->switch_flags[7] == 1)
            mx_array_reverse(sort->files, sort->len_of_files_array);
        add_inode_to_name_of_file(sort);
    }
    if (sort->len_of_dirs_array != 0) {
        mx_alphabet_sort(sort->dirs, sort->len_of_dirs_array);
        if (flags->switch_flags[7] == 1)
            mx_array_reverse(sort->dirs, sort->len_of_dirs_array);
    }
    if (sort->len_of_files_array != 0) {
        if (isatty(1))
            mx_output_by_size_of_wind(sort->files, sort->len_of_files_array);
        else
            mx_output_in_one_column(sort->files, sort->len_of_files_array);
    }
    for (int j = 0; j < sort->len_of_dirs_array; ++j) {
        if (flags->number_of_obj != 1) {
            if (j != 0 || sort->len_of_files_array != 0)
                mx_printchar('\n');
            mx_printstr(sort->dirs[j]);
            mx_printstr(":\n");
        }
        struct_result = one_obj(sort->dirs[j], flags);
        // --output--
        if (struct_result->permission) { // if we have permission for dir
            if (isatty(1))
                mx_output_by_size_of_wind(struct_result->result, struct_result->length);
            else
                mx_output_in_one_column(struct_result->result, struct_result->length);
        }
        else { // if we dont have permission
            char *current_file;
            char *temp = trim(sort->dirs[j], &current_file);
            mx_print_permission_error(current_file);
            mx_strdel(&current_file);
            mx_strdel(&temp);
        }
        // --
        if (struct_result->length != 0) {
            if (struct_result->result[struct_result->length - 1])
                mx_strdel(&struct_result->result[struct_result->length - 1]);
            mx_del_strarr(&struct_result->result);
            struct_result->length = 0;
        }
        free(struct_result);
    }
    if (sort->files)
        mx_del_strarr(&sort->files);
    if (sort->dirs)
        mx_del_strarr(&sort->dirs);
    free(sort);
}

static void add_inode_to_name_of_file(t_sorted_odj *sort) {
    char **array = (char **)malloc(sizeof(char *) * sort->len_of_files_array);
    DIR *d;
    struct dirent *directory;
    char *inode;
    for (int i = 0; i < sort->len_of_files_array; ++i) {
        char *current_file;
        char *current_dir = trim(sort->files[i], &current_file);
        d = opendir(current_dir);
        while ((directory = readdir(d)) != NULL) {
            if (mx_strcmp(directory->d_name, current_file) == 0) {
                array[i] = mx_strnew(mx_strlen(sort->files[i]) + mx_intlen(directory->d_ino) + 1);
                inode = mx_itoa(directory->d_ino);
                array[i] = mx_strcpy(array[i], inode);
                array[i] = mx_strcat(array[i], " ");
                array[i] = mx_strcat(array[i], sort->files[i]);
                mx_strdel(&inode);
            }
        }
        closedir(d);
        mx_strdel(&current_dir);
        mx_strdel(&current_file);
    }
    for (int j = 0; j < sort->len_of_files_array; ++j) {
        mx_strdel(&sort->files[j]);
        sort->files[j] = mx_strdup(array[j]);
        mx_strdel(&array[j]);
    }
    mx_del_strarr(&array);
}

static void add_to_array(int max_len_of_inode, struct dirent *directory, char **array, int i) {
    int temp;
    char *inode;

    temp = max_len_of_inode - mx_intlen(directory->d_ino);
    array[i] = mx_strnew(directory->d_namlen + max_len_of_inode + 1);
    if (temp != 0) {
        for (int j = 0; j < temp; ++j) {
            if (j == 0) {
                array[i] = mx_strcpy(array[i], " ");
            }
            else {
                array[i] = mx_strcat(array[i], " ");
            }
        }
        inode = mx_itoa(directory->d_ino);
        array[i] = mx_strcat(array[i], inode);
    }
    else {
        inode = mx_itoa(directory->d_ino);
        array[i] = mx_strcpy(array[i], inode);
    }
    array[i] = mx_strcat(array[i], " ");
    array[i] = mx_strcat(array[i], directory->d_name);
    mx_strdel(&inode);
}
