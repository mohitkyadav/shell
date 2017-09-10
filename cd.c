#include <cstdio>
#include <unistd.h>
#ifndef CD_H
#define CD_H
 char* cd(const char *dir){
    char *path = NULL;
    int rc = chdir(dir);//Changes Directory
    if (rc < 0) {
        perror("cd");// Shows Error
    }
    path=get_current_dir_name();
    return path;//returns changed Directory path
 }
#endif


