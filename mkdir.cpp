#include<iostream>
#include <sys/stat.h>
#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include<string>

using namespace std;

/*
	param: @path: path where the directory is to be created
	param: @dirname: name of the directory that is to be created
*/
int mk_dir(string path, string dirname)
{
	path += "/" + dirname + "/";
	int rc = mkdir(&path[0], 0777);
	if (rc < 0)
    {
        perror("mkdir");// Shows Error
    }
	return 0;
}

int mk_dirv(string path, string dirname)
{
	path += "/" + dirname + "/";
	int rc = mkdir(&path[0], 0777);
	if (rc < 0)
    {
        perror("mkdir");// Shows Error
    }
    else
    {
        cout << dirname << " created.\n";
    }
	return 0;
}

int mk_dirp(string path)
{
	int rc = mkdir(&path[0], 0777);
	if (rc < 0)
    {
        perror("mkdir");// Shows Error
    }
	return 0;
}
