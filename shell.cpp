#include "mkdir.cpp"
#include "ls.cpp"
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
        cout << "myshell$: " << curDir << ":";
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
                cin.clear();
                fflush(stdin);
                mk_dir(&curDir[0], &newFolder[0], &flag[0]);     
            }
            else
            {
                newFolder = commands[1];
                flag = "-p";
                cin.clear();
                fflush(stdin);
                mk_dir(&curDir[0], &newFolder[0], &flag[0]);
            }
        }
        else if(commands[0] == "rmdir")
        {
        	string temp = curDir;
        	char* inDir = &temp[0];
        	char* dname = &commands[1][0];
	        char* inp = (char*)malloc(sizeof(char)*100);
	        //cout << inDir << " " << dname << endl;
	        strcat(inDir,"/");
	        strcat(inDir,dname);
	        strcpy(inp,inDir);
	        //cout << inDir << endl;
	        dir_finder(inDir,inp);
        }
        else
        {
        	cout << "Invalid keyword.\n";
        }
    }
    while(1)
    {
       
    
        //string newDir = curDir + "/" + "hi";
        //string newDir = "hi";
        //string flag = "-p";
        //cout << "myshell$: " << curDir << ":";
        //string args;
        //cin >> args;
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
        /*
        string args;
        args = "hi/hi";
        char* path = &args[0];
        strcpy(inp,path);
        dir_finder(path, inp);
        */
        break;
    }
}