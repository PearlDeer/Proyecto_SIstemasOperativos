#include"memoria.h"
#include"ram.h"
#include <iostream>
#include<math.h>

using namespace std;

void RAM::InsertaProceso(int tamProceso, int idProceso){
	Memoria *bloque=inicio;
	int tamRequerido;
	bool flag=false;
	tamRequerido=pow(2,ceil(log2(tamProceso)));
	if(tamRequerido<32){
		tamRequerido=32;
	}
	while(bloque!=NULL){
		if(bloque->libre==true&&bloque->size>=tamRequerido){
			while(bloque->size>=tamRequerido*2&&bloque->size>32){
				Memoria *nuevoBloque= new Memoria(bloque->size/2,-1);
				nuevoBloque->next=bloque->next;
				bloque->next=nuevoBloque;
				bloque->size=bloque->size/2;
			}
			flag=true;
			bloque->libre=false;
			bloque->idProceso=idProceso;
			cout<<"El proceso: "<<idProceso<<" se encuentra en un bloque de espacio "<<bloque->getSize()<<" KB"<<endl;
			goto salida;
		}
		bloque=bloque->next;
	}
	if(flag==false){
		cout<<"El proceso: "<<idProceso<<" no se puedo insertar en Memoria"<<endl;
	}
	salida:
		cout<<"";
}
void RAM::ElimnarProceso(int idProceso){
	Memoria *bloqueALiberar=inicio;
	bool flag=true;
	while(bloqueALiberar->idProceso!=idProceso && flag==true){
		if(bloqueALiberar->next!=NULL){
			bloqueALiberar=bloqueALiberar->next;
		}
		else{
			flag=false;
		}
	}
	if(flag==true){
		bloqueALiberar->libre=true;
		bloqueALiberar->idProceso=-1;
	}
}

RAM Juntar(RAM &obj1){
	Memoria *bloque=obj1.inicio;
	Memoria *bloqueSiguiente;
	
	while(bloque!=NULL){
			bloqueSiguiente=bloque->next;
		while(bloqueSiguiente!=NULL&&bloque->libre==true&&bloqueSiguiente->libre==true&&bloque->size==bloqueSiguiente->size){
			bloque->size=bloque->size*2;
			bloque->next=bloqueSiguiente->next;
			bloqueSiguiente=bloque->next;
			obj1=Juntar(obj1);
		}
		bloque=bloque->next;	
	}
	return obj1;
}

void RAM::EstadoMemoria(){
	Memoria *bloque=inicio;
	while(bloque!=NULL){
		cout<<"[";
		if(bloque->idProceso>0){
			cout<<bloque->idProceso;
		}
		else{
			cout<<"0";
		}
		cout<<","<<bloque->getSize()<<",";
		(bloque->libre) ? cout<<"0": cout<<"1 ";
		cout<<"]"<<" ";
		/*cout<<"Tama"<<char(164)<<"o del bloque: "<<bloque->getSize()<<" KB"<<endl;
		if(bloque->libre==false){
			cout<<"Ocupado por el proceso: "<<bloque->getIdProceso()<<endl;
		}
		else{
			cout<<"Espacio Libre"<<endl;
		}*/
		bloque=bloque->next;
	}
}
