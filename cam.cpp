#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <opencv/cv.h>
#include "cam.h"
#include <opencv/highgui.h>
using namespace std;
using namespace cv;
using std::vector;


std::vector <int> res;
std::vector <int> xres;
std::vector <int> yres;
int width=0;
int height=0;




void cam::get_px(){
	int i=1;
	while(res.size()>0){
		xres.push_back(i%width);
		yres.push_back((i-i%width)/width+1);
		res.erase(res.begin());
		i++;
		}
	}

void cam::grep_img(int c, int dev, int tre)//c=channel(rgb), dev=device number, minimum value
    	{
	CvCapture *capture = 0; 
    	IplImage  *frame = 0;
    	/* initialize camera */
    	capture = cvCaptureFromCAM(dev);
    	if ( !capture ) {
    		fprintf( stderr, "Cannot open initialize webcam!\n" );
        	}     
	frame = cvQueryFrame( capture );
	width=frame->width;
	height=frame->height;
	int pixels = height * width;
	int channels = frame->nChannels;

	for (int i = 0; i < pixels*channels; i=i+ channels)
		{
    		int r = frame->imageData[i + 2]+128;
    		int g = frame->imageData[i + 1]+128;
    		int b = frame->imageData[i]+128;
		if(c==1&&r>tre){res.push_back(i);}
		if(c==2&&g>tre){res.push_back(i);}
		if(c==3&&b>tre){res.push_back(i);}
		}

	cvReleaseCapture( &capture );
	get_px();

    }


std::vector <int> cam::get_x(){
	return(xres);
	}


std::vector <int> cam::get_y(){
	return(yres);
	}
