#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>

using namespace std;

int mkdir(int argc,char **argv) {

	char *str, *s;
	struct stat statBuf;
	
	if (argc != 2) {
		cout << "usage:" << basename (argv[0]) << "<path>\n";
		exit (1);
	}
    
    s = argv[1];
    
    while ((str = strtok (s, "/")) != NULL) {
    	if (str != s) {
    		str[-1] = '/';
    	}
    	if (stat (argv[1], &statBuf) == -1) {
    		mkdir (argv[1], 0777);
        } 
        else {
        	if (! S_ISDIR (statBuf.st_mode)) {
	        	cout << "couldn't create directory %s\n";
	        	exit (1);
	        }
	    }
        s = NULL;
	}
	
	return 0; 
}
