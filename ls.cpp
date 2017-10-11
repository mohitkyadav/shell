#include<iostream>
#include<dirent.h>
#include <sys/stat.h>
#include <iomanip>
#include <sys/types.h>
#include<time.h>


using namespace std;

//Returns extension of file.
string getExt(string pathName)
{
    string ext;
    // Finds the last period character of the string
    if (pathName.find('.') != std::string::npos)
    {
        int period = pathName.find_last_of(".");
        ext = pathName.substr(period + 1);
        return ext;
    }
    return ext ;
}

//Returns size of file.
size_t getFilesize(const char* filename)
{
    //Structure to store file attributes
    struct stat st;
    //Return 0 is successfully executed.
    if(stat(filename, &st) != 0)
    {
        return 0;
    }
    return st.st_size;
}

//Prints rwx permissions of file.
void getFilePermission(const char* filename)
{
    struct stat fileStat;
    if(stat(filename, &fileStat) != 0)
    {
        return ;
    }
    //Check for directory. If directory then prints d else -.
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    //Check for read access to user. If permitted then prints r else -.
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    //Check for write access to user. If permitted then prints w else -.
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    //Check for executable access to user. If permitted then prints x else -.
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    //Check for read access to group. If permitted then prints r else -.
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    //Check for write access to group. If permitted then prints w else -.
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    //Check for executable access to group. If permitted then prints x else -.
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    //Check for read access to other users. If permitted then prints r else -.
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    //Check for write access to other users. If permitted then prints w else -.
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    //Check for executable access to other users. If permitted then prints x else -.
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    cout<<"\t";
}

string getLastAccessedTime(const char* pathname)
{

    //Structure to store time related details of file or directory.
    struct tm* tmModifiedTime;
    struct stat attrib; // create a file attribute structure
    //stat function use for reading file details and storing in structure.
    stat(pathname, &attrib);
    //gmtime used for reading time details and storing in structure.
    tmModifiedTime = gmtime(&(attrib.st_mtime));
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
            {
                continue;
            }
            getFilePermission(directoryStream->d_name);

            //getLastAccessedTime(directoryStream->d_name);

            //Gets size of directory or file in bytes/
            size_t s =  getFilesize(directoryStream->d_name);
            //Gets extension of file.
            string ex = getExt(directoryStream->d_name);
            if(s!=0)
            {
            // Print the name of directories in current directory.


                cout<<setw(40)<<left<<directoryStream->d_name;
                cout<<setw(15)<<right<<s;
                cout<<setw(10)<<right<<ex;
                cout<<setw(30)<<right<<getLastAccessedTime(directoryStream->d_name);
            }
            else
            {

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
        cout<<"\n";
    }
    else
    {
        cout<<"Couldn't open the directory";
    }
}
