#include "HunterBook.h"
#include "hunter.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <forward_list>
#include <functional>
#include <iterator>
using namespace std;
HunterBook::HunterBook()
{
	forward_list<hunter*> bookH;
}

HunterBook::~HunterBook(){}
hunter* HunterBook::getHunter(int index)
{
	int counter=0;
	for(auto ptr=bookH.begin();ptr!=bookH.end();++ptr)
	{
		if(counter==index)
		{
			return(*ptr);
			break;
		}
		counter++;
	}
}
void HunterBook::add()
{
	hunter* h=new hunter();

	bool newHunter=true;
	if (bookH.empty()==false)
	{	
		for(auto ptr=bookH.begin();ptr!=bookH.end();++ptr)
		{
			if((*ptr)->getFirstName()==h->getFirstName() && (*ptr)->getLastName()==h->getLastName())
			{
				newHunter=false;;
				break;
			}
		}
	}
	if(newHunter)
	{
		bookH.push_front(h);
	}
}

int HunterBook::size()
{
	int size=0;
	size=distance(bookH.begin(),bookH.end());
	return size;
}

void HunterBook::remove(string a, string b)
{
	string fname=a;
	string lname=b;
	for(auto ptr=bookH.begin();ptr!=bookH.end();++ptr)
	{
		if((*ptr)->getFirstName()==fname && (*ptr)->getLastName()==lname)
		{
			bookH.remove(*ptr);
			break;
		}
	}
}


void HunterBook::save()
{
	ofstream outFile;
	outFile.open("Hunter.txt");
	for (auto ptr=bookH.begin();ptr!=bookH.end();ptr++)
	{   
		//write hunter stats to file
		outFile<<(*ptr)->getFirstName()<<" "<<(*ptr)->getLastName();
		outFile<<", "<<(*ptr)->getGender()<<", "<<(*ptr)->getAge()<<", "<<endl;
		outFile<<"Energy: "<<(*ptr)->getEnergy();
		outFile<<", Defense: "<<(*ptr)->getDefense();
		outFile<<", HP: "<<(*ptr)->getHp();
		outFile<<", Attack: "<<(*ptr)->getAttack();
		outFile<<", Defense: "<<(*ptr)->getDefense();
		outFile<<", Sword: "<<(*ptr)->getSwordName()<<"("<<(*ptr)->getSwordAttack()<<"), ";
		outFile<<"Equipment: "<<(*ptr)->getEquipName()<<"("<<(*ptr)->getEquipDefense()<<")"<<endl;		
	}
	outFile.close();
}


void HunterBook::search()
{
	char* fname;
	cout<<"Enter First Name of the Hunter: ";
	cin>>fname;
	char* lname;
	cout<<"Enter Last Name of the Hunter: ";
	cin>>lname;
	bool found=false;
	for(auto ptr=bookH.begin();ptr!=bookH.end();++ptr)
	{
		if((*ptr)->getFirstName()==fname && (*ptr)->getLastName()==lname)
		{  
			//output hunter stats
			cout<<(*ptr)->getFirstName()<<" "<<(*ptr)->getLastName();
			cout<<", "<<(*ptr)->getGender()<<", "<<(*ptr)->getAge()<<", "<<endl;
			cout<<"Energy: "<<(*ptr)->getEnergy();
			cout<<", Defense: "<<(*ptr)->getDefense();
			cout<<", HP: "<<(*ptr)->getHp();
			cout<<", Attack: "<<(*ptr)->getAttack();
			cout<<", Defense: "<<(*ptr)->getDefense();
			cout<<", Sword: "<<(*ptr)->getSwordName()<<"("<<(*ptr)->getSwordAttack()<<"), ";
			cout<<"Equipment: "<<(*ptr)->getEquipName()<<"("<<(*ptr)->getEquipDefense()<<")"<<endl;
			found=true;
			//exit loop
			break;
		}
	}
	if (found==false)
	{
		cout<<"Can not find "<<fname<<" "<<lname<<endl;
	}
}


hunter* HunterBook::get_max(int s)
{
	hunter* h;
	int max=0;
	switch(s)
	{
		case 0:
			for(auto ptr=bookH.begin();ptr!=bookH.end();++ptr)
			{
				if((*ptr)->getEnergy()>max)	
				{
					max=(*ptr)->getEnergy();
					h=(*ptr);
				}
			}
			break;
		case 1:
			for(auto ptr=bookH.begin();ptr!=bookH.end();++ptr)
			{
				if((*ptr)->getHp()>max)	
				{
					max=(*ptr)->getHp();
					h=(*ptr);
				}
			}
			break;
		case 2:
			for(auto ptr=bookH.begin();ptr!=bookH.end();++ptr)
			{
				if((*ptr)->getAttack()>max)	
				{
					max=(*ptr)->getAttack();
					h=(*ptr);
				}
			}
			break;
		case 3:
			for(auto ptr=bookH.begin();ptr!=bookH.end();++ptr)
			{
				if((*ptr)->getDefense()>max)	
				{
					max=(*ptr)->getDefense();
					h=(*ptr);
				}
			}
			break;
		default:
			break;
	}
	return h;
}

void HunterBook::sort(int s)
{
	switch(s)
	{
		case 0:
			bookH.sort([](hunter* a, hunter * b) {return a->getEnergy() < b->getEnergy();});
			break;
		case 1:
			bookH.sort([](hunter* a, hunter * b) {return a->getHp() < b->getHp();});
			break;
		case 2:
			bookH.sort([](hunter* a, hunter * b) {return a->getAttack() < b->getAttack();});
			break;
		case 3:
			bookH.sort([](hunter* a, hunter * b) {return a->getDefense() < b->getDefense();});
			break;
		default:
			break;
	}	
}

//moving updating point locations of all hunters in hunterBook
void HunterBook::hunterMove()
{
	for(auto ptr=bookH.begin();ptr!=bookH.end();++ptr)
	{
		(*ptr)->movePoint();
	}
}
