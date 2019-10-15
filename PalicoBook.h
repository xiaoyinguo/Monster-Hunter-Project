#ifndef PalicoBook_h
#define PalicoBook_h
#include "palico.h"
#include <vector>
#include <algorithm>
#include <cstring>
#include "Point.h"
using namespace std;

class PalicoBook
{
private:
	vector<palico*> bookP;
	//h_a=0 if HP sorted, h_a=1 if attack sorted
	int h_a;
public:
	PalicoBook();
	~PalicoBook();
	void add();	
	void change_mode(int hp_attack);
	palico* max(int hp_attack);	
	void remove(string a, string b);
	void save();	
	void search();	
	void palicoMove();
	int size();
	palico* getPalico(int i);
};

#endif