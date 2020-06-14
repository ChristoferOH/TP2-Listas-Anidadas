#include "Interfaz.h"

using namespace std;

Interfaz::Interfaz(){
    
}

Interfaz::~Interfaz(){

}

void Interfaz::ejecutar(){
     
    int opcion = 0;
    string nombre; //guarda el nombre de una lista a operar
    string secuencia; //secuencia de caracteres a seguir para llamados recursivos de colas y cabezas
    string lista1; //identificador
    string lista2; //identificador
    int valor; //valor numérico a asignar a una lista 

    do{
        mostrar_menu();
        cout << "Opcion: ";
        opcion = controlador.validar_entrada();

        switch(opcion){
            case 1:
                cout << "*** Tenga en cuenta que si repite un nombre, su lista será reemplazada ***" << endl;
                cout << "Nombre de la nueva lista atómica: ";
                cin >> nombre;
                cout << "Valor a asignar: ";
                valor = controlador.validar_entrada();
                referencia = new Lista(valor,nombre);
                listas[nombre] = referencia;
                break;
            case 2:
                cout << "A qué lista(nombre) le desea agregar una nueva cabeza?" << endl;
                cin >> lista2;
                cout << "Cuál lista(nombre) le desea agregar como cabeza?" << endl;
                cin >> lista1;
                operar_listas(lista1,lista2,'h');           
                break;
            case 3:
                cout << "A qué lista(pos) le desea agregar una nueva cola?" << endl;
                cin >> lista2;
                cout << "Cuál lista(pos) le desea agregar como cola?" << endl;
                cin >> lista1;
                operar_listas(lista1,lista2,'t');
                break;
            case 4:
                cout << "Puede obtener un fragmento de alguna lista de la siguiente manera:" << endl;
                cout << "Ingrese una h para obtener la cabeza y una t para la cola" << endl;
                cout << "Ejemplo: hthh -> la cabeza de la cabeza, de la cola de la cabeza" << endl;
                cout << "\nIngrese el nombre de la lista: ";
                cin >> nombre;
                if(buscar_lista(nombre)){
                    cout << "Ingrese la secuencia que desea buscar: ";
                    cin >> secuencia;
                    referencia = referencia->obtener_fragmento(secuencia,listas[nombre]);
                    cout << "\nDesea crear una nueva lista a partir del fragmento obtenido? s/n" << endl;
                    char respuesta;
                    cin >> respuesta;
                    if(respuesta == 's'){
                        cout << "Nombre de su nueva lista: ";
                        cin >> nombre;
                        referencia = new Lista(referencia->get_head(),referencia->get_tail(),nombre);
                        listas[nombre] = referencia;
                    }
                }
                else{
                    cout << "Lista no existe" << endl;
                }
                break;
            case 5:
                cout << "Listas existentes:" << endl;
                for(it = listas.begin(); it != listas.end(); ++it){
                    cout << (*it).first << ":";
                    (*it).second->mostrar_lista();
                    cout << endl;
                }
                break;
            case 6:
                cout << "Ingrese el nombre de la lista a eliminar: ";
                cin >> nombre;
                listas.erase(nombre);
                break;
            case 7:
                cout << "Ingrese el nombre de la lista a consultar: ";
                cin >> nombre;
                cout << "Ingrese el valor que desea buscar: ";
                cin >> valor;
                if(buscar_lista(nombre)){
                    if(listas[nombre]->buscar_valor(valor,false)){
                        cout << valor << " existe en " << nombre << endl;
                    }
                    else{
                        cout << valor << " no ha sido encontrado en " << nombre << endl;
                    }
                }
                else{
                    cout << "Lista consultada no existe" << endl;
                }
                break;
        }
    }while(opcion != 8);
    liberar_memoria();
}

void Interfaz::mostrar_menu(){
    cout << "\n1. Nueva lista atómica" << endl;
    cout << "2. Agregar cabeza a lista" << endl;
    cout << "3. Agregar cola a la lista" << endl;
    cout << "4. Obtener fragmento de lista" << endl;
    cout << "5. Mostrar listas" << endl;
    cout << "6. Eliminar lista" << endl;
    cout << "7. Buscar valor en una lista" << endl;
    cout << "8. Salir" << endl;
}

void Interfaz::liberar_memoria(){
    for(it = listas.begin(); it != listas.end(); ++it){
        cout << "Deleted" << endl;
        delete (*it).second; 
    }
}

bool Interfaz::buscar_lista(string nombre){
    bool encontrada = false;
    it = listas.find(nombre);
    if(it != listas.end()){
        encontrada = true;
    }
    return encontrada;
}

void Interfaz::operar_listas(string lista1, string lista2, char pos){
    if(buscar_lista(lista1) && buscar_lista(lista2)){
        referencia = referencia->add(pos,listas[lista1],listas[lista2]);
        listas[referencia->nombre] = referencia;
    }
    else{
        cout << "Las referencias a las listas no fueron correctas" << endl;
    }     
}