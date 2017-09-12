#include <string>
#include "bits/stdc++.h"
#include <pwd.h>
#include <grp.h>
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
	register struct passwd *pw;
	register uid_t uid;
	uid = geteuid ();
	pw = getpwuid (uid);
	string root_name = pw->pw_name;
    string curDir = pwd();
    while(1)
    {
        string args;
        cout << root_name << ": " << curDir << "$ ";
        getline(cin, args);
        vector < string > commands = split(args, ' ');
        if(commands[0] == "pwd")
        {
            curDir = pwd();
            cout << curDir << endl;
        }
        else if(commands[0] == "ls")
        {
        	if( commands.size() > 1)
        	{
            	l(&curDir[0]);
        	}
        	else
        	{
            	ls(&curDir[0]);
        	}
        }
        else if(commands[0] == "cd")
        {
        	if(commands.size() == 1)
        	{
        		curDir = "/home/";
        	}
        	else
        	{
            	curDir = (string)cd(commands[1].c_str());
        	}
        }
        else if(commands[0] == "exit")
        {
            exit(0);
        }
        // call mkdir
        else if(commands[0] == "mkdir")
        {
            string newFolder;
            string flag;
            if(commands.size() > 2)
            {
                newFolder = commands[2];
                flag = commands[1];
                if(flag == "-p")
                {
                	mk_dirp(newFolder);     
                }
                else if(flag == "-v")
                {
                	mk_dirv(curDir, newFolder);     
                }
            }
            else
            {
                newFolder = commands[1];
                mk_dir(curDir, newFolder);
            }
        }
        // call rm -rf
        else if(commands[0] == "rm" && commands[1] == "-rf")
        {
        	char* dname = (char*)malloc(sizeof(char)*100);
			std::strcpy(dname,curDir.c_str());
        	char* inDir = (char*)malloc(sizeof(char)*100);
			std::strcpy(inDir,commands[2].c_str());
	        char* inp = (char*)malloc(sizeof(char)*100);
	        strcat(dname,"/");
	        strcat(dname,inDir);
	        strcpy(inp,dname);
	        dir_finder(dname,inp);
        }
	// call rmdir
        else if(commands[0] == "rmdir")
        {
        	char* dname = (char*)malloc(sizeof(char)*100);
		std::strcpy(dname,curDir.c_str());
        	char* inDir = (char*)malloc(sizeof(char)*100);
		std::strcpy(inDir,commands[1].c_str());
	        strcat(dname,"/");
	        strcat(dname,inDir);
	        rmdir_find(dname);
        }

	    
	else
        {
        	cout << "Invalid keyword.\n";
        }
        commands.clear();
    }
}
