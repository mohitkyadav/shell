#include <iostream>
#include <cstring>
#include <string>
#include <pwd.h>
#include <grp.h>
#include <signal.h>
#include <algorithm>
#include <vector>

#include "rmdir.cpp"
#include "ls.cpp"
#include "mkdir.cpp"
#include "pwd.cpp"
#include "rm.cpp"
#include "cd.cpp"

using namespace std;

// splits the line into a vector of string
vector <string> split(const string &text, char sep)
{
    vector<string> commands;
    size_t start = 0, end = 0;
    while ((end = text.find(sep, start)) != string::npos)
    {
        commands.push_back(text.substr(start, end - start));
        start = end + 1;
    }
    commands.push_back(text.substr(start));
    commands.erase(remove(commands.begin(), commands.end(), ""), commands.end());
    return commands;
}

int main()
{
    struct passwd *pw;
    uid_t uid;
    uid = geteuid ();
    pw = getpwuid (uid);
    string user_name = pw->pw_name;
    string curDir = pwd();
    while(1)
    {
        string args;
        cout << user_name << ": " << curDir << "$ ";
        getline(cin, args);
        vector <string> commands = split(args, ' ');
        // Call for pwd
        if(commands[0] == "pwd")
        {
            curDir = pwd();
            cout << curDir << endl;
        }
        // Call for ls
        else if(commands[0] == "ls")
        {
            if( commands.size() > 1)
            {
                if(commands[1] == "-l" && commands.size() <= 2)
                    l(&curDir[0]);
                else
                {
                    cout << "Flag does not exist" << "\n";
                    cout << "Try: ls -l" << "\n";

                }
            }
            else
            {
                ls(&curDir[0]);
            }
        }
        // Call for cd
        else if(commands[0] == "cd")
        {
            if(commands.size() == 1)
            {
                curDir = "/home/"+user_name;
                curDir = (string)cd(curDir.c_str());
            }
            else
            {
                curDir = (string)cd(commands[1].c_str());
            }
        }
        // Call for exit
        else if(commands[0] == "exit")
        {
            kill(getppid(), SIGKILL);
        }
        // call mkdir
        else if(commands[0] == "mkdir")
        {
            string newFolder;
            string flag;
            if(commands.size() >= 2)
            {
                // newFolder = commands[2];
                flag = commands[1];
                if(flag == "-v")
                {
                    for(int i=2;i<commands.size();i++)
                    {
                        newFolder=commands[i];
                        mk_dirv(newFolder, newFolder);
                    }
                }
                else if(flag.at(0)=='-')
                {
                    cout<<"Invalid Command\n";
                }
                else
                {
                    //cout << "Flag invalid\n";
                    for(int i=1;i<commands.size();i++)
                    {
                        newFolder=commands[i];
                        mk_dir(newFolder);
                    }

                }
            }
            /*
            else
            {
                newFolder = commands[1];
                mk_dir(newFolder);
            }
            */
        }
        // call rm -rf
        else if(commands[0] == "rm" && commands[1] == "-rf")
        {

            for(int i=2;i<commands.size();i++)
            {
                char* dname = (char*)malloc(sizeof(char)*100);
                strcpy(dname,curDir.c_str());
                char* inDir = (char*)malloc(sizeof(char)*100);
                strcpy(inDir,commands[i].c_str());
                char* inp = (char*)malloc(sizeof(char)*100);
                strcat(dname,"/");
                strcat(dname,inDir);
                strcpy(inp,dname);
                dir_finder(dname,inp);
            }
        }
        // call rmdir
        else if(commands[0] == "rmdir")
        {

            for(int i=1;i<commands.size();i++)
            {
                char* dname = (char*)malloc(sizeof(char)*100);
                strcpy(dname,curDir.c_str());
                char* inDir = (char*)malloc(sizeof(char)*100);
                strcpy(inDir,commands[i].c_str());
                strcat(dname,"/");
                strcat(dname,inDir);
                rmdir_find(dname);
            }
        }
        else
        {
            cout << args << " : Invalid command.\n";
        }
        commands.clear();
    }
}
