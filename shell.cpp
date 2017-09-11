#include "ls.cpp"
#include "mkdir.cpp"
#include "pwd.cpp"
#include "rmdir.cpp"
#include "cd.cpp"
#include <string>
#include "bits/stdc++.h"
using namespace std;

vector <string> split(const string &text, char sep) {
    vector<string> tokens;
    size_t start = 0, end = 0;
    while ((end = text.find(sep, start)) != string::npos) {
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(text.substr(start));
    tokens.erase(remove(tokens.begin(), tokens.end(), ""), tokens.end());
    return tokens;
}

int main()
{ 
    string curDir = pwd();
    while(1)
    {
        string args;
        cout << "myshell: " << curDir << "$ ";
        getline(cin, args);
        vector < string > commands = split(args, ' ');
        if(commands[0] == "pwd")
        {
            curDir = pwd();
            cout << curDir << endl;
        }
        else if(commands[0] == "ls")
        {
            ls(&curDir[0]);
        }
        else if(commands[0] == "cd")
        {
            curDir = (string)cd(commands[1].c_str());
        }
        else if(commands[0] == "exit")
        {
            exit(0);
        }
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
        else if(commands[0] == "rmdir")
        {
        	//string temp = curDir;
        	char* dname = (char*)malloc(sizeof(char)*100);
		std::strcpy(dname,curDir.c_str());
        	char* inDir = (char*)malloc(sizeof(char)*100);
		std::strcpy(inDir,commands[1].c_str());
	        char* inp = (char*)malloc(sizeof(char)*100);
	        //cout << inDir << " " << dname << endl;
	        strcat(dname,"/");
	        strcat(dname,inDir);
	        strcpy(inp,dname);
		
	       // cout <<endl<< inp << endl<<dname;
	        dir_finder(dname,inp);
        }
        else
        {
        	cout << "Invalid keyword.\n";
        }
        commands.clear();
    }
}
