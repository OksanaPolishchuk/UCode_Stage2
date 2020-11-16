#include "uls.h"

static void illegal_opt_print(char fl) {
    char *not_fl = malloc(2);
    not_fl[0] = fl;
    not_fl[1] = '\0';

    mx_printerr(ILLEGAL_OPT);
    mx_printerr(not_fl);
    mx_printerr("\n");
    mx_printerr(INVALID_USAGE);
    mx_printerr("\n");
    exit(1);
}

void mx_error_illegal_option(t_flags *flags) {
    char our_flags[10] = "alihp1Ars";

    for (int i = 1; i < flags->argc; i++)
        if ((flags->argv[i][0] == '-' && flags->argv[i][1] != '-') ||
            (flags->argv[i][1] == '-' && flags->argv[i][2]))
            for (int j = 1; flags->argv[i][j]; j++)
                if (!mx_strchr(our_flags, flags->argv[i][j]))
                    illegal_opt_print(flags->argv[i][j]);
}
