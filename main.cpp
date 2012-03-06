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

myscan.set_geo(8,78,49);// distance zero-camera, winkel laser zu bildebene , stepps/360°

myscan.load_file(h[1], atoi(h[2]));
myscan.write_values();

//myscan.test(); 
 return 0;
}


