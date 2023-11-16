#ifndef MEMORIA_H
#define MEMORIA_H
#include<iostream>
class Memoria{
	private:
		int size;
		bool libre;
		Memoria *next;
	public:
	Memoria(int size){
		this->size=size;
		this->libre=true;
		this->next=NULL;
	}
	void setSize(int size){
		this->size=size;
	}
	int getSize(){
		return this->size;
	}
};



#endif
