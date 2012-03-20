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

#include <opencv/cv.h>
#include <opencv/highgui.h>
#ifndef CAM_H
#define CAM_H
class cam
{
private: 
	IplImage* get_img(int );
	IplImage* get_cont(IplImage*, int);
	std::vector <int> px;
	std::vector <int> py;
	int width;
	int height;
	int dev;


public: 
	void grep_img(int); //gibt Vurweqktor mit pixelwerten zurück, wobei [0]=w,[1]=hight
	int get_w(); //pixelwert für x,y,	
	int get_h(); //pixelwert für x,y,
	void set_dev(int);
	std::vector <int> get_x();
	std::vector <int> get_y();
	void flush();
};

#endif
