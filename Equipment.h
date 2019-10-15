#ifndef Equipment_h
#define Equipment_h
#include "Item.h"
class Equipment:public Item{
private:
	int defense;
public:
	Equipment();
	~Equipment();
	int get_equipDef();
	void set_equipDef(int a);
};
#endif 
