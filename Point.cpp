#include <iostream>
#include "Point.h"
#include <cstdlib>
#include <stdio.h>
using namespace std;
void Point::set_x()
{
	int xcoor;
	xcoor=rand()%16;
	x=xcoor;
}
void Point::set_y()
{
	int ycoor;
	ycoor=rand()%16;
	y=ycoor;
}
int Point::get_x()
{
	return x;
}
int Point::get_y()
{
	return y;
}

