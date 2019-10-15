#ifndef Sword_h
#define Sword_h
#include "Item.h"
class Sword:public Item{
private: 
	int attack;
public:
	Sword();
	~Sword();
	int get_swordAtt();
	void set_swordAtt(int a);
};

#endif 
