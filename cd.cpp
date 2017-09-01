#include <string>
#include <unistd.h>
#include <cstdio>
#include "cd.h"


int HD::cd(const char *dir)
{
    int rc = chdir(dir);
    if (rc < 0) {
        perror("cd");
    }
    return 0;
}
