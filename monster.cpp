#include <iostream>
#include <cstring>
#include "monster.h"
#include "hunter.h"
#include "palico.h"
using namespace std;


monster::monster()
{
	hp=100;
	attack=20;
	defense=1;
	coordinate.set_x();
	coordinate.set_y();
	color[0]=rand()%256;
	color[1]=rand()%256;
	color[2]=rand()%256;
	
	age=0;
	cout<<"What is the monster's first name"<<endl;
	cin>>firstName;
	cout<<"What is the monster's last name"<<endl;
	cin>>lastName;
	cout<<"What is the monster's gender"<<endl;
	cin>>gender;
	while(age<18||age>70)
	{
		cout<<"What is the monster's age (18-70)"<<endl;
		cin>>age;
	}
	
}
monster::~monster(){}
int monster::getHp(){return hp;}
int monster::getAttack(){return attack;}
int monster::getDefense(){return defense;}
string monster::getGender(){return gender;}
int monster::getAge(){return age;}
void monster::setHp(int h){hp=h;}
string monster::getFirstName(){return firstName;}
string monster::getLastName(){return lastName;}
Point monster::getPoint(){return coordinate;}
char* monster::getColor(){return color;}
void monster::movePoint()
{
	coordinate.set_x();
	coordinate.set_y();
}
void monster::attackHunter(hunter* h)
{
	hunt=h;
	int totalDefense=hunt->getDefense()+hunt->getEquipDefense();
	
	
		if(attack>(2*totalDefense))
		{
			cout<<firstName<<" "<<lastName<<" attacked ";
			cout<<"hunter "<<hunt->getFirstName()<<" "<<hunt->getLastName()<<"."<<endl;
			cout<< hunt->getFirstName()<<" "<<hunt->getLastName()<<"'s HP drops from ";
		
			cout<<hunt->getHp()<<" to "<<hunt->getHp()-attack+(2*totalDefense)<<endl;
			hunt->setHp(hunt->getHp()-attack+(2*totalDefense));
		}
		else
		{
			cout<<"You defended against the attack successfully."<<endl;
		}
	
	
}
void monster::attackPalico(palico* p)
{
	pal=p;
	cout<<"Rathalos attacked your Palico. Your Palico's HP drops from ";
	cout<<pal->getHp()<<" to "<<(pal->getHp())-attack<<endl;
	pal->setHp((pal->getHp())-attack);
}
void monster::checkDead()
{
	if(hp>=0)
	{
		cout<<"Now monster's HP is "<<hp<<"."<<endl;
	}
	else
	{
		cout<<"You have defeated Ratholos. You can explore this area again."<<endl;
	}
}