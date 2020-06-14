#pragma interface
#include <iostream>
#include <map>
#include "Lista.h"
#include "Controlador.h"

class Interfaz{

    public:
        Interfaz();
        ~Interfaz();
        void ejecutar();
    private:
        void mostrar_menu();
        void liberar_memoria();
        bool buscar_lista(std::string);
        void operar_listas(std::string,std::string,char);
        Controlador controlador;
        Lista *referencia; //lista para crear nuevas instancias 
        std::map<std::string,Lista*> listas; //mapa para guardar las listas que se van creando
        std::map<std::string,Lista*>::iterator it;
};