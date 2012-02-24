#ifndef SCAN_H
#define SCAN_H
class scan
{
private: //all the Values 
	std::string points;
	int lines;
	int cx;
	int cy;
	int ww;
	int hh;
//	std::vector <string> cont;
	int i;

	std::vector <int> x;
	std::vector <int> y;

	int pointsx;
	int pointsy;



public: // all the Methods
	void load_file(char*);//array (x,y)
	void read_file();
	void set_cal(int, int, int, int);//ww,hh,cx,cy
	void test();
	void write_values(char*);
	//bool status();

};

#endif

