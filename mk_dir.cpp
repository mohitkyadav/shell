#include<iostream>
#include <sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int mkdir(char *path,char *dirname,char* flag){
	char* arg[4];
	if(flag != NULL){
		arg[1]=flag;
		strcpy(arg[2],path);
		strcat(arg[2],"/");
		strcat(arg[2],dirname);
		strcat(arg[2],"/");
		//printf("%s",arg[2]);
		if(strcmp(arg[1],"-v")==0){
			const int n = mkdir(arg[2] ,0777);
			if(n==-1){
				cout << "Error creating directory!\n";
	    			exit(1);
			}
			else
				cout << dirname << " Created.\n";
		}

		else if(strcmp(arg[1],"-p")==0){

	    		const int n = mkdir(arg[2] ,0777);

			if (n==-1){
				cout << "Error creating directory!\n";
	    			exit(1);
			}

		}


	}
	else{
		strcpy(arg[1],path);
		strcat(arg[1],dirname);
		strcat(arg[2],"/");
		const int n= mkdir(arg[1] ,0777);
		if (n==-1){
			cout << "Error creating directory!\n";
    			exit(1);
		}
	}

	return 0;
}
