#include "mkdir.cpp"
#include "ls.cpp"
#include "pwd.cpp"
#include "rmdir.cpp"
#include "cd.cpp"
#include <string>

using namespace std;

int main()
{
    while(1)
    {
        string curDir = pwd();
        //string newDir = curDir + "/" + "hi";
        string newDir = "hi";
        string flag = "-p";
        cout << "myshell$: " << curDir << ":";
        /*
        string args;
        args = "hi";

        //cin >> args;
        //ls(curDir.c_str());
        //char* path = cd(args.c_str());
        //cout << path;
        char* path = &args[0];
         char *test = &curDir[0];
         char *test2 = &newDir[0];
         char *test3= &flag[0];
         strcpy(inp,path);
         cout << path << inp;
         dir_finder(path, inp);
        //mkdir(test, test2, NULL);
        */
        string args;
        args = "hi/hi";
        char* path = &args[0];
        strcpy(inp,path);
        dir_finder(path, inp);
        break;
    }
}
