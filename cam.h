#ifndef CAM_H
#define CAM_H
class cam
{
private: 
	std::vector <int> res;
public: 
	void cam::grep_img(int,int); //gibt Vurweqktor mit pixelwerten zurück, wobei [0]=w,[1]=hight
	int cam::get_w(); //pixelwert für x,y,	
	int cam::get_h(); //pixelwert für x,y,
};

#endif
