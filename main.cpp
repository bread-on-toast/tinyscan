#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "scan.h"
using namespace std;
using std::vector;

int main ( int a, char *h[] ) {
//cout <<h[1];
scan myscan;

myscan.set_geo(1000,10,50);// distance zero-camera, angle laser to camera, stepps/360°

myscan.load_file(h[1], atoi(h[2]));
myscan.write_values();

//myscan.test(); 
 return 0;
}


