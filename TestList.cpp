#include "pch.h"
#include "Lista.h"

Lista<string>* lista1 = new Lista<string>("lista 1", "lista1");
Lista<int>* lista2 = new Lista<int>(77, "lista2");
Lista<int>* lista3 = new Lista<int>(51, "lista3");
Lista<int>* lista4 = new Lista<int>(lista2,lista3, "lista4");

TEST(TipoDeEntrada, stringConEspacios) {
	string valor = "lista 1";
	bool igual = valor.compare(lista1->valor);
	EXPECT_FALSE(igual);
}

TEST(BusquedaDeFragmentos, posicionNoValida) {
	Lista<int>* fragmento = lista2->obtener_fragmento("hhht",lista2);
	EXPECT_EQ(fragmento->valor, lista2->valor);
}

TEST(BuscarValor, valorUnitario) {
	bool encontrado = lista2->buscar_valor(7, false);
	EXPECT_FALSE(encontrado);
}

TEST(ConsultarValor, valorEnListaAnidada) {
	int valor = lista4->valor;
	EXPECT_TRUE(valor < 0);
}

TEST(BuscarValor, valorExistente) {
	bool encontrado = lista4->buscar_valor(51, false);
	EXPECT_TRUE(encontrado);
}

TEST(ManipularListas, eliminarListaContenidaEnOtra) {
	delete lista3;
	bool sigue_existiendo = lista4->buscar_valor(51, false);
	EXPECT_FALSE(sigue_existiendo);
}
