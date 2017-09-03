#include<dirent.h>
#include<iostream>

using namespace std;

void ls() {

//DIR is a type that describes a directory stream.
//We will create a pointer of DIR type to store the refrence of directory.
DIR *pointerToDirectory;

/* structure dirent includes the following members:
   ino_t  d_ino       file serial number                                                                        
   char   d_name[]    name of entry                  */
struct dirent *directoryStream;  
  
/* Open the current directory.
    / is the root of the current drive;
   ./ is the current directory;
   ../ is the parent of the current directory.      */
pointerToDirectory = opendir("./");                                 

//To check that directory is not null.
if( pointerToDirectory != NULL) {
    //To read the files of directory one by one and printing their names.
    while( directoryStream = readdir(pointerToDirectory)) {
        cout<<directoryStream->d_name;                              // Print the name of directories in current directory.
        cout<<"\n";
    }
    //Closing the directory. 
    closedir(pointerToDirectory);
}
//If directory is null we will print an error message.
else {
    cout<<"Couldn't open the directory";
}
}
