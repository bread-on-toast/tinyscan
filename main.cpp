#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "scan.h"
#include <curses.h>

using namespace std;
using std::vector;

int main ( int a, char *h[] ) {

scan myscan;

int steps=360;
/*
string input;
cout << "Number of steps?\n";
cin >>input;
int steps=atoi(input);

cout << "\nCamera Device?(/dev/video[x])\n"
cin >>input;
int dev=atoi(input);

cout << "\nDistance Camera-Object?\n"
cin >>input;
int dist=atoi(input);


cout << "\nAngle Laser-Kamera=\n";
cin >>input;
int ang=atoi(input);
*/

myscan.send("X0Y0Z0L0");
myscan.set_geo(8,60,steps,1);// distance zero-camera, winkel laser zu bildebene , stepps/360°, cam-dev
myscan.send("L1");
cout<<"start scanning\n"<<endl;
string bla;cin>>bla;
for(int i=0 ; i<steps;i++){


	myscan.get_img(1);
	myscan.load_file("/tmp/tinyscan.png", i);	cout <<i+1;
}

myscan.send("X0Y0Z0L0");
myscan.write_values();

//myscan.test(); 
 return 0;
}


