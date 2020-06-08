#include "Lista.h"

using namespace std;

Lista::Lista(bool es_atomico, int valor, string nombre){
    atomico = es_atomico; //si es atomico, su valor se muestra, si no, quiere decir que es una lista
    this->valor = valor;
    this->nombre = nombre;
    cabeza = nullptr;
    cola = nullptr;
}

Lista::~Lista(){
    //cout << "destructor" << endl;
    if(atomico == true){
        if(cabeza){
            delete cabeza;
        }
        if(cola){
            delete cola;
        }
    }
}
/*
@brief Para no alterar el orden de los parámetros, se decide utilizar un char como selector.
Siempre va a ser lista1 la que se va a agregar en la posicion deseada.
@param posicion: selector para agregar a cabeza o cola. h para cabeza y t para cola.
@param *lista1: la lista a agregar en la posición seleccionada.
@param *lista2: la lista a la que se le va a añadir lista1.
*/
Lista* Lista::add(char posicion, Lista *lista1, Lista *lista2){
    string nombre;
    cout << "Ingrese el nombre de su nueva lista: ";
    cin >> nombre;
    Lista *nueva = new Lista(false,0,nombre);

    if(posicion == 'h'){
        nueva->cabeza = lista1;
        nueva->cola = lista2;
    }
    else if(posicion == 't'){
        nueva->cabeza = lista2;
        nueva->cola = lista1;
    }
    return nueva;
}

void Lista::mostrar_lista(){
    if(atomico == false){
        if(cabeza != nullptr){
            cout << "(";
            cabeza->mostrar_lista();
            cout << " ";
        }
        if(cola != nullptr){
            cola->mostrar_lista();
            cout << ")";
        }
    }
    else{
        cout << valor;
    }
}