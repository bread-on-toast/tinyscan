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
#include <unistd.h>
#include<limits>
#include <cmath> 
#include "CImg.h"
#include "cam.h"
#include "scan.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>


using namespace std;
using namespace cimg_library;
using std::vector;


std::vector <string>  cont;


//int dev=1;
float ww=0.000000;
float hh=0.000000;
float pv=0.000;
float pvz=0.000;


bool end=false;
int a=0;

float c=0.000; //tan(angle laser camera)

std::vector <float> x,y,z;
//std::vector <float> z;
//std::vector <float> x;
float deg;


void scan::load_file(char* name, int num){
	cam mycam;
	mycam.set_dev(1);
	mycam.grep_img(1);
	
	std::vector <int> xx=mycam.get_x();
	std::vector <int> yy=mycam.get_y();


	while(yy.size()>0){
		float r=sqrt((a/(pv/(ww-xx[0])-c))*(a/(pv/(ww-xx[0])-c))*(1+c*c) );
		x.push_back(r*cos(deg*num*M_PI/180)); 
		y.push_back(r*sin(deg*num*M_PI/180));
		z.push_back(((a/(pv/(ww-xx[0])-c))*c+a)*(hh-yy[0])/pvz);
		xx.erase(xx.begin());
		yy.erase(yy.begin());
		}
}





void scan::set_zero(int d){
	cam mycam;
	mycam.set_dev(d);
	mycam.grep_img(1);
	
	std::vector <int> xc=mycam.get_x();
	std::vector <int> yc=mycam.get_y();

	int width = mycam.get_w();
	int height = mycam.get_h();

	int www=0;
	int hhh=0;
	int min=width;
	int max=0;		
	while (xc.size()>0){
		www=xc[0];
		if(www<min){min=www;}
		if(www>max){max=www;}
		xc.erase(xc.begin());
		}
	ww=(min+max)/2;
	min=height;
	max=0;		
	while (yc.size()>0){
		www=yc[0];
		if(www<min){min=www;}
		if(www>max){max=www;}
		yc.erase(yc.begin());
		}
	hh=(min+max)/2;
	mycam.flush();
	}



void scan::set_pv(int d){
	cam mycam;
	mycam.set_dev(d);
	mycam.grep_img(1);
	
	std::vector <int> xc=mycam.get_x();
	std::vector <int> yc=mycam.get_y();
	int www=0;
	int hhh=0;

	int min=mycam.get_w();
	int max=0;		
	while (xc.size()>0){
		www=xc[0];
		if(www<min){min=www;}
		if(www>max){max=www;}
		xc.erase(xc.begin());	
		}
	www=(min+max)/2;
	pv=(www-ww)*(a+1)*c;
	mycam.flush();
	}



void scan::set_pvz(int d){
	cam mycam;
	mycam.set_dev(d);
	mycam.grep_img(1);
	
	std::vector <int> xcc=mycam.get_x();
	std::vector <int> ycc=mycam.get_y();
	int www=0;
	int hhh=0;

	int min=mycam.get_h();
	int max=0;		
	while (ycc.size()>0){
		www=ycc[0];
		if(www<min){min=www;}
		if(www>max){max=www;}
		ycc.erase(ycc.begin());	
		}
	www=(min+max)/2;
	pvz=a*(www-ww);
	mycam.flush();
	}



void scan::write_values(){
	int i=0;
	remove("cloud.obj");
	ofstream myfile;
  	myfile.open ("cloud.obj", ios::app);
  			
	myfile<<"# Created by tinyscan \n\n";
  			
	while(x.size()>0){
	
			myfile<<"v "<<x[0]<<" "<<y[0]<<" "<< z[0] <<" 1.0\n";
			x.erase(x.begin());
			y.erase(y.begin());
			z.erase(z.begin());
		}

	myfile.close();
	x.clear();
	y.clear();
	z.clear();
	}


void scan::set_geo(int aa, int b,int stepps, int d){//aa = distance zero camera, b = angle between laser and cam
	//dev=d;

	a=aa;
	c=tan((b)*M_PI/180);
	deg=360.0000/stepps;
	send("Z1");
	set_zero(d); 
	send("Z0");
	send("X1");
	set_pv(d);
	send("X0"); 
	send("Y1");
	set_pvz(d); 

	send("Y0");
	cout <<"pv="<<pv<<" pvz="<<pvz<<" ww="<<ww<<"hh="<<hh<<endl;
	}

void scan::send(const char* mes){
		ofstream myfile;
  		myfile.open ("/dev/ttyUSB0", ios::app);
  		myfile << mes;
  		myfile.close();
		sleep(0.5);
	}

//void scan::set_dev(int d){in set_geo...
//		dev=d;
//	}


