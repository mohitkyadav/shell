#include<iostream>
#include <sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

int mk_dir(string path, string dirname){
	path += "/" + dirname + "/";
	mkdir(&path[0], 0777);
	return 0;
}

int mk_dirv(string path, string dirname){
	path += "/" + dirname + "/";
	mkdir(&path[0], 0777);
	cout << dirname << " created.\n";
	return 0;
}

int mk_dirp(string path, string dirname){
	path += "/" + dirname + "/";
	mkdir(&path[0], 0777);
	return 0;
}
