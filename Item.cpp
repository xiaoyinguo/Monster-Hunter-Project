#include "Item.h"
#include <iostream>
#include <string>
using namespace std;
Item::Item()
{
	cout<<"What is the item's name"<<endl;
	cin>>name;	
}
Item::~Item()
{}
string Item::getItemName()
{
	return name;
}
void Item::setItemName(string s)
{
	name=s;
}
