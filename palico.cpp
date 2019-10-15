#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include "palico.h"
#include "hunter.h"
#include "monster.h"
#include "Item.h"
using namespace std;

palico::palico()
{
	hp=50;
	attack=5;
	
	cout<<"What is the palico's first name"<<endl;
	cin>>firstName;
	cout<<"What is the palico's last name"<<endl;
	cin>>lastName;
	cout<<"What is the palico's gender"<<endl;
	cin>>gender;
	cout<<"What is the palico's age"<<endl;
	cin>>age;
	
	coordinate.set_x();
	coordinate.set_y();
	color[0]=rand()%256;
	color[1]=rand()%256;
	color[2]=rand()%256;
}
 
void palico::setHp(int h){hp=h;}
int palico::getHp(){return hp;}
int palico::getAttack(){return attack+sword.get_swordAtt();}
string palico::getFirstName(){return firstName;}
string palico::getLastName(){return lastName;}
string palico::getSwordName(){return sword.getItemName();}
int palico::getSwordAttack(){return sword.get_swordAtt();}
string palico::getGender(){return gender;}
Point palico::getPoint(){return coordinate;}
char* palico::getColor(){return color;}
void palico::movePoint()
{
	coordinate.set_x();
	coordinate.set_y();
}
void palico::attackMonsters(monster *m)
{
	mon=m;
	int totalAttack=attack+sword.get_swordAtt();
	if(totalAttack>(mon->getDefense()))
	{
		cout<<"Palico"<<firstName<<" "<<lastName<<" attacked monster ";
		cout<<mon->getFirstName()<<" "<<mon->getLastName()<<"."<<endl;
		cout<< mon->getFirstName()<<" "<<mon->getLastName()<<"'s HP drops from ";
		cout<<mon->getHp()<<" to "<<(mon->getHp())-totalAttack<<endl;
		mon->setHp(mon->getHp()-attack);
	}
}
void palico::cure(hunter *h)
{
	int maxHunterHp=100;
	int maxPalicoHp=50;
	hunt=h;
	if(hunt->getHp()<=90)
	{	
		hunt->setHp((hunt->getHp())+10);
	}
	else
	{
		hunt->setHp(maxHunterHp);
	}
	if(hp<=40)
	{
		hp=hp+10;
	}
	else
	{
		hp=maxPalicoHp;
	}
}
void palico::checkDead()
{
	if(hp>=0)
	{
		cout<<"Now your Palico's HP is "<<hp<<"."<<endl;
	}
	else
	{
		cout<<"Rathalos kiled your cat!!!!!"<<endl;
	}
}