#include "Champion.h"
#include "hunter.h"
#include "palico.h"
#include "Point.h"

Champion::Champion(hunter* h, palico* p)
{
	hunt=h;
	pal=p;
	coordinate.set_x();
	coordinate.set_y();
}
void Champion::movePoint()
{
	coordinate.set_x();
	coordinate.set_y();
}
hunter* Champion::getHunter()
{
	return hunt;
}
palico* Champion::getPalico()
{
	return pal;
}
Point Champion::getPoint()
{
	return coordinate;
}