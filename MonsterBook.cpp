#include "MonsterBook.h"
#include "monster.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
using namespace std;

MonsterBook::MonsterBook()
{
	head=NULL;
	temp=NULL;
	tail=NULL;
}
MonsterBook::~MonsterBook()
{}
monster* MonsterBook::getMonster(int index)
{
	node* temp=head;
	for(int i=0;i<index;i++)
	{
		temp=temp->next;
	}
	return temp->mon;
}
int MonsterBook::size()
{
	int size=0;
	node* ptr=head;
	while(ptr!=NULL)
	{
		size++;
		ptr=ptr->next;
	}
	return size;	
}
void MonsterBook::add()
{
	monster* m=new monster();
	
	temp=new node;
	node* ptr;
	ptr=head;
	temp->mon=m;
	//if first node
	if(tail==NULL)
	{
		head=temp;
		tail=temp;
	}
	//if not first node
	else
	{
		while(ptr!=NULL)
		{
			//if same first name
			if(m->getFirstName()==ptr->mon->getFirstName())
			{
				//last name is further down the alphabet and not last entry
				if (m->getLastName()>ptr->mon->getLastName() && ptr->next != NULL)
				{
					// look at next entry
					ptr=ptr->next;
				}
				//if last name is further down the alphabet and at the last point
				else if (m->getLastName()>ptr->mon->getLastName() && ptr->next == NULL)
				{
					temp->prev=tail;
					tail->next=temp;
					tail=temp;
					break;	
				}
				
				//if last name is the same
				else if (m->getLastName()==ptr->mon->getLastName())
				{
					//if age is greater and not last entry
					if(m->getAge()>ptr->mon->getAge() && ptr->next != NULL)
					{
						ptr=ptr->next;						
					}
					//if age is greater and we've reached the end of the list
					else if(m->getAge()>ptr->mon->getAge() && ptr->next == NULL)
					{
						temp->prev=tail;
						tail->next=temp;
						tail=temp;
						break;					
					}
					//if entry already exists then don't add
					else if(m->getAge()==ptr->mon->getAge())
					{
						break;
					}
					//else if age is smaller insert before ptr
					else
					{
						temp->next=ptr;
						temp->prev=ptr->prev;
						ptr->prev->next=temp;
						ptr->prev=temp;
						break;
					}
				}
				//if last name is closer to front of alphabet, insert monster in front of ptr
				else
				{
					temp->next=ptr;
					temp->prev=ptr->prev;
					ptr->prev->next=temp;
					ptr->prev=temp;
					break;
				}
			}
			//if further down the alphabet and not last entry
			else if(m->getFirstName()>ptr->mon->getFirstName() && ptr->next != NULL)
			{
				ptr=ptr->next;
			}
			//if further down the alphabet and at last entry
			else if(m->getFirstName()>ptr->mon->getFirstName() && ptr->next == NULL)
			{
				temp->prev=tail;
				tail->next=temp;
				tail=temp;
				break;
			}
			//if first name is smaller than insert before ptr
			else 
			{
				temp->next=ptr;
				//if not inserting at the front
				if(ptr->prev!=NULL)
				{
					temp->prev=ptr->prev;
					ptr->prev->next=temp;
				}
				ptr->prev=temp;
				break;
			}
		}
	}
}
void MonsterBook::remove(string a)
{
	string name=a;
	node* ptr=head;
	while(ptr!=NULL)
	{
		if(name==ptr->mon->getFirstName())
		{
			//using code from https://www.geeksforgeeks.org/delete-a-node-in-a-doubly-linked-list/
 			//on how to insert nodes into a dll
  			/* If node to be deleted is head node */
  			if(head == ptr)
  			{	
    			head = ptr->next; 
    		}
			 /* Change next only if node to be deleted is NOT the last node */
  			if(ptr->next != NULL)
  			{	
    			ptr->next->prev = ptr->prev;
 			}
  			/* Change prev only if node to be deleted is NOT the first node */
  			if(ptr->prev != NULL)
  			{	
    			ptr->prev->next = ptr->next;  
    		}	 
			cout<<"contact removed"<<endl;
			//exit loop
			break;	
		}
		else if(ptr==tail)
		{
			cout<<"Contact not found"<<endl;
			ptr=ptr->next;
		}
		else 
		{
			ptr=ptr->next;
		}
	}
}

void MonsterBook::save()
{
	ofstream outFile;
	outFile.open("Monsters.txt");
	node*ptr=head;
	while(ptr!=NULL)
	{   
		outFile<<ptr->mon->getFirstName()<<" "<<ptr->mon->getLastName();
		outFile<<", "<<ptr->mon->getGender()<<", "<<ptr->mon->getAge()<<endl;
		ptr=ptr->next;
	}
	outFile.close();
}
void MonsterBook::search()
{
	char* name;
	cout<<"Enter First Name of the Monster: ";
	cin>>name;
	node* ptr=head;
	while(ptr!=NULL)
	{
		if(name==ptr->mon->getFirstName())
		{
			monster* temp=ptr->mon;   
			cout<<temp->getFirstName()<<" "<<temp->getLastName();
			cout<<", "<<temp->getGender()<<", "<<temp->getAge()<<", "<<endl;
			cout<<"Attack: "<<temp->getAttack()<<endl;
			cout<<", Defense: "<<temp->getDefense()<<endl;
			cout<<", HP: "<<temp->getHp()<<endl;  
			//exit loop
			break;	
		}
		//if last element and no match found
		else if(ptr==tail)
		{
			cout<<"Contact not found"<<endl;
			ptr=ptr->next;
		}
		else 
		{
			ptr=ptr->next;
		}
	}
}

void MonsterBook::monsterMove()
{
	node* ptr=head;
	while(ptr!=NULL)
	{
		ptr->mon->movePoint();
		ptr=ptr->next;
	}
}

