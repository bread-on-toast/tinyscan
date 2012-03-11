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
#include <vector>
#include "scan.h"
#include <curses.h>

using namespace std;
using std::vector;

int main ( int a, char *h[] ) {

scan myscan;

int steps=90;

myscan.send("X0");
myscan.send("Y0");
myscan.send("Z0");
myscan.send("L0");
myscan.set_geo(4,40,steps,1);// distance zero-camera, winkel laser zu bildebene , stepps/360°, cam-dev
myscan.send("L1");
cout<<"start scanning\n"<<endl;
string bla;cin>>bla;
for(int i=0 ; i<steps;i++){
	myscan.get_img(1);
	myscan.load_file("/tmp/tinyscan.png", i);
	cout <<i+1<<"\n\n\n\n--------------------------\n\n";
}
myscan.send("X0");
myscan.send("Y0");
myscan.send("Z0");
myscan.send("L0");
myscan.write_values();

//myscan.test(); 
 return 0;
}


