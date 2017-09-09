#include<iostream>
#include <sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include "mk_dir.cpp" 

using namespace std;

int main(){
	char flag[100];
	char path[100];
	char dirname[100];
	scanf("%s", path);
	scanf("%s", dirname);
	scanf("%s", flag);
	printf("---------------Processing-----------------\n");
	mkdir(path,dirname,flag);
}
