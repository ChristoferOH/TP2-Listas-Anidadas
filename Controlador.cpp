/**
 * @file Controlador.cpp
 * @brief Clase Controlador que se encarga de validar entradas de datos
 * @author Christofer Obregón
 * @date 16 de junio,2020
 */

#include "Controlador.h"

using namespace std;

Controlador::Controlador(){

}

Controlador::~Controlador(){

}

int Controlador::validar_entrada(){ //actualmente solo funciona contra strings
    int valor = 0;
    bool error = true;
    //recuperado de: https://es.stackoverflow.com/questions/165106/validar-entrada-tipos-de-datos
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