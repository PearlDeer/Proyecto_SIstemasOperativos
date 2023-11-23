#include"memoriac.cpp"
#include<iostream>

using namespace std;

int main(){
	RAM MemoriaPrincipal(1024,-1);
	MemoriaPrincipal.InsertaProceso(64,1);
	MemoriaPrincipal.InsertaProceso(512,2);
	MemoriaPrincipal.InsertaProceso(16,3);
	MemoriaPrincipal.EstadoMemoria();
	cout<<endl<<"bajando de memoria Procesos 1 y 3"<<endl;
	MemoriaPrincipal.ElimnarProceso(1);
	MemoriaPrincipal.ElimnarProceso(3);
	MemoriaPrincipal=Juntar(MemoriaPrincipal);
	MemoriaPrincipal.EstadoMemoria();
}

