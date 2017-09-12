#include <cstdio>
#include <unistd.h>
#ifndef CD_H
#define CD_H
char* cd(const char *dir)
{
    char *path = NULL;
    //Changes Directory
    int rc = chdir(dir);
    if (rc < 0)
    {
        perror("cd");// Shows Error
    }
    path=get_current_dir_name();
    //returns changed Directory path
    return path;
}
#endif
