#include <iostream>
#include <string.h>
#include <sys/types.h>  // used for ino_t
#include <dirent.h>     // used for structure : struct dirent
#include <cerrno>		// For finding error in opening directory
#include<stdlib.h>		// exit()
#include<cstdio>		// perror() and remove()
#include<unistd.h>		// rmdir()


using namespace std;

int rmdir_finder(char*);
int rmdir_finder(char* dname) // Recursive function for finding file/directory and deleteing them
{

    DIR* d;
    d = opendir(dname);
    struct dirent *dir;          /* Includes :-     1) ino_t d_ino - Stores file serial number
    			        	            2) char d_name[] - Stores name of directory  */ 													
     if (d!=NULL)		// Returns NULL when given address is not a directory
    {
        while ((dir = readdir(d)) != NULL)   // On successfull completion, returns pointer to the object "dir" of type "struct dirent"
        {
            if (strcmp(dir->d_name, ".")==0 || strcmp(dir->d_name, "..")==0 )
                continue;
            cout<<"Error : Cannot delete a non-empty directory\n";
	        return 0;
        }
    }
    else
    {
        perror("Error : ");
	return 0;
    }
}

