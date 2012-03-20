/*
    Tinyscan - a small 3D-Scanner
    Copyright (C) 2012  Andre Sobotta

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>
#include "scan.h"
#include "cam.h"
#include <curses.h>

using namespace std;
using std::vector;

int main ( int a, char *h[] ) {
scan myscan;

int steps=360;
string q="y";
myscan.send("X0");
myscan.send("Y0");
myscan.send("Z0");
myscan.send("L0");


cout<<"start calibration\n";

myscan.set_geo(2,70,steps,1 );// distance zero-camera, winkel laser zu kamera , stepps/360°, cam-dev

cout<<"Insert Object to scan and hit return\n"<<endl;
string bla;
cin>>bla;

while(q=="y"){
myscan.send("L1");
sleep(0.1);
for(int i=0 ; i<steps;i++){
	myscan.load_file("/tmp/tinyscan.png", i);
	cout <<i+1<<"\n\n\n\n--------------------------\n\n";
	myscan.send("S");
	sleep(0.2);
}
myscan.send("X0");
myscan.send("Y0");
myscan.send("Z0");
myscan.send("L0");
myscan.write_values();
cout <<"one more scan?(y/n)\n";
cin>>q;
}

//myscan.test(); 
 return 0;
}


