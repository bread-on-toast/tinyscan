#ifndef CAM_H
#define CAM_H
class cam
{
private: 
	std::vector <int> res;
	std::vector <int> x;
	std::vector <int> y;
	void get_px(); //berechnet (x,y)
public: 
	void grep_img(int,int,int); //macht bild und wertet aus (channel(rgb),device(/dev/videox), min colorvalue)
	std::vector <int> get_x();
	std::vector <int> get_y();


};

#endif
