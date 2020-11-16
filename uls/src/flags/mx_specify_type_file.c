#include "uls.h"

/*
 * Speciying type of files for -l flag
 */
void mx_specify_type_file(struct stat sb, t_lattrib **lattrib, int i) {
        switch (sb.st_mode & S_IFMT) {
            case S_IFBLK:  lattrib[i]->ftype = ('b'); break; /*block device*/
            case S_IFCHR:  lattrib[i]->ftype = ('c'); break; /*character device*/
            case S_IFDIR:  lattrib[i]->ftype = ('d'); break; /*directory*/
            case S_IFIFO:  lattrib[i]->ftype = ('p'); break; /*named pipe (fifo)*/
            case S_IFLNK:  lattrib[i]->ftype = ('l'); break; /*symlink*/
            case S_IFREG:  lattrib[i]->ftype = ('-'); break; /*regular file*/
            case S_IFSOCK: lattrib[i]->ftype = ('s'); break; /*socket*/
            default:       lattrib[i]->ftype = ('?'); break; /**/
        }
}
