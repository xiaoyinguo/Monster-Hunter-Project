#ifndef Item_h
#define Item_h
#include <string>
using namespace std;

class Item{
private:
	string name;
public:
	Item();
	~Item();
	string getItemName();
	void setItemName(string s);
};


#endif