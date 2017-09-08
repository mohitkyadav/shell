
#include <sys/stat.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	
	if(strcmp(argv[1],"-v")==0){
		const int n = mkdir(argv[2] ,0777);
		if(n==-1){
			printf("Error creating directory!\n");
    			exit(1);
		}	
		else
			printf("Created directory '%s' \n",argv[2]);
	}
	
	else if(strcmp(argv[1],"-p")==0){
	
    		const int n = mkdir(argv[2] ,0777);
    			
		if (n==-1){
			printf("Error creating directory!\n");
    			exit(1);
		}	
	}
	else if(strcmp(argv[1],"-m")==0){
		const int n = mkdir(argv[3],0777);
		printf("%s",argv[2]);
		chmod(argv[3],atoi(argv[2]));
		if(n==-1){
			printf("Error creating directory!\n");
    			exit(1);
		}
	}	
	else{
		const int n= mkdir(argv[1] ,0777);	
		if (n==-1){
			printf("Error creating directory!\n");
    			exit(1);
		}
	}	
	
	return 0;
}
