#include<iostream>
#include<dirent.h>
#include <sys/stat.h>

using namespace std;

size_t getFilesize(const char* filename)
{
    struct stat st;
    if(stat(filename, &st) != 0)
    {
        return 0;
    }
    return st.st_size;
}

void l(const char*  curDir)
{
    DIR *pointerToDirectory;                                            // A type that describes a directory stream.
    struct dirent *directoryStream;
    pointerToDirectory = opendir(curDir);
    if( pointerToDirectory != NULL)
    {
        while( directoryStream = readdir(pointerToDirectory))
        {
            cout<<directoryStream->d_name;
               size_t s =  getFilesize(directoryStream->d_name);
               if(s!=0)
               cout<<"\t"<<s/1024<<" KB";                             
            cout<<"\n";
        }
        closedir(pointerToDirectory);
    }
    else
    {
        cout<<"Couldn't open the directory";
    }
}
