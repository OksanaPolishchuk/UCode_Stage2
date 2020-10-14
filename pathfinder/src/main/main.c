#include "pathfinder.h"

int main(int argc, char **argv) {
    if (argc == 2) {
        check_all_errors(argv[1]);
        mx_printstr("jopa");
    }
    else {
        mx_printerr("usage: ./pathfinder [filename]\n");
    }
}
