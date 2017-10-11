#include<iostream>
#include<dirent.h>
#include <sys/stat.h>
#include <iomanip>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<time.h>


using namespace std;

string getExt(string pathName)
{
    string ext;
    // Finds the last persiod character of the string
    if (pathName.find('.') != std::string::npos) 
    {
        int period = pathName.find_last_of(".");
        ext = pathName.substr(period + 1);
        return ext;
    }
    return ext ;
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

void getFilePermission(const char* filename) 
{
    struct stat fileStat;
    if(stat(filename, &fileStat) != 0) 
    {
        return ;
    }
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    cout<<"\t";
}

string getLastAccessedTime(const char* pathname) 
{

    struct tm* tmModifiedTime;
    struct stat attrib; // create a file attribute structure
    stat("Filename.Ext", &attrib);
    tmModifiedTime = gmtime(&(attrib.st_mtime));
    //cout<<"\t"<<asctime(tmModifiedTime);
    string t = asctime(tmModifiedTime);
    t = t.substr(0,t.length()-6);
    return t;
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
            if (strcmp(directoryStream->d_name, ".")==0 || strcmp(directoryStream->d_name, "..")==0 )
            continue;
            getFilePermission(directoryStream->d_name);

            //getLastAccessedTime(directoryStream->d_name);

        //Gets size of directory or file in bytes/
            size_t s =  getFilesize(directoryStream->d_name);
        //Gets extension of file.
            string ex = getExt(directoryStream->d_name);
            if(s!=0) {
            // Print the name of directories in current directory.


                cout<<setw(40)<<left<<directoryStream->d_name;
                cout<<setw(15)<<right<<s;
                cout<<setw(10)<<right<<ex;
                cout<<setw(30)<<right<<getLastAccessedTime(directoryStream->d_name);
            }
            else {

               cout<<setw(55)<<left<<directoryStream->d_name;
               cout<<setw(10)<<right<<ex;
               cout<<setw(30)<<right<<getLastAccessedTime(directoryStream->d_name);
           }
           cout<<"\n";

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
            if (strcmp(directoryStream->d_name, ".")==0 || strcmp(directoryStream->d_name, "..")==0 )
                continue;
            cout<<directoryStream->d_name;
            cout<<"\t";
        }
        closedir(pointerToDirectory);
    }
    else
    {
        cout<<"Couldn't open the directory";
    }
}
