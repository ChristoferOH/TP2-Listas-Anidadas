#include "Lista.h"

using namespace std;

Lista::Lista(int valor, string nombre){ //constructor de listas atómicas: poseen un valor
    atomico = true; //si es atomico, su valor se muestra, si no, quiere decir que es una lista
    this->valor = valor;
    this->nombre = nombre;
    cabeza = nullptr;
    cola = nullptr;
}

Lista::Lista(Lista* lista1, Lista* lista2, string nombre){ //constructor de listas no atómicas
    atomico = false;
    valor = 0;
    this->nombre = nombre;
    cabeza = lista1;
    cola = lista2;
}

Lista::~Lista(){
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
    Lista *nueva;

    if(posicion == 'h'){
        nueva = new Lista(lista1,lista2,nombre);
    }
    else if(posicion == 't'){
        nueva = new Lista(lista2,lista1,nombre);
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

Lista* Lista::get_head(){
    return cabeza;
}

Lista* Lista::get_tail(){
    return cola;
}

Lista* Lista::obtener_fragmento(string secuencia,Lista *lista){ //editar

    int ultima_pos = secuencia.length()-1;
    Lista *fragmento = lista;
    
    if(ultima_pos >= 0){
        if((secuencia[ultima_pos] == 'h') && (lista->cabeza != nullptr)){
            secuencia.pop_back();
            lista->cabeza->mostrar_lista();
            cout << " cabeza encontrada" << endl;
            fragmento = obtener_fragmento(secuencia,lista->cabeza);
        }
        else if((secuencia[ultima_pos] == 't') && (lista->cola != nullptr)){
            secuencia.pop_back();
            lista->cola->mostrar_lista();
            cout << " cola encontrada" << endl;
            fragmento = obtener_fragmento(secuencia,lista->cola);
        }
        else{
            secuencia.pop_back();
            fragmento = obtener_fragmento(secuencia,lista);
        }
    }
    cout << endl;
    fragmento->mostrar_lista();
    return fragmento;
}

bool Lista::buscar_valor(int valor, bool encontrado){ //editar
    
    if(atomico == false && !encontrado){
        if(cabeza != nullptr){
            encontrado = cabeza->buscar_valor(valor,false);
        }
        if(cola != nullptr){
            encontrado = cola->buscar_valor(valor,false);
        }
    }
    else{
        cout << "He llegado a un valor atómico" << endl;
        if(this->valor != valor){
            cout << "No hay coincidencias" << endl;
        }
        else{
            cout << "Los valores coinciden" <<endl;
            encontrado = true;
        }
    }
    cout << encontrado << endl;
    return encontrado;
}