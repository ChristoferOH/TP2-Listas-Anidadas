#pragma lista
#include <iostream>

class Lista{

    public:
        Lista(int,std::string);
        Lista(Lista*,Lista*,std::string);
        ~Lista();
        std::string nombre;
        Lista* add(char,Lista*,Lista*);
        void mostrar_lista();
        Lista* obtener_fragmento(std::string,Lista*);
        Lista* get_head();
        Lista* get_tail();
        bool buscar_valor(int,bool);

    private:
        bool atomico;
        Lista *cabeza;
        Lista *cola;
        int valor;
};