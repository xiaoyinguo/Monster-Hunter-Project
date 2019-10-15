#ifndef Champion_h
#define Champion_h
#include "Point.h"

class hunter;
class palico;
class Champion{
private:
	hunter* hunt;
	palico* pal;
	Point coordinate;
public:
	Champion(hunter* h, palico* p);
	Point getPoint();
	void movePoint();
	hunter* getHunter();
	palico* getPalico();
};
#endif