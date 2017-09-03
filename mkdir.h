#include <stdio.h>
#include <iostream>
#include <sys/stat.h>
#include <string.h>
using namespace std;

int mkdir2(int argc,char* argv[3]) {
        if((mkdir(argv[1],00777))==-1) {
               cout << "Error in Creating Directory.\n";   
        }
        else
        		cout << argv[1] << " was created successfully.\n";
}
