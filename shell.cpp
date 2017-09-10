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
        string newDir = curDir + "/" + "hi";
        string flag = "-p";
        cout << "myshell$: " << curDir << "\n";
        ls(curDir.c_str());
        char* path = cd(newDir.c_str());
        //cout << path;
        dir_finder(path, path);
        break;
    }
}
