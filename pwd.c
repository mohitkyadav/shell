#include<iostream>
#include<unistd.h>
using namespace std;

void pwd(){
	char cwd[1024];
	getcwd(cwd,sizeof(cwd));
	cout<<cwd<<endl;
}
