#include "Controlador.h"

using namespace std;

Controlador::Controlador(){

}

Controlador::~Controlador(){

}

int Controlador::validar_entrada(){ //actualmente solo funciona contra strings
    int valor = 0;
    bool error = true;
    do{
        switch (scanf("%d", &valor)) {
            case EOF: printf("Ha ocurrido un error interno.\n"); 
            cin.ignore();
            cin.clear();break;
            case 0: 
                cin.ignore();
                cin.clear(); break;
            default:
                cin.ignore();
                cin.clear();
                error = false; break;
        } 
    }while(error == true);
    return valor;
}