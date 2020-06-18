#include "Interfaz.h"
#include <iostream>

using namespace std;

int main(){
    int opcion = 0;
    do{
        cout << "\n*** Escoja un tipo de dato para trabajar con las listas ***" << endl;
        cout << "1. Lista int" << endl;
        cout << "2. Lista double" << endl;
        cout << "3. Lista string" << endl;
        cout << "4. Lista char" << endl;
        cout << "Opción: ";
        cin >> opcion;
    }while(opcion < 1 || opcion > 4);
    
    
    if(opcion == 1){
        Interfaz<int> *interfaz = new Interfaz<int>();
        interfaz->ejecutar();
    }
    else if(opcion == 2){
        Interfaz<double> *interfaz = new Interfaz<double>();
        interfaz->ejecutar();
    }
    else if(opcion == 3){
        Interfaz<string> *interfaz = new Interfaz<string>();
        interfaz->ejecutar();
    }
    else if(opcion == 4){
        Interfaz<char> *interfaz = new Interfaz<char>();
        interfaz->ejecutar();
    }
    return 0;
}