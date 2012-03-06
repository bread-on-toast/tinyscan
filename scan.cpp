#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<limits>
#include <cmath> 
#include "cam.h"


using namespace std;
using std::vector;
#include "scan.h"

std::vector <string>  cont;



float ww=680.000000;
float hh=270.000000;
float pv=200.000;
float pvz=200.000;


bool end=false;
//int i=0;
int a=0;

float c=0.000; //tan(angle laser camera)

std::vector <float> y;
std::vector <float> z;
std::vector <float> x;
float deg;




void scan::load_img(int num){

	std::vector <int> yy;
	std::vector <int> xx;

	cam mycam;
	mycam.grep_img(1,0,250);
	xx=mycam.get_x();
	yy=mycam.get_y();

	while(xx.size() > 0){
			float r=sqrt((a/(pv/(ww-xx[0])-c))*(a/(pv/(ww-xx[0])-c))*(1+c*c) );
			x.push_back(r*cos(deg*num*M_PI/180)); 
			y.push_back(r*sin(deg*num*M_PI/180));
			z.push_back(((a/(pv/(ww-xx[0])-c))*c+a)*(hh-yy[0])/pvz);
			xx.erase(xx.begin());
			yy.erase(yy.begin());
			}

}





void scan::set_zero(){

	std::vector <int> xc;
	std::vector <int> yc;

	cam calcam;
	calcam.grep_img(1,0,250);
	xc=calcam.get_x();
	yc=calcam.get_y();

	int www=0;
	int hhh=0;
	int min=1000000000;
	int max=0;		
	while (xc.size()>0){
		www=xc[0];
		if(www<min){min=www;}
		if(www>max){max=www;}
		xc.erase(xc.begin());
		}
	ww=(min+max)/2;
	min=1000000000;
	max=0;		
	while (yc.size()>0){
		www=yc[0];
		if(www<min){min=www;}
		if(www>max){max=www;}
		yc.erase(yc.begin());
		}
	hh=(min+max)/2;
	}



void scan::set_pv(){
	std::vector <int> xc;
	std::vector <int> yc;

	cam calcam;
	calcam.grep_img(1,0,250);
	xc=calcam.get_x();
	yc=calcam.get_y();

	int www=0;
	int hhh=0;
	int min=1000000000;
	int max=0;		
	while (xc.size()>0){
		www=xc[0];
		if(www<min){min=www;}
		if(www>max){max=www;}
		xc.erase(xc.begin());	
		}
	www=(min+max)/2;
	pv=(www-ww)*(a+1)*c;
	}



void scan::set_pvz(){


	std::vector <int> xcc;
	std::vector <int> ycc;

	cam calcam;
	calcam.grep_img(1,0,250);
	xcc=calcam.get_x();
	ycc=calcam.get_y();

	int www=0;
	int hhh=0;
	int min=1000000000;//ein gigapixel...
	int max=0;		
	while (ycc.size()>0){
		www=ycc[0];
		if(www<min){min=www;}
		if(www>max){max=www;}
		ycc.erase(ycc.begin());	
		}
	www=(min+max)/2;
	pvz=a*(www-ww);
	}



void scan::write_values(){
	int i=0;
	
	while(x.size()>0){
			ofstream myfile;
  			myfile.open ("cloud.obj", ios::app);
  			myfile << "v "<<x[0]<<" "<<y[0]<<" "<< z[0] <<" 1.0\n";
  			myfile.close();
			//cout<<"v "<<x[0]<<" "<<y[0]<<" "<< z[0] <<" 1.0\n";
			x.erase(x.begin());
			y.erase(y.begin());
			z.erase(z.begin());
		}

	}


void scan::set_geo(int aa, int b,int stepps){//aa = distance zero camera, b = angle between laser and x-axis
	a=aa;
	c=tan((b)*M_PI/180);
	deg=360.0000/stepps;

	}


