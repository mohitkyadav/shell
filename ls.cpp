#include<iostream>
#include<dirent.h>

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
