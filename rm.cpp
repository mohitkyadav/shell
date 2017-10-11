#include <iostream>
#include <string.h>
#include <sys/types.h>  // used for ino_t
#include <dirent.h>     // used for structure : struct dirent
#include <cerrno>       // For finding error in opening directory
#include<cstdio>        // perror() and remove()
#include<unistd.h>      // rmdir()


using namespace std;

char* a = (char*)"/";
int ret,i,plen;
DIR* d;
int dir_finder(char*, char*);

char *strrev(char *); //Function to reverse the string given as an argument

char* getpname(char *); //Function to get the parent name of a file/directory

// Recursive function for finding file/directory and deleteing them
int dir_finder(char* dname, char* inp)
{
    d = opendir(dname);
    struct dirent *dir;
    /* Includes :- 1) ino_t d_ino - stores file serial number
                   2) char d_name[] - stores name of entry                                                      */

    if (d!=NULL)        // Returns NULL when given address is not a directory
    {
        while ((dir = readdir(d)) != NULL)   // On successfull completion, returns pointer to the object "dir" of type "struct dirent"
        {
            if (strcmp(dir->d_name, ".")==0 || strcmp(dir->d_name, "..")==0 )
                continue;
            strcat(dname,a);
            strcat(dname,(dir->d_name));
            closedir(d);
            dir_finder(dname, inp);
            return 0;
        }


        // Deleting the input directory
        if((strcmp(dname, inp)==0) && (dir == NULL))
        {
            rmdir(dname);
            return 0;
        }
        // Deleting an empty subdirectory
        if(dir==NULL)
        {

            char* parent_name= (char*)malloc(sizeof(char) * 100);
            parent_name=getpname(dname);
            i=rmdir(dname);
            if(i==0)
            {
                dir_finder(parent_name, inp);
            }
            else
            {
                perror("Error: ");
            }
        }
    }
    // Delete the files in directory
    else if(errno == ENOTDIR)
    {
        char* parent_name = (char*)malloc(sizeof(char) * 100);
        parent_name=getpname(dname);
        ret = remove(dname);
        if(ret ==0)
            dir_finder(parent_name, inp);
        else
            perror("Error : ");

    }
    else
        perror("Error : ");

}
// Function to reverse the passed string
char *strrev(char *str)
{
    char *p1, *p2;

    if (! str || ! *str)
    {
        return str;
    }
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}
// Function to get the parent directory
char* getpname(char* dname)
{
    char* tmp_name = (char*)malloc(sizeof(char) * 100);
    strcpy(tmp_name,dname);
    tmp_name=strrev(tmp_name);
    tmp_name= strchr(tmp_name, '/');
    tmp_name=strrev(tmp_name);
    plen=strlen(tmp_name);
    tmp_name[plen-1] = '\0';
    return tmp_name;
}
