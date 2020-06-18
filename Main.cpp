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
        Interfaz<int> *interfaz_int = new Interfaz<int>();
        interfaz_int->ejecutar();
        delete interfaz_int;
    }
    else if(opcion == 2){
        Interfaz<double> *interfaz_double = new Interfaz<double>();
        interfaz_double->ejecutar();
        delete interfaz_double;
    }
    else if(opcion == 3){
        Interfaz<string> *interfaz_string = new Interfaz<string>();
        interfaz_string->ejecutar();
        delete interfaz_string;
    }
    else if(opcion == 4){
        Interfaz<char> *interfaz_char = new Interfaz<char>();
        interfaz_char->ejecutar();
        delete interfaz_char;
    }
    return 0;
}