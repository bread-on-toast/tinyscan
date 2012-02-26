#ifndef SCAN_H
#define SCAN_H
class scan
{
private: 
	std::string points;
	int lines;
	int cx; //calibration-factors
	int cy;
	int ww; //coordinates for zero
	int hh;
	int height;//height of image
	int i;

	std::vector <int> x;//X-coordinates
	std::vector <int> y;//Y-coordinates

	int pointsx;//
	int pointsy;//

	void read_file();//function calculating coordinates from position in the image


public: 
	void load_file(char*);// reads a svg-file

	void set_cal(int, int, int, int);//calibration
	void write_values(char*);//prints Points

};

#endif

