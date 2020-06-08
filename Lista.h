#pragma lista
#include <iostream>

class Lista{

    public:
        Lista(bool,int,std::string);
        ~Lista();
        std::string nombre;
        Lista* add(char,Lista*,Lista*);
        void mostrar_lista();

    private:
        bool atomico;
        Lista *cabeza;
        Lista *cola;
        int valor;
};