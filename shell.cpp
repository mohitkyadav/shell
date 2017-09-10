#include "mkdir.cpp"
#include "ls.cpp"
#include "pwd.cpp"

#include "cd.cpp"
#include <string>

using namespace std;

int main()
{
    while(1)
    {
        string curDir = pwd();
        //cout << curDir;
        string newDir = curDir + "/" + "hi";
        string flag = "-p";
        cout << "myshell$: " << pwd();
        ls(curDir.c_str());
        char* path = cd(newDir.c_str());
        cout << path;
        ls(path);
        break;
    }
}
