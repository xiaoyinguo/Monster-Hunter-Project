#ifndef MonsterBook_h
#define MonsterBook_h
#include "monster.h"
#include <cstring>
struct node
{
	monster* mon;
	node* next;
	node* prev;
};

class MonsterBook
{
private:
	node* head;
	node* temp;
	node* tail;
public:
	MonsterBook();
	~MonsterBook();
	void add();
	void remove(string a);
	void save();
	void search();
	void monsterMove();
	monster* getMonster(int i);
	int size();
};

#endif 