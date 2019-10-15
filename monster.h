#ifndef monster_h
#define monster_h
#include <string>
#include "Point.h"
using namespace std;
class hunter;
class palico;

class monster
{
private:
	string lastName;
	string firstName;
	string gender;
	int age;
	int hp;
	int attack;
	int defense;
	char color[3];
	Point coordinate;
	hunter* hunt;
	palico* pal;
public:
	//constructor
	monster();
	~monster();
	//get methods
	int getHp();
	int getAttack();
	int getDefense();
	string getFirstName();
	string getLastName();
	string getGender();
	int getAge();
	char* getColor();
	Point getPoint();
	//set method
	void setHp(int h);
	//other methods
	void attackHunter(hunter* h);
	void attackPalico(palico* p);
	void checkDead();
	void movePoint();
	


};
#endif