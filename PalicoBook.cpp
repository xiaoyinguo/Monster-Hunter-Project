#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstring>
#include "palico.h"
#include "PalicoBook.h"
using namespace std;



struct compareHp{
	bool operator () (palico* a, palico* b) 
  		{ return(a->getHp() > b->getHp());}
};
  	
struct compareAtt{
	bool operator () (palico* a, palico* b) 
  		{ return(a->getAttack() > b->getAttack());}
};
  
PalicoBook::PalicoBook()
{
	
	int h_a=0;
	make_heap(bookP.begin(),bookP.end(),compareHp());
	//auto compare=[](palico* a, palico * b) {return a->getHp() < b->getHp();};

}

PalicoBook::~PalicoBook(){}

void PalicoBook::add()
{
	palico* p=new palico();
	bool newPalico=true;
	
	
	if (bookP.empty()==false)
	{	
		for(palico* i:bookP)
		{
			if(i->getFirstName()==p->getFirstName() && i->getLastName()==p->getLastName())
			{
				newPalico=false;;
				break;
			}
		}
	}
	
	if(newPalico)
	{
		bookP.push_back(p);
	}
	
}
void PalicoBook::change_mode(int hp_attack)
{
	if(hp_attack!=h_a)
	{
		if(hp_attack==0)
		{
			h_a=0;
			make_heap(bookP.begin(), bookP.end(), compareHp());
		}
		else
		{
			h_a=1;
			make_heap(bookP.begin(), bookP.end(), compareAtt());
		}
	}
}
palico* PalicoBook::max(int hp_attack)
{
	if(hp_attack==h_a)
	{
		return bookP.front();
	}
	else
	{
		if(hp_attack=1)
		{
			make_heap(bookP.begin(), bookP.end(), compareHp());
			return bookP.front();
		}
		else
		{
			make_heap(bookP.begin(), bookP.end(), compareAtt());
			return bookP.front();
		}
	}
	
}


void PalicoBook::remove(string a, string b)
{
	string fname=a;	
	string lname=b;
	
	int position=0;
	for(palico* i:bookP)
		{
			if(i->getFirstName()==fname && i->getLastName()==lname)
			{
				bookP.erase(bookP.begin()+position);
				break;
			}
			position++;
		}
}


void PalicoBook::save()
{
	ofstream outFile;
	outFile.open("Palico.txt");
	for (palico* i:bookP)
	{   
		outFile<<i->getFirstName()<<" "<<i->getLastName();
		outFile<<", "<<i->getGender();
		outFile<<", HP: "<<i->getHp();
		outFile<<", Attack: "<<i->getAttack();
		outFile<<", Sword: "<<i->getSwordName()<<"("<<i->getSwordAttack()<<")"<<endl;
	}
	outFile.close();
}


void PalicoBook::search()
{
	char* fname;
	cout<<"Enter First Name of the Hunter: ";
	cin>>fname;
	char* lname;
	cout<<"Enter Last Name of the Hunter: ";
	cin>>lname;
	bool found=false;
	for(palico* i:bookP)
	{
		if(i->getFirstName()==fname && i->getLastName()==lname)
		{  
			cout<<i->getFirstName()<<" "<<i->getLastName();
			cout<<", "<<i->getGender();
			cout<<", HP: "<<i->getHp();
			cout<<", Attack: "<<i->getAttack();
			cout<<", Sword: "<<i->getSwordName()<<"("<<i->getSwordAttack()<<")"<<endl;
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

void PalicoBook::palicoMove()
{
	for(palico* i:bookP)
	{
		i->movePoint();
	}	
}
int PalicoBook::size()
{
	int size=0;
	for(palico* i:bookP)
	{
		size++;
	}
	return size;
}
palico* PalicoBook::getPalico(int index)
{
	int counter=0;
	for(palico* i:bookP)
	{
		if (counter==index)
		{
			return i;
			break;
		}
		counter++;
	}
}


