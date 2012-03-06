#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<limits>
#include <cmath> 
#include "CImg.h"
using namespace std;
using namespace cimg_library;
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




void scan::load_file(char* name, int num){

	CImg<unsigned char> img(name);
	int width = img.width();
	int height = img.height();

	for (float yy = 0.00; yy < height; yy++){
		for (float xx = 0.00; xx < width; xx++){
			if((int)img(xx,yy,0,0)>250){
				
				

				//float r=sqrt(c*c+1)*a*(ww-xx)/(c*(ww-xx)+pv);
				float r=sqrt((a/(pv/(ww-xx)-c))*(a/(pv/(ww-xx)-c))*(1+c*c) );


//rmax=cos(alfa)*a
//r=(cos(atan(c))-px/pv*sin(atan(c)))*a

				x.push_back(r*cos(deg*num*M_PI/180)); 
				y.push_back(r*sin(deg*num*M_PI/180));
				//z.push_back((hh-yy)/pv* sqrt((a-x[x.size()-1])* (a*a-x[x.size()-1])*x[x.size()-1]) +y[y.size()-1]*y[y.size()-1])); 
				z.push_back(((a/(pv/(ww-xx)-c))*c+a)*(hh-yy)/pvz);
				break;
				}
			}
		}

}





void scan::set_zero(){

	std::vector <int> xc;
	std::vector <int> yc;
	CImg<unsigned char> img("./vimg/cal/cal0.png");
	int width = img.width();
	int height = img.height();
	for (int yy = 0; yy < height; yy++){
		for (int xx = 0; xx < width; xx++){
			if((int)img(xx,yy,0,0)>250){
				xc.push_back(xx); 
				yc.push_back(yy);
				}
			}
		
		}
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
	}



void scan::set_pv(){
	std::vector <int> xc;
	std::vector <int> yc;
	CImg<unsigned char> img("./vimg/cal/calx.png");
	int width = img.width();
	int height = img.height();
	for (int yy = 0; yy < height; yy++){
		for (int xx = 0; xx < width; xx++){
			if((int)img(xx,yy,0,0)>200){
				xc.push_back(xx); 
				yc.push_back(yy);
				}
			}
		
		}
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
	www=(min+max)/2;


	pv=(www-ww)*(a+1)*c;
	//pv=1000.000;
	}



void scan::set_pvz(){
	std::vector <int> xcc;
	std::vector <int> ycc;
	CImg<unsigned char> img("./vimg/cal/calz.png");
	int width = img.width();
	int height = img.height();
	for (int yy = 0; yy < height; yy++){
		for (int xx = 0; xx < width; xx++){
			if((int)img(xx,yy,0,0)>200){
				xcc.push_back(xx); 
				ycc.push_back(yy);
				}
			}
		
		}
			int www=0;
			int hhh=0;

			int min=height;
			int max=0;		
			while (ycc.size()>0){
				www=ycc[0];
				if(www<min){min=www;}
				if(www>max){max=www;}
				ycc.erase(ycc.begin());	
				}
	www=(min+max)/2;


	pvz=a*(www-ww);

	//pv=1000.000;


	}



void scan::write_values(){
	int i=0;
	while(x.size()>0){
	
			cout<<"v "<<x[0]<<" "<<y[0]<<" "<< z[0] <<" 1.0\n";
			x.erase(x.begin());
			y.erase(y.begin());
			z.erase(z.begin());
		}

	}


void scan::set_geo(int aa, int b,int stepps){//aa = distance zero camera, b = angle between laser and x-axis
	a=aa;
	c=tan((b)*M_PI/180);
	deg=360.0000/stepps;
	set_zero(); 
	set_pv(); 
	set_pvz(); 
	}


