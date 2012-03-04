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
	int pv;	// virtuelle Pixel
	float c; //tan(winkel kamera laser)
	int a; //abstand kamera nullpunkt


	std::vector <float> x;//X-coordinates
	std::vector <float> y;//Y-coordinates
	std::vector <float> z;//Y-coordinates
	void set_zero();//calibration
	void set_pv();//calibration
public: 
	void load_file(char*,int);// reads a image-file



	void write_values();//prints Points
	void set_geo(int, int, int);//distance zero camera,angle between laser and x-axis, steps/360°


};

#endif

