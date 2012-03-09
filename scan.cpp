#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<limits>
#include <cmath> 
#include "CImg.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>


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


void scan::get_img(int dev)//dev=device number
    	{
	CvCapture *capture = 0; 
    	IplImage  *frame = 0;
    	/* initialize camera */
    	capture = cvCaptureFromCAM(dev);
    	if ( !capture ) {
    		fprintf( stderr, "Cannot open initialize webcam!\n" );
        	}     
	frame = cvQueryFrame( capture );
	cvSaveImage("/tmp/tinyscan.png" ,frame);
	cvReleaseCapture( &capture );
	}

void scan::load_file(char* name, int num){

	CImg<unsigned char> img(name);
	int width = img.width();
	int height = img.height();

	for (float yy = 0.00; yy < height; yy++){
		for (float xx = 0.00; xx < width; xx++){
			if((int)img(xx,yy,0,0)>250){
				float r=sqrt((a/(pv/(ww-xx)-c))*(a/(pv/(ww-xx)-c))*(1+c*c) );
				x.push_back(r*cos(deg*num*M_PI/180)); 
				y.push_back(r*sin(deg*num*M_PI/180));
				z.push_back(((a/(pv/(ww-xx)-c))*c+a)*(hh-yy)/pvz);
				break;
				}
			}
		}

}





void scan::set_zero(int dev){

	std::vector <int> xc;
	std::vector <int> yc;
	get_img(dev);
	CImg<unsigned char> img("/tmp/tinyscan.png");
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



void scan::set_pv(int dev){
	std::vector <int> xc;
	std::vector <int> yc;
	get_img(dev);
	CImg<unsigned char> img("/tmp/tinyscan.png");
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
	}



void scan::set_pvz(int dev){
	std::vector <int> xcc;
	std::vector <int> ycc;
	get_img(dev);
	CImg<unsigned char> img("/tmp/tinyscan.png");
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
	}



void scan::write_values(){
	int i=0;
	ofstream myfile;
  	myfile.open ("cloud.obj", ios::app);
  			
	while(x.size()>0){
	
			myfile<<"v "<<x[0]<<" "<<y[0]<<" "<< z[0] <<" 1.0\n";
			x.erase(x.begin());
			y.erase(y.begin());
			z.erase(z.begin());
		}

	myfile.close();
	}


void scan::set_geo(int aa, int b,int stepps, int dev){//aa = distance zero camera, b = angle between laser and x-axis
	a=aa;
	c=tan((b)*M_PI/180);
	deg=360.0000/stepps;
	send("Z1");
	set_zero(dev); 
	send("Z0");
	send("X1");
	set_pv(dev);
	send("X0"); 
	send("Y1");
	set_pvz(dev); 
	send("Y0");
	}

void scan::send(const char* mes){
		ofstream myfile;
  		myfile.open ("/dev/ttyUSB1", ios::app);
  		myfile << mes;
  		myfile.close();
	}


