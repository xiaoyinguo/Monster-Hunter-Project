#include <iostream>
#include <cstring>
#include "hunter.h"
#include  "monster.h"
#include "Point.h"
#include "Item.h"

using namespace std;

hunter::hunter()
{
	
	cout<<"What is the hunter's first name"<<endl;
	cin>>firstName;
	cout<<"What is the hunter's last name"<<endl;
	cin>>lastName;
	cout<<"What is the hunter's gender"<<endl;
	cin>>gender;
	cout<<"What is the hunter's age"<<endl;
	cin>>age;
	
	energy=100;
	hp=100;
	attack=10;
	defense=4;
	coordinate.set_x();
	coordinate.set_y();
	color[0]=rand()%256;
	color[1]=rand()%256;
	color[2]=rand()%256;
	
}
hunter::~hunter(){}
int hunter::getHp()const{return hp;}
int hunter::getEnergy()const {return energy;}
int hunter::getAttack()const {return attack;}
int hunter::getDefense()const {return defense;}
bool hunter::getDefend(){return defend;}
int hunter::getEquipDefense(){return equip.get_equipDef();}
int hunter::getSwordAttack(){return sword.get_swordAtt();}
string hunter::getEquipName(){return equip.getItemName();}
string hunter::getSwordName(){return sword.getItemName();}
string hunter::getFirstName(){return firstName;}
string hunter::getLastName(){return lastName;}
string hunter::getGender(){return gender;}
int hunter::getAge(){return age;}
Point hunter::getPoint(){return coordinate;}
char* hunter::getColor(){return color;}
void hunter::setHp(int h){hp=h;}
void hunter::setEnergy(int e){energy=e;}
void hunter::movePoint()
{
	coordinate.set_x();
	coordinate.set_y();
}
void hunter::attackMonsters(monster *m)
{
	mon=m;
	int totalAttack=attack+sword.get_swordAtt();
	if(totalAttack>=(mon->getDefense()))
	{
		cout<<firstName<<" "<<lastName<<" attacked ";
		cout<<"monster "<<mon->getFirstName()<<" "<<mon->getLastName()<<"."<<endl;
		cout<< mon->getFirstName()<<" "<<mon->getLastName()<<"'s HP drops from ";
		cout<<mon->getHp()<<" to "<<mon->getHp()-attack<<endl;
		mon->setHp(mon->getHp()-totalAttack);
	}
	defend=false;	
}
void hunter::defendMonsters()
{
	defend=true;
	
}
void hunter::checkDead()
{
	if(hp>=0)
	{
		cout<<"Now your HP is "<<hp<<"."<<endl;
	}
	else
	{
		cout<<"You faint. Now return back to the village."<<endl;
	}
}

