#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "scan.h"
using namespace std;
using std::vector;

int main ( int bla, char *h[] ) {
//cout <<h[1];
scan myscan;

myscan.set_cal(10000,1000,330,400);//int kx, int ky, int www, int hhh
myscan.load_file(h[1]);
//myscan.read_file();
//myscan.test();
myscan.write_values(h[2]);
  return 0;
}


