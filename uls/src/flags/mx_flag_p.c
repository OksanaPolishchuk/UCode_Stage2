#include "uls.h"

static void one_obj(char *obj, t_flags *flags);
static int get_dir_len(char *obj, t_flags *flags);
static void two_and_more_obj(t_flags *flags);
static void add_to_array(char **array, char *obj, int i, struct dirent *directory);
static char *trim(char *string, char **current_file);

void mx_flag_p(t_flags *flags) {
    if (flags->count_obj == 0) {
        one_obj(".", flags);
    }
    else if (flags->count_obj == 1) {
        two_and_more_obj(flags);
    }
    else if (flags->count_obj > 1) {
        two_and_more_obj(flags);
    }
}

static void one_obj(char *obj, t_flags *flags) {
    int len_of_array;
    int i = 0;
    char **array = NULL;
    DIR *d;
    struct dirent *directory;
    d = opendir(obj);
    if (d) {
        len_of_array = get_dir_len(obj, flags);
        array = (char **)malloc(sizeof(char *) * len_of_array);
        while ((directory = readdir(d)) != NULL) {
            if (flags->switch_flags[0] == 1 || flags->switch_flags[6] == 1) {
                if (flags->switch_flags[0] == 1) { // '-a' case
                    add_to_array(array, obj, i, directory);
                    i++;
                }
                else if (flags->switch_flags[6] == 1 &&
                         (mx_strcmp(".", directory->d_name) != 0 &&
                          mx_strcmp("..", directory->d_name) != 0)) { // case '-A'
                    add_to_array(array, obj, i, directory);
                    i++;
                }
            }
            else {
                if (directory->d_name[0] != '.') { // case without '-a' and '-A'
                    add_to_array(array, obj, i, directory);
                    i++;
                }
            }
        }
        closedir(d);
        // --sort and reverse--
        mx_alphabet_sort3(array, len_of_array);

        if (flags->switch_flags[7] == 1)
            mx_array_reverse(array, len_of_array);
        // --
        // --output
        if (flags->switch_flags[5] != 1)
            mx_output_by_size_of_wind(array, len_of_array);
        else
            mx_output_in_one_column(array, len_of_array);
        // --
        if (len_of_array != 0) {
            if (array[len_of_array - 1])
                mx_strdel(&array[len_of_array - 1]);
            if (array)
                mx_del_strarr(&array);
        } else
            free(array);
    }
    else { // permission error
        char *current_file;
        char *temp = trim(obj, &current_file);
        mx_print_permission_error(current_file);
        mx_strdel(&current_file);
        mx_strdel(&temp);
    }
}

static void two_and_more_obj(t_flags *flags) {
    t_sorted_odj *sort = (t_sorted_odj *)malloc(sizeof(t_sorted_odj));
    sort->len_of_dirs_array = sort->len_of_files_array = 0;
    mx_file_dir_sort(sort, flags);
    if (sort->len_of_files_array != 0) {
        mx_alphabet_sort(sort->files, sort->len_of_files_array);
        if (flags->switch_flags[7] == 1)
            mx_array_reverse(sort->files, sort->len_of_files_array);
    }
    if (sort->len_of_dirs_array != 0) {
        mx_alphabet_sort(sort->dirs, sort->len_of_dirs_array);
        if (flags->switch_flags[7] == 1)
            mx_array_reverse(sort->dirs, sort->len_of_dirs_array);
    }
    if (sort->len_of_files_array != 0) {
        if (flags->switch_flags[5] != 1)
            mx_output_by_size_of_wind(sort->files, sort->len_of_files_array);
        else
            mx_output_in_one_column(sort->files, sort->len_of_files_array);
    }
    for (int j = 0; j < sort->len_of_dirs_array; ++j) {
        if (flags->count_obj != 1) {
            if (j != 0 || sort->len_of_files_array != 0)
                mx_printchar('\n');
            mx_printstr(sort->dirs[j]);
            mx_printstr(":\n");
        }
        one_obj(sort->dirs[j], flags);
    }
    if (sort->files)
        mx_del_strarr(&sort->files);
    if (sort->dirs)
        mx_del_strarr(&sort->dirs);
    free(sort);
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

static void add_to_array(char **array, char *obj, int i, struct dirent *directory) {
    DIR *temp_d;
    char *full_path = mx_strnew(mx_strlen(obj) + 1 + mx_strlen(directory->d_name));
    full_path = mx_strcpy(full_path, obj);
    full_path = mx_strcat(full_path, "/");
    full_path = mx_strcat(full_path, directory->d_name);
    if ((temp_d = opendir(full_path))) {
        array[i] = malloc(mx_strlen(directory->d_name) + 1);
        array[i] = mx_strcpy(array[i], directory->d_name);
        array[i] = mx_strcat(array[i], "/");
        closedir(temp_d);
    } else {
        array[i] = malloc(mx_strlen(directory->d_name));
        array[i] = mx_strcpy(array[i], directory->d_name);
    }
    mx_strdel(&full_path);
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
