#include <iostream>
#include <string>

using namespace std;

/*
Ejercicio de prueba para el commit y guerdar en repositorio
*/
 
// Interfaz de la clase
    // Clase Base
class Persona{
    private:
        int edad;
        string nombre;

    public:
        Persona(string = "", int = 1);
        void setEdad(int);
        void setNombre(string);
        int getEdad();
        string getNombre();
        virtual ~Persona(){  // destructor de perona, solo se usa en la clase base
            cout << endl << "Destructor de 'Persona'";
        }
};

class Asalariado : public Persona{
    private:
        double sueldo;
    
    public:
        Asalariado(string = "", int = 1, double = 0); // aplicacion de la herencia
        void setSueldo(double);
        double getSueldo();
        ~Asalariado(){
            cout << endl << "Destructor de 'Asalariado'";
        }
};

class Obrero : public Asalariado{
    private:
        string cargo;

    public:
        Obrero(string = "", int = 1, double = 0, string = "Funciones Generales");
        void setCargo(string);
        string getCargo();
        ~Obrero(){
            cout << endl << "Destructor de 'Obrero'";
        }
};

class Medico : public Asalariado{
    private:
        int cantPac;

    public:
        Medico(string = "", int = 1, double = 0, int = 0);
        void setCantPac(int);
        int getCantPac();
        ~Medico(){
            cout << endl << "Destructor de 'Medico'";
        }
};

// Implementaciones de la calse
    // Persona
Persona :: Persona(string nombre, int edad) : nombre(nombre), edad(edad) {}
void Persona :: setEdad(int edad) {
    this->edad=edad;
}
void Persona :: setNombre(string nombre) {
    this->nombre = nombre;
}
int Persona :: getEdad() {
    return this->edad;
}
string Persona :: getNombre() {
    return this->nombre;
}

    // Asalariado
Asalariado :: Asalariado(string nombre, int edad, double sueldo) : Persona(nombre, edad) { // casteo
    cout << endl << "Constructor de 'Asalariado'";
    this->sueldo=sueldo;
}
void Asalariado :: setSueldo(double sueldo) {
    this->sueldo=sueldo;
}
double Asalariado :: getSueldo() {
    return this->sueldo;
}

    //Obrero
Obrero :: Obrero(string nombre, int edad, double sueldo, string cargo) : Asalariado(nombre, edad, sueldo) {
    cout << endl << "Constructor de 'Obrero'";
    this->cargo=cargo;
}
void Obrero :: setCargo(string){
    this->cargo = cargo;
}
string Obrero :: getCargo(){
    return this->cargo;
}

    //Medico
Medico :: Medico(string nombre, int edad, double sueldo, int cantPac) : Asalariado(nombre, edad, sueldo), cantPac(cantPac) {
    cout << endl << "Constructor de 'Medico'";
}
void Medico :: setCantPac(int cantPac) {
    this->cantPac = cantPac;
}
int Medico :: getCantPac() {
    return this->cantPac;
}

//Funciones
    // En este parametro tenemos POLIMORFISMO
void imprimir(Persona *p){
    cout << endl << " - - -";
    Obrero *obr;
    Medico *med;
    string cargo;
    int cantPac;

    /*
            Downcasting
            Consiste en recuperar la instancia de la clase derivada que esta contenida (oculta) en un objeto del tipo de la case Base.
            La razon por la que ae hace downcasting es para tener acceso a toda la funcionalidad de la claseoculta y no solo a lo
            sobreescrito
    */

    cout << endl << " imprimiendo...";

    if(dynamic_cast <Obrero *> (p)){ // se verifica si Persona *p es Obrero
        cout << endl << "La persona es 'Obrero'";
        obr = dynamic_cast <Obrero *> (p);  // downcasting
        cargo = obr->getCargo();
    }else{
        cout << endl << "La persona es 'Medico'";
        med = dynamic_cast <Medico *> (p);  // downcasting
        cantPac = med->getCantPac();
    }

    cout << endl << "Nombre: " << p->getNombre();
    cout << endl << "Edad: " << p->getEdad();
    cout << endl << "Sueldo: " << dynamic_cast <Asalariado *> (p)->getSueldo();
    (dynamic_cast <Obrero *> (p)) ? cout << endl << "Cargo: " << cargo : cout << endl << "Total de pacientes: " << cantPac;
    cout << endl;
}  

int main(){

    {   // bloque de codigo
        cout << endl;
        cout << endl << " - - -";
        Medico medico1("Martin Romo", 19, 1.078, 950);
        cout << endl << " Medico: " << medico1.getNombre();
        cout << endl << " Edad: " << medico1.getEdad();
        cout << endl << " Sueldo: " << medico1.getSueldo();
        cout << endl << " Cantidad de Pacientes: " << medico1.getCantPac();
        cout << endl;
    }

    cout << endl << endl << "Entendiendo que un parametro del tipo de la clase base"
         << endl << "puede recibir cualquier objeto de sus clases derivadas" << endl;

    Obrero *obrero1 = new Obrero("Alfonso Martinez", 20, 19859855, "Maistro");
    imprimir(obrero1);
    cout << endl;

    Medico *medico2 = new Medico("Amelia Martinez", 60, 41259, 8);
    imprimir(medico2);
    cout << endl;
    
    return 0;
}
