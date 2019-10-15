#include <iostream>
#include "Sword.h"

Sword::Sword()
{
	cout<<"creating sword"<<endl;
	attack=5;
}
Sword::~Sword()
{}
int Sword::get_swordAtt()
{
	return attack;
}
void Sword::set_swordAtt(int a)
{
	attack=a;
}
