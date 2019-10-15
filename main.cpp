#include "hunter.h"
#include "monster.h"
#include "palico.h"
#include "HunterBook.h"
#include "MonsterBook.h"
#include "PalicoBook.h"
#include "Champion.h"
#include "Point.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <chrono>
#include <cstring>
#include <cmath>
#include <unistd.h>
#include <thread>
#include "bmplib.h"

using namespace std;

//using code from shapes.cpp
// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE][RGB];

//code for drawing square
void draw_rectangle(int top, int left,char* color) {
  	for(int i = top; i < top + 32; i++){
    	for(int j = left; j < left + 32; j++){
      		image[i][j][0] = color[0];
      		image[i][j][1] = color[1];
      		image[i][j][2] = color[2];
    	}
  	}
}
//code for drawing circle
void draw_circle(int top, int left,char* color)
{
	int radius=16;
 	int center_y=top+16;
  	int center_x=left+16;
  	double distance; 
 	for(int i = top; i < top + 32; i++){
    	for(int j = left; j < left + 32; j++){
      		distance=sqrt(pow(i-center_y,2)+pow(j-center_x,2));
      		if(distance<=radius)
      		{
	      		image[i][j][0] = color[0];
	      		image[i][j][1] = color[1];
	      		image[i][j][2] = color[2];
	  		}
    	}
 	}
}
//code for drawing triangle
void draw_triangle(int leftx, int lefty,  char* color){
  	for(int i = 0 ; i <32 ; i++){
    	for(int j = 0; j <(32*i/32); j ++){
      	image[leftx+i][lefty + 32*(32-i)/32/2 + j][0] = color[0];
      	image[leftx+i][lefty + 32*(32-i)/32/2 + j][1] = color[1];
      	image[leftx+i][lefty + 32*(32-i)/32/2 + j][2] = color[2];  
    	}
  	}
}
//code for wiping the board blank
void make_blank()
{
	for (int i=0; i < SIZE; i++) {
      	for (int j=0; j < SIZE; j++) {
        	if(i%32==0 || j%32==0)
          	continue;
        	for (int k=0; k < RGB; k++) {
         		image[i][j][k] = 255;
         	}
        }
    }
}
//drawing the palicos, hunters, and monsters on the grid
void drawGrid(PalicoBook palicoBook, HunterBook hunterBook, MonsterBook monsterBook)
{
	make_blank();
	palico* tempP;
	for(int i=0;i<palicoBook.size();i++)
	{
		tempP=palicoBook.getPalico(i);
		char* color=tempP->getColor();
		draw_circle((32*tempP->getPoint().get_y()),(32*tempP->getPoint().get_x()),color);
	}
	monster* tempM;
	for (int i=0;i<monsterBook.size();i++)
	{
		tempM=monsterBook.getMonster(i);
		char*color=tempM->getColor();
		draw_triangle((32*tempM->getPoint().get_y()),(32*tempM->getPoint().get_x()),color);
	}
	hunter* tempH;
	for(int i=0;i<hunterBook.size();i++)
	{
		tempH=hunterBook.getHunter(i);
		char*color=tempH->getColor();
		draw_rectangle((32*tempH->getPoint().get_y()),(32*tempH->getPoint().get_x()),color);
	}
}

//hunter versus monster
bool enterCombatHunter(hunter* hunt, monster* mon)
{
	//hunters turn
	while(hunt->getHp()>0&&mon->getHp()>0)
	{
		
		hunt->attackMonsters(mon);
		if(mon->getHp()>0&&hunt->getHp()>0)
		{
			//monster's turn
			mon->attackHunter(hunt);		
		}
		hunt->checkDead();
	}
	if (hunt->getHp()<=0)
	{
		//if hunter died
		return true;
	}
	else
	{
		//if hunter is alive
		return false;
	}
}

//champion vs monster
bool enterCombatChampion(hunter* hunt, palico* pal, monster* mon)
{
	double randNum;
	string decision;
	while(hunt->getHp()>0&&mon->getHp()>0)
	{
		//hunters turn
		hunt->attackMonsters(mon);
		//monsters turn
		if(mon->getHp()>0&&hunt->getHp()>0)
		{
			//generating random number to determine what monster does
			randNum=static_cast<double>(rand())/RAND_MAX;
			//70% chance attack hunter
			if(randNum<0.7)
			{
				mon->attackHunter(hunt);
			}
			//20% chance attack palico
			else if(randNum<0.9&&pal->getHp()>0)
			{
				mon->attackPalico(pal);
				if (pal->getHp()<=0)
				{	//checking if palico is killed by monster					
					pal->checkDead();
				}
			}
			//10% chance do nothing
			else
			{}			
		}
		//palico's turn
		if(pal->getHp()>0&&mon->getHp()>0)
		{
			//Palico turn
			cout<<"Now your Palico should _________(attack/cure)"<<endl;
			cin>>decision;
			if (decision=="attack")
			{
				pal->attackMonsters(mon);
			}
			else
			{
				pal->cure(hunt);
			}		
		}
		hunt->checkDead();
	}
	if (hunt->getHp()<=0)
	{
		//if hunter died
		return true;
	}
	else
	{
		//if hunter is alive
		return false;
	}
}

//comparing two points, return true if points are equal
bool comparePoint(Point x, Point y)
{
	if(x.get_x()==y.get_x() && x.get_y()==y.get_y())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	//seeding my random number generator
	srand(time(0));

	//will store my random number which I 
	//will use to determine what monster does if facing a champion
	double randNum;

	//will store the user decision
	string decision;
	
	cout<<"Welcome to text-based monster hunter world. ";

	//creating the books that store the hunters, monsters, and palicos
	HunterBook hunterBook;
	MonsterBook monsterBook;
	PalicoBook palicoBook;
	
	//adding hunters
	for(int i=0;i<3;i++)
	{
		cout<<"adding hunter to the book of hunters"<<endl;
		hunterBook.add();
	}
	//adding monsters
	for(int i=0;i<10;i++)
	{
		cout<<"adding monster to the book of monsters"<<endl;
		monsterBook.add();
	}
	//adding palicos
	for(int i=0;i<5;i++)
	{
		cout<<"adding palico to the book of palicos"<<endl;
		palicoBook.add();
	}
	
	//will hold champions, champion is a hunter/palico team
	vector<Champion*> champions;
	//champ will be true if there are any champions, false if there are no champions
	bool champ=false;
	
	//drawing initial positions
	drawGrid(palicoBook, hunterBook, monsterBook);
	showRGBBMP(image);
	
	//will be true if hunter dies, false if monster dies
	bool death;

	//loop will continue until either there are no monsters or there are no more hunters or champions
	while(((champions.size()!=0&&champ==true)&&monsterBook.size()!=0)||(hunterBook.size()!=0&&monsterBook.size()!=0))
	{


		//drawing palicos, hunters, and monsters
		drawGrid(palicoBook, hunterBook, monsterBook);
		//if there are any champions draw the champion (palico circle on top of hunter square)
		if(champ)
		{
			for(Champion* i:champions)
			{
				char* colorP=i->getPalico()->getColor();
				char* colorH=i->getHunter()->getColor();
				draw_rectangle((32*i->getPoint().get_y()),(32*i->getPoint().get_x()),colorH);
				draw_circle((32*i->getPoint().get_y()),(32*i->getPoint().get_x()),colorP);
			}
		}
		//show image
		showRGBBMP(image);

		//checking if any palicos or hunters are at same point
		for(int i=0;i<hunterBook.size();i++)
		{
			hunter* tempH=hunterBook.getHunter(i);
			for (int j=0;j<palicoBook.size();j++)
			{
				palico* tempP=palicoBook.getPalico(i);
				if(comparePoint(tempH->getPoint(), tempP->getPoint()))
				{
					//if they intersect then remove the hunter and palico from their respective books
					//and add them to the champion vector as a new champion 
					Champion* tempC=new Champion(tempH, tempP);
					hunterBook.remove(tempH->getFirstName(), tempH->getLastName());
					palicoBook.remove(tempP->getFirstName(), tempP->getLastName());
					champions.push_back(tempC);
					//setting champ to true because there are now champions
					champ=true;
				}
			}
		}
		//checking if any hunters or monsters are at same point
		for(int i=0;i<hunterBook.size();i++)
		{
			hunter* tempH=hunterBook.getHunter(i);
			for (int j=0;j<monsterBook.size();j++)
			{
				monster* tempM=monsterBook.getMonster(i);
				if(comparePoint(tempH->getPoint(), tempM->getPoint()))
				{
					
					//if they are at the same point then enter combat in new thread 
					thread t1(enterCombatHunter,tempH, tempM);
					t1.join();
					monsterBook.remove(tempM->getFirstName());
					
					
				}
			}
		}
		
		//if there are champions
		if(champ==true&&champions.size()!=0)
		{
			//checking if any champions or monsters are at the same point if champions exist
			for(int i=0;i<champions.size();i++)
			{
				Champion* tempC=champions.at(i);
				for (int j=0;j<monsterBook.size();j++)
				{
					monster* tempM=monsterBook.getMonster(j);
					if(comparePoint(tempC->getPoint(), tempM->getPoint()))
					{
						
						//if they are at same point then enter combat
						thread t2(enterCombatChampion,tempC->getHunter(), tempC->getPalico(), tempM);									
						t2.join();
						monsterBook.remove(tempM->getFirstName());
						
					}
				}
			}
		}
		//updating all point locations
		hunterBook.hunterMove();
		monsterBook.monsterMove();
		palicoBook.palicoMove();
		if(champ)
		{
			for(Champion* i: champions)
			{
				i->movePoint();
			}
		}
		//pausing briefly so image can refresh
		sleep(2);
	}
	return 0;
}
