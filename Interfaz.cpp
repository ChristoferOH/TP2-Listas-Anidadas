#include "Interfaz.h"

using namespace std;

Interfaz::Interfaz(){
    
}

Interfaz::~Interfaz(){

}

void Interfaz::ejecutar(){
    Controlador controlador;
    Lista *referencia; //lista para crear nuevas instancias 
    map<string,Lista*> listas; //mapa para guardar las listas que se van creando
    map<string,Lista*>::iterator it; 
    int opcion = 0;
    string nombre; //guarda el nombre de una lista a operar
    string lista1; //identificador
    string lista2; //identificador
    int valor; //valor numérico a asignar a una lista 

    do{
        cout << "\n1. Nueva lista atómica" << endl;
        cout << "2. Agregar cabeza a lista" << endl;
        cout << "3. Agregar cola a la lista" << endl;
        cout << "4. Mostrar listas" << endl;
        cout << "5. Eliminar lista" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion: ";
        opcion = controlador.validar_entrada();

        switch(opcion){
            case 1:
                cout << "*** Tenga en cuenta que si repite un nombre, su lista será reemplazada ***" << endl;
                cout << "Nombre de la nueva lista atómica: ";
                cin >> nombre;
                valor = controlador.validar_entrada();
                referencia = new Lista(true, valor,nombre);
                listas[nombre] = referencia;
                break;
            case 2:
                cout << "A qué lista(nombre) le desea agregar una nueva cabeza?" << endl;
                cin >> lista2;
                cout << "Cuál lista(nombre) le desea agregar como cabeza?" << endl;
                cin >> lista1;
                referencia = referencia->add('h',listas[lista1],listas[lista2]);
                listas[referencia->nombre] = referencia;
                break;
            case 3:
                cout << "A qué lista(pos) le desea agregar una nueva cola?" << endl;
                cin >> lista2;
                cout << "Cuál lista(pos) le desea agregar como cola?" << endl;
                cin >> lista1;
                referencia = referencia->add('t',listas[lista1],listas[lista2]);
                listas[referencia->nombre] = referencia;
                break;
            case 4:
                cout << "Listas existentes:" << endl;
                for(it = listas.begin(); it != listas.end(); ++it){
                    cout << (*it).first << ":";
                    (*it).second->mostrar_lista();
                    cout << endl;
                }
                break;
            case 5:
                cout << "Ingrese el nombre de la lista a eliminar: ";
                cin >> nombre;
                listas.erase(nombre);
                break;
        }
    }while(opcion != 6);

    //Liberar memoria reservada
    for(it = listas.begin(); it != listas.end(); ++it){
        delete (*it).second; 
    }
}