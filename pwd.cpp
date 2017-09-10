#include<iostream>
#include<unistd.h>
#include<string>

using namespace std;

string pwd()
{
	char cwd[1024];
	//cout << getcwd(cwd,sizeof(cwd));
	return getcwd(cwd,sizeof(cwd));
}
