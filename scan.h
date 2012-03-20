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

#ifndef SCAN_H
#define SCAN_H
class scan
{
private: 
	std::string points;
	int lines;
	float ww; //coordinates for zero in image
	float hh;
	float deg; // winkel/stepp
	int pv;	// virtuelle Pixel Radius
	int pvz;// virtuelle Pixel z-Achse
	float c; //tan(winkel kamera laser)
	int a; //abstand kamera nullpunkt
	int dev;

	std::vector <float> x;//X-coordinates
	std::vector <float> y;//Y-coordinates
	std::vector <float> z;//Y-coordinates
	void set_zero(int);//calibration
	void set_pv(int);//calibration
	void set_pvz(int);//calibration

public: 
	void send(const char*);
	void get_img(int);
	void load_file(char*,int);// reads a image-file
	void write_values();//prints Points
	void set_geo(int, int, int, int);//distance zero camera,angle between laser and x-axis, steps/360°
	//void set_dev(int);


};

#endif

