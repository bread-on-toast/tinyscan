#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "scan.h"
#include "cam.h"

using namespace std;

using std::vector;

int main ( int a, char *h[] ) {


//cout <<h[1];
	scan myscan;
	myscan.set_geo(8,78,atoi(h[1]));// distance zero-camera, winkel laser zu bildebene , stepps/360°
	myscan.set_zero(); //hier müssen noch die anweisungen an adruino eingebaut werden damit er die kalibration durchführen kann
	myscan.set_pv(); 
	myscan.set_pvz(); 

	for(int i=0; i<atoi(h[1]);i++){
		myscan.load_img(i);
		myscan.write_values();
		}
	return 0;
	}


