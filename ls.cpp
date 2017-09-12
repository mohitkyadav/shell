#include<iostream>
#include<dirent.h>
#include <sys/stat.h>
#include <iomanip>

using namespace std;

string getExt(string pathName)
{
    string ext;
    // Finds the last persiod character of the string
    if (pathName.find('.') != std::string::npos) {
        int period = pathName.find_last_of(".");
        ext = pathName.substr(period + 1);
        return ext;
    }
    return ext ;
}

size_t getFilesize(const char* filename) {
    struct stat st;
    if(stat(filename, &st) != 0) {
        return 0;
    }
    return st.st_size;
}

void l(const char*  curDir)
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
            //Gets size of directory or file in bytes/
                size_t s =  getFilesize(directoryStream->d_name);
            //Gets extension of file.
                string ex = getExt(directoryStream->d_name);
                if(s!=0) {
                // Print the name of directories in current directory.
                    cout<<setw(40)<<left<<directoryStream->d_name;
                    cout<<s<<"bytes";
                    cout<<setw(20)<<right<<ex;
                }
                else {
                   cout<<setw(60)<<left<<directoryStream->d_name;
                   cout<<setw(20)<<left<<ex;
               }
               cout << "\n";
           }


           closedir(pointerToDirectory);
       }
       else
       {
        cout<<"Couldn't open the directory";
    }

}


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
       if( pointerToDirectory != NULL)
       {
        while( directoryStream = readdir(pointerToDirectory))
        {
            cout<<directoryStream->d_name;
            cout<<"\n";
        }
        closedir(pointerToDirectory);
    }
    else
    {
        cout<<"Couldn't open the directory";
    }
}
