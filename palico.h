#ifndef palico_h
#define palico_h
#include <cstring>
#include "Sword.h"
#include "Point.h"
using namespace std;


class hunter;
class monster;

class palico
{
private:
	string lastName;
	string firstName;
	string gender;
	Sword sword;
	int age;
	int hp;
	int attack;
	char color[3];
	Point coordinate;
	hunter* hunt;
	monster* mon;
public:
	//constructor
	palico();
	//set method
	void setHp(int h);
	//getmethods
	int getHp();
	int getAttack();
	string getFirstName();
	string getLastName();
	string getSwordName();
	string getGender();
	Point getPoint();
	int getSwordAttack();
	//other methods
	void attackMonsters(monster *m);
	void cure(hunter *h);
	void checkDead();
	void movePoint();
	char* getColor();
};

#endif 
