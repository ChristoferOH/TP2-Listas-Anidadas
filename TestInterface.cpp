#include "pch.h"
#include "Interfaz.h"

Interfaz<int>* interfaz = new Interfaz<int>();


TEST(OperarListas, crearListaAtomica) {
	interfaz->prueba_crear(30);
	int cantidad_listas = interfaz->listas.size();
	bool existe_una = cantidad_listas == 1;
	EXPECT_TRUE(existe_una);
}

TEST(OperarListas, insertarNoValida) {
	interfaz->operar_listas("lista1", "lista2", 't');
	int cantidad_listas = interfaz->listas.size();
	bool no_se_creo_nueva = cantidad_listas == 1;
	EXPECT_TRUE(no_se_creo_nueva);
}

TEST(OperarListas, buscarLista) {
	interfaz->prueba_crear(51);
	bool encontrada = interfaz->buscar_lista(interfaz->nombre);
	EXPECT_TRUE(encontrada);
}

TEST(OperarListas, insertarValida) {
	interfaz->prueba_crear(99);
	interfaz->operar_listas(interfaz->nombre, interfaz->nombre, 'h');
	int cantidad_listas = interfaz->listas.size();
	bool aumento_cant = cantidad_listas == 2;
	EXPECT_TRUE(aumento_cant);
}