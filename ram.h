#ifndef RAM_H
#define RAM_H
#include"memoria.h"

class RAM{
	private:
		Memoria *inicio;
		friend RAM Juntar(RAM &);
	public:
		RAM(int size,int idProceso){
			this->inicio= new Memoria(size,idProceso);
		}
		void InsertaProceso(int tamProceso, int idProceso);
		void ElimnarProceso(int idProceso);
		void EstadoMemoria();
};
#endif
