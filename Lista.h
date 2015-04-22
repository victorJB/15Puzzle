#include <iostream>
#include "Nodo.h"

using namespace std;

class Lista
{
    private:



    public:

    Nodo * cabeza;
    int **mat;
    int **copia_mat;
    int counter;
    int **configuracionGanadora;
    int **otra;
    Lista();
    void insertarNodoAlFinal();
    void insertarNodoCola();
    void insertarNodoArriba();
    void insertarNodoAbajo();
    void insertarNodoIzquierda();
    void insertarNodoDerecha();
    void verLista();
    int revisarGana();
    int revisarNodosRepetidos();


};

