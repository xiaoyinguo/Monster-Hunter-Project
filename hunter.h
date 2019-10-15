#ifndef hunter_h
#define hunter_h
#include <cstring>
#include "Sword.h"
#include "Equipment.h"
#include "Point.h"
using namespace std;


class monster;
class hunter
{
private:
	int energy;
	int hp;
	int attack;
	int defense;
	bool defend;
	string lastName;
	string firstName;
	string gender;
	int age;
	Sword sword;
	Equipment equip;
	char color[3];
	Point coordinate;
	monster* mon;
public:
	//constructor
	hunter();
	~hunter();
	//get methods
	int getHp() const;
	int getEnergy() const;
	int getAttack() const;
	int getDefense() const;
	int getEquipDefense();
	string getEquipName();
	string getSwordName();
	int getSwordAttack();
	string getFirstName();
	string getLastName();
	string getGender();
	int getAge();
	bool getDefend();
	Point getPoint();
	char* getColor();
	//set methods
	void setHp(int h);
	void setEnergy(int e);
	//other methods
	void attackMonsters(monster *m);
	void defendMonsters();
	void checkDead();
	void movePoint();
	
};

#endif