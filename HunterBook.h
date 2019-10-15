#ifndef HunterBook_h
#define HunterBook_h
#include "hunter.h"
#include <forward_list>
#include <cstring>
using namespace std;

class HunterBook
{
private:
	forward_list<hunter*> bookH;
public:
	HunterBook();
	~HunterBook();
	hunter* getHunter(int i);
	void add();	
	int size();
	void remove(string a, string b);
	void save();	
	void search();
	hunter* get_max(int s);
	void sort(int s);	
	void hunterMove();	
};

#endif 