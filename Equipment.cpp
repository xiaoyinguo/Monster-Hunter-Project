#include "Equipment.h"
#include <iostream>
Equipment::Equipment()
{
	cout<<"Creating equipment"<<endl;
	defense=5;
}
Equipment::~Equipment()
{}
int Equipment::get_equipDef()
{
	return defense;
}
void Equipment::set_equipDef(int a)
{
	defense=a;
}
