#include "Controlador.h"

using namespace std;

Controlador::Controlador(){

}

Controlador::~Controlador(){

}

int Controlador::validar_entrada(){ //actualmente solo funciona contra strings
    int valor = 0;
    bool error;
    do{
        cout << "Valor a asignar: ";
        error = false;
        if(!(cin>>valor)){
            error = true;
            cout << "Tipo de dato diferente a int no aceptado" << endl;
            cin.clear();
            cin.ignore();
        }
    }while(error);
    return valor;
}