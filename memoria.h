#ifndef MEMORIA_H
#define MEMORIA_H
#include<iostream>

using namespace std; 

class Memoria{
	public:
		int size;
		int idProceso;
		bool libre;
		Memoria *next;
	Memoria(int size, int idProceso){
		this->size=size;
		this->idProceso=idProceso;
		this->libre=true;
		this->next=NULL;
	}
	void setSize(int size){
		this->size=size;
	}
	int getSize(){
		return this->size;
	}
	void setIdProceso(int idProceso){
		this->idProceso=idProceso;
	}
	int getIdProceso(){
		return this->idProceso;
	}

};


#endif
