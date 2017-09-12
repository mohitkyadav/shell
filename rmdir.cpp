#include <iostream>
#include <string.h>
#include <sys/types.h>  // used for ino_t
#include <dirent.h>     // used for structure : struct dirent
#include <cerrno>		// For finding error in opening directory
#include<stdlib.h>		// exit()
#include<cstdio>		// perror() and remove()
#include<unistd.h>		// rmdir()


using namespace std;

char* a = (char*)"/";
int ret=1,i,plen,lencur,leninp;
char inp[100];
DIR* d;
int dir_finder(char*, char*);
char *strrev(char *); //Function to reverse the string given as an argument

// Recursive function for finding file/directory and deleteing them
int dir_finder(char* dname, char* inp) 
{
    //cout << dname;
    d = opendir(dname);
    struct dirent *dir; /* Includes :- 1) ino_t d_ino - stores file serial number
    								   2) char d_name[] - stores name of entry														*/
    if (d!=NULL)		// Returns NULL when given address is not a directory
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

        lencur=strlen(dname);
        leninp=strlen(inp);
        // Deleting the input directory
        if( (lencur==leninp) && (strcmp(dname, inp)==0) && (dir == NULL))
        {
            rmdir(dname);
            //cout<<"\nInputted Directory has been removed SUCCESSFULLY.. Action Completed !!!!!\n\n\n\n";
            return 0; 
        }
        // Deleting an empty subdirectory
            if(dir==NULL)
            {

                char* parent_name= (char*)malloc(sizeof(char) * 100);
                strcpy(parent_name,dname);
                parent_name=strrev(parent_name);
                parent_name = strchr(parent_name, '/');	// Returns the string after the first occurence of passed argument#2
                parent_name=strrev(parent_name);
                plen=strlen(parent_name);
                parent_name [plen-1] = '\0';
                i=rmdir(dname);
                //cout<<"The following directory is removed :: "<< dname <<endl;
                dir_finder(parent_name, inp);
         	}
	}
	// Delete the files in directory
    else if(errno == ENOTDIR)
    {
        char* parent_name = (char*)malloc(sizeof(char) * 100);
		strcpy(parent_name,dname);
	    parent_name=strrev(parent_name);
        parent_name = strchr(parent_name, '/');
        parent_name=strrev(parent_name);
        plen=strlen(parent_name);
        parent_name [plen-1] = '\0';
        ret = remove(dname);
        if(ret ==0)
        {
            //cout <<" The following File has been successfully deleted :: "<<dname<<endl;
            dir_finder(parent_name, inp);
        }
        else if(ret ==-1)
        {
            //cout<<" "<< dname <<"  :- File cannot be deleted \n";
        }
    }
    else
        perror("error");

}
// Function to reverse the passed string
char *strrev(char *str)
{
    char *p1, *p2;

    if (! str || ! *str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}
