/**
 * @file Lista.cpp
 * @brief Clase Lista que se encarga de crear listas y operar sobre ellas
 * @author Christofer Obregón
 * @date 16 de junio,2020
 */

#include "Lista.h"

using namespace std;

/**
 * @brief Constructor de una lista atómica, con un valor entero y un nombre
 * @param valor valor entero a asignar a la lista atómica
 * @param nombre nombre a asignar a la lista
 */
Lista::Lista(int valor, string nombre){
    atomico = true;
    this->valor = valor;
    this->nombre = nombre;
    cabeza = nullptr;
    cola = nullptr;
}

/**
 * @brief Constructor de una lista a partir de dos lista ya existentes
 * @param lista1 primera lista de referencia para construir una nueva
 * @param lista2 segunda lista de referencia para construir una nueva
 * @param nombre nombre a asignar a la lista
 */
Lista::Lista(Lista* lista1, Lista* lista2, string nombre){
    atomico = false;
    valor = 0; //por defecto se le asigna un 0, sin embargo, no se toma en cuenta
    this->nombre = nombre;
    cabeza = lista1;
    cola = lista2;
}

/**
 * @brief Constructor de una lista a partir de otra ya existente
 * @param lista lista de referencia que se utilizará para crear una nueva
 */
Lista::Lista(Lista* lista){
    atomico = lista->atomico;
    valor = lista->valor;
    nombre = lista->nombre;
    cabeza = lista->cabeza;
    cola = lista->cola;
}

Lista::~Lista(){
    if(atomico == true){
        if(cabeza){
            delete cabeza;
        }
        else if(cola){
            delete cola;
        }
    }
}
/**
 * @brief Funciona como operador de listas, agrega cabezas o colas de acuerdo a lo que se le indique
 * @param posicion selector para agregar a cabeza o cola, h para cabeza y t para cola
 * @param lista1 lista a agregar en la posición seleccionada (cabeza o cola)
 * @param lista2 lista a la que se le va a agregar lista1
 * @returns Una nueva lista operada
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

/**
 * @brief Muestra la lista en pantalla
 */
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

/**
 * @brief Obtiene la cabeza de una lista
 */
Lista* Lista::get_head(){
    return cabeza;
}

/**
 * @brief Obtiene la cola de una lista
 */
Lista* Lista::get_tail(){
    return cola;
}

/**
 * @brief Obtiene un fragmento de la lista indicada de manera recursiva
 * @param secuencia la cadena de posiciones que debe seguir y encontrar, lee de atrás hacia adelante
 * @param lista lista sobre la cual operará
 * @returns Una nueva lista que contiene el fragmento encontrado, si no encuentra nada, devuelve la lista inicial
 */
Lista* Lista::obtener_fragmento(string secuencia,Lista *lista){

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
            cout << "Posición no corresponde" << endl;
            secuencia.pop_back();
            fragmento = obtener_fragmento(secuencia,lista);
        }
    }
    return fragmento;
}

/**
 * @brief Busca un valor entero de forma recursiva en la lista
 * @param valor valor a buscar
 * @param encontrado por defecto se debe establecer en false, si se encuentra el valor, este cambia a true
 * @returns Un bool si se encontró o no el valor
 */
bool Lista::buscar_valor(int valor, bool encontrado){
    
    if(!atomico && !encontrado){
        if(cabeza){
            encontrado = cabeza->buscar_valor(valor,encontrado);
        }
        if(cola){
            encontrado = cola->buscar_valor(valor, encontrado);
        }
    }
    else{
        if(this->valor == valor){
            encontrado = true;
        }
        else{
        }
    }
    return encontrado;
}