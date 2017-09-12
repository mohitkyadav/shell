#include<iostream>
#include<dirent.h>
#include <sys/stat.h>

using namespace std;
void ls(const char*  curDir)
{
    // A type that describes a directory stream.
    DIR *pointerToDirectory;
    /*
        structure dirent includes the following members:
        ino_t  d_ino       file serial number
        char   d_name[]    name of entry
    */
    struct dirent *directoryStream;

    //Open the current directory.
    pointerToDirectory = opendir(curDir);
    /*
        / is the root of the current drive;
        ./ is the current directory;
        ../ is the parent of the current directory.
    */

    if( pointerToDirectory != NULL)
    {
        while( directoryStream = readdir(pointerToDirectory))
        {
            // Print the name of directories in current directory.
            cout << directoryStream->d_name;
            cout << "  ";
        }
        cout << "\n";

        closedir(pointerToDirectory);
    }
    else
    {
        cout<<"Couldn't open the directory";
    }

}
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
