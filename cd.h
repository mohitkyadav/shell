#include <cstdio>
#ifndef CD_H
#define CD_H
class HD{
 public:
 HD(){}
 char* cd(const char *dir){
    char *path = NULL;
    size_t size;
    int rc = chdir(dir);
    if (rc < 0) {
        perror("cd");
    }
    path=getcwd(path,size);
    return path;
}
};
#endif


