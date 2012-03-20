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

#include "cam.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
using namespace std;
using namespace cv;
using std::vector;



std::vector <int> px;
std::vector <int> py;
int width=0;
int height=0;
int dev=0;

int cam::get_w(){
	return(width);
	}
int cam::get_h(){
	return(height);
	}


std::vector <int> cam::get_x(){return px;}
std::vector <int> cam::get_y(){return py;}




void cam::grep_img(int c)//c=channel(rgb), d=device number
    	{
    	IplImage  *frame = 0;
	frame = get_img(dev);	cvSaveImage("/tmp/tinyscan.png" ,frame);
	width=frame->width;
	height=frame->height;
	int channels=frame->nChannels;
	int pixels = height * width*channels;
	cvSaveImage("/tmp/tinyscan.png" ,frame);

	int i=0;
	uchar *p;
	cvGetRawData(frame, (uchar**)&p);

	for (int y = 0; y < frame->height; y++){
		for(int x=0; x<(frame->width);x++){

			if(p[y*frame->width + x]>200){
				//cout <<p<<"\n";
				px.push_back(x) ;
				py.push_back(y);cout<<x<<"  --  "<<y<<endl;
				//x=frame->width;//erstes pixel wird gezählt, danach neue zeile
				}
			}
		}
	}



IplImage* cam::get_cont(IplImage* img, int thr){

	IplImage*	g_gray = NULL;
	CvMemStorage* 	storage = NULL;
	if( storage == NULL ){
		g_gray = cvCreateImage( cvGetSize( img ), 8, 1 );
		storage = cvCreateMemStorage(0);
	} else {
		cvClearMemStorage( storage );
	}

	CvSeq* contours = 0;
	cvCvtColor( img, g_gray, CV_BGR2GRAY );
	cvThreshold( g_gray, g_gray, thr, 255, CV_THRESH_BINARY );
	cvFindContours( g_gray, storage, &contours );
	cvZero( g_gray );
	if( contours ){
		cvDrawContours(
			g_gray,
			contours,
			cvScalarAll(255),
			cvScalarAll(255),
			100 );
	}
	cvShowImage( "Contours", g_gray );
	return(g_gray);
}


IplImage* cam::get_img(int d){
	CvCapture *capture = 0; 
    	IplImage  *frame = 0;
    	/* initialize camera */
    	capture = cvCaptureFromCAM(d); 
    	if ( !capture ) {
    		fprintf( stderr, "Cannot open initialize webcam!\n" );
        	}     
	frame = get_cont(cvQueryFrame( capture ), 180);
	//frame = cvQueryFrame( capture );

	//cvSaveImage("/tmp/tinyscan.png" ,frame);
	cvReleaseCapture( &capture );
	return frame;
	}

void cam::set_dev(int d){
	dev=d;
	}
void cam::flush(){
	px.clear();
	py.clear();
	}







