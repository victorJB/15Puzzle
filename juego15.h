#include <iostream>

using namespace std;

class CuadroMagico
{
  private:

    int filas;
    int columnas;
    int **matriz;


  public:

    CuadroMagico();
    void inicializarTablero(int filas, int columnas);
    void mostrarTablero();
    int determinarLongitudVector(int numero);
    int moverNumeroDerecha(int numero);
    int moverNumeroIzquierda(int numero);
    int moverNumeroAbajo(int numero);
    int moverNumeroArriba(int numero);
    int comprobarGana();

};
