#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>

void check_arg2_is_file(char *str);
void check_arg2_is_exist(char *file);
void check_arg2_is_empty(char *file);
void check_all_errors(char *file);
void check_line_is_not_valid(char *file);
void line_number_is_not_valid(char *file);



#endif
