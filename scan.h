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


};

#endif

