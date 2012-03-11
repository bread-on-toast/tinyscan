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


