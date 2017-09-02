#include<iostream>
#include<dirent.h>

using namespace std;
void ls() {

// A type that describes a directory stream.
DIR *pointerToDirectory;
/* structure dirent includes the following members:
struct dirent *directoryStream;                                     
ino_t  d_ino       file serial number                                                                        
char   d_name[]    name of entry                  */

pointerToDirectory = opendir("./");                                 //Open the current directory.
                                                                    /* / is the root of the current drive;
                                                                        ./ is the current directory;
                                                                       ../ is the parent of the current directory. */

if( pointerToDirectory != NULL) {
    while( directoryStream = readdir(pointerToDirectory)) {
        cout<<directoryStream->d_name;                              // Print the name of directories in current directory.
        cout<<"\n";
    }
    closedir(pointerToDirectory);
}
else {
    cout<<"Couldn't open the directory";
}

}
