#include <iostream>
#include "Lista.h"

using namespace std;

class CuadroMagico
{
  private:




  public:

    int filas;
    int columnas;
    int **matriz;
    int **checar;
    int **combinacionGanadora;
    Lista listaNodos;
    Lista nodosVisitados;
    Lista direccionInicialNodosVisitados;
    Lista direccionInicialListaNodos;

    CuadroMagico();
    void inicializarTablero(int filas, int columnas);
    void mostrarTablero();
    int determinarLongitudVector(int numero);
    int moverNumeroDerecha(int numero);
    int moverNumeroIzquierda(int numero);
    int moverNumeroAbajo(int numero);
    int moverNumeroArriba(int numero);
    int comprobarGana();
    void revolverTablero();
    void calcularDistanciaManhattan();
    void evaluarMaquina();
    int checarMoverArriba();
    int checarMoverAbajo();
    int checarMoverDerecha();
    int checarMoverIzquierda();
    void verTableroChecar();


};


