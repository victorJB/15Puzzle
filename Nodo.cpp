#include <iostream>
#include "Nodo.h"
#include <cstdlib>

using namespace std;



Nodo::Nodo()
{
    identificador = 0;
    estado = 0;
    matrix = NULL;
    siguiente = NULL;
    ultimo = NULL;
    manhattan = 0;

    int i = 0;

    matrix = new int*[4];

    for(i = 0;i<4;i++)
       {

           matrix[i] = new int[4];
    }

}






