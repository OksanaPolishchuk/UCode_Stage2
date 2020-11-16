#include "uls.h"

static void year(struct stat sb, t_lattrib **lattrib, int i);
static void hours_minutes(struct stat sb, t_lattrib **lattrib, int i);

void mx_time_modif(struct stat sb, t_lattrib **lattrib, int i) {
    time_t seconds;
    seconds = time(NULL);
    lattrib[i]->time = mx_strnew(12);

    lattrib[i]->time[0] = ctime(&sb.st_mtime)[4];
    lattrib[i]->time[1] = ctime(&sb.st_mtime)[5];
    lattrib[i]->time[2] = ctime(&sb.st_mtime)[6];
    lattrib[i]->time[3] = ctime(&sb.st_mtime)[7];
    lattrib[i]->time[4] = ctime(&sb.st_mtime)[8];
    lattrib[i]->time[5] = ctime(&sb.st_mtime)[9];
    lattrib[i]->time[6] = ctime(&sb.st_mtime)[10];

    if (sb.st_mtime < (seconds - 15552000)) // modif made more than 6 months -/+
        year(sb, lattrib, i);
    if (sb.st_mtime > (seconds - 15552000)) // modif made within half a year -/+
        hours_minutes(sb, lattrib, i);
}

static void year(struct stat sb, t_lattrib **lattrib, int i) {
    lattrib[i]->time[7] = ctime(&sb.st_mtime)[19];
    lattrib[i]->time[8] = ctime(&sb.st_mtime)[20];
    lattrib[i]->time[9] = ctime(&sb.st_mtime)[21];
    lattrib[i]->time[10] = ctime(&sb.st_mtime)[22];
    lattrib[i]->time[11] = ctime(&sb.st_mtime)[23];
}

static void hours_minutes(struct stat sb, t_lattrib **lattrib, int i) {
    lattrib[i]->time[7] = ctime(&sb.st_mtime)[11];
    lattrib[i]->time[8] = ctime(&sb.st_mtime)[12];
    lattrib[i]->time[9] = ctime(&sb.st_mtime)[13];
    lattrib[i]->time[10] = ctime(&sb.st_mtime)[14];
    lattrib[i]->time[11] = ctime(&sb.st_mtime)[15];
}
