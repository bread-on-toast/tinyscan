#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
using namespace std;
using namespace cv;
using std::vector;


std::vector <int> res;
int width=0;
int height=0;

int cam::get_w(){
	return(width);
	}
int cam::get_h(){
	return(height);
	}

void cam::grep_img(int c, int dev)//c=channel(rgb), dev=device number
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
	int pixels = frame->height * frame->width;
	int channels = frame->nChannels;
	int max=0;
	for (int i = 0; i < pixels*channels; i+= channels)
		{
    		int r = frame->imageData[i + 2]+128;
    		int g = frame->imageData[i + 1]+128;
    		int b = frame->imageData[i]+128;
		if(c==1){res.push_back(r);}
		if(c==2){res.push_back(g);}
		if(c==3){res.push_back(b);}

		if(r>max){max=r;}
		cout <<r<<";"<<g<<";"<<b<<endl;
		}
	cout << max<<endl;
	cvReleaseCapture( &capture );

    }

int cam::get_next(){
	int val=res[0];
	
	}


