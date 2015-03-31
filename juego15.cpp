#include "juego15.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>

CuadroMagico::CuadroMagico()
{
  filas = 0;
  columnas = 0;
  matriz = NULL;
}

void CuadroMagico::inicializarTablero(int filas, int columnas)
{
    int i = 0;
    int j = 0;
    int contador = 1;

    this->filas = filas;
    this->columnas = columnas;
    this->matriz = new int* [filas];

    for(i=0;i<filas;i++)
    {
        this->matriz[i] = new int [columnas];
    }

    for(i = 0;i<this->filas;i++)
    {
        for(j = 0;j<this->columnas;j++)
        {
            matriz[i][j] = contador;
            contador++;

        }
    }

    matriz[0][3] = 0;
    matriz[3][3] = 4;

    this->mostrarTablero();
}

void CuadroMagico::mostrarTablero()
{
    int i = 0;
    int j = 0;
    int res = 0;

    cout<<endl;

    for(i=0;i<this->filas;i++)
    {
        for(j=0;j<this->columnas;j++)
        {
            res = this->determinarLongitudVector(matriz[i][j]);

            if(res == 2)
            {
                cout<<this->matriz[i][j]<<" ";
            }

            else
                cout<<" "<<this->matriz[i][j]<<" ";

        }

        cout<<endl;
    }

    cout<<endl;

}

int CuadroMagico::determinarLongitudVector(int numero)
{
    vector <char> cadena;
    char arreglo[2];
    itoa(numero,arreglo,10);
    unsigned int resultado = 0;

    resultado = char_traits<char>::length(arreglo);

    return resultado;
}

int CuadroMagico::moverNumeroDerecha(int numero)
{
    int i = 0;
    int j = 0;
    int encontrado = 0;
    int gana = 0;


    if(numero == 0)
       {
         encontrado = 1;
         j = 10;
         i = 10;
       }

    else
    {
        for(i = 0;i<this->filas;i++)
        {
            for(j = 0;j<this->columnas;j++)
            {
                if(encontrado == 1)
                {

                    break;
                }

                else if(numero == matriz[i][j])
                {
                   encontrado = 1;
                   //cout<<"Numero encontrado"<<"  renglon = "<<i+1<<"  columna = "<<j+1<<endl;
                   j--;
                }

            }

            if(encontrado == 1)
                break;
        }
    }

    if(encontrado == 1)
    {
        if(j<3)
        {
            if(matriz[i][j+1] == 0)
            {
                matriz[i][j+1] = matriz[i][j];
                matriz[i][j] = 0;
                cout<<"Movimiento Ejecutado correctamente"<<endl;

            }

            else
                cout<<"Movimiento Invalido"<<endl;
        }

        else
           {
             cout<<"Movimiento Invalido"<<endl;
           }

    }

    else
    {
        cout<<"Dato no encontrado"<<endl;
    }

    this->mostrarTablero();
    gana = this->comprobarGana();
    return gana;
}

int CuadroMagico::moverNumeroIzquierda(int numero)
{
    int i = 0;
    int j = 0;
    int encontrado = 0;
    int gana = 0;

    if(numero == 0)
       {
         encontrado = 1;
         j = -10;
         i = -10;
       }

    else
    {
        for(i = 0;i<this->filas;i++)
        {
            for(j = 0;j<this->columnas;j++)
            {
                if(encontrado == 1)
                {
                    break;
                }

                else if(numero == matriz[i][j])
                {
                   encontrado = 1;
                   //cout<<"Numero encontrado"<<"  renglon = "<<i+1<<"  columna = "<<j+1<<endl;
                   j--;
                }

            }

            if(encontrado == 1)
                break;
        }
    }


    if(encontrado == 1)
    {
        if(j>0)
        {
            if(matriz[i][j-1] == 0)
            {
                matriz[i][j-1] = matriz[i][j];
                matriz[i][j] = 0;
                cout<<"Movimiento Ejecutado correctamente"<<endl;
            }

            else
            {
                cout<<"Movimiento Invalido"<<endl;
            }
        }

        else
           {
             cout<<"Movimiento Invalido"<<endl;
           }
    }

    else
    {
        cout<<"Dato no encontrado"<<endl;
    }

    this->mostrarTablero();
    gana = this->comprobarGana();
    return gana;
}


int CuadroMagico::moverNumeroAbajo(int numero)
{
    int i = 0;
    int j = 0;
    int encontrado = 0;
    int gana = 0;

    if(numero == 0)
       {
         encontrado = 1;
         j = 10;
         i = 10;
       }

    else
    {
        for(i = 0;i<this->filas;i++)
        {
            for(j = 0;j<this->columnas;j++)
            {
                if(encontrado == 1)
                {

                    break;
                }

                else if(numero == matriz[i][j])
                {
                   encontrado = 1;
                   //cout<<"Numero encontrado"<<"  renglon = "<<i+1<<"  columna = "<<j+1<<endl;
                   j--;
                }

            }

            if(encontrado == 1)
                break;
        }
    }

    if(encontrado == 1)
    {
        if(i<3)
        {
            if(matriz[i+1][j] == 0)
            {
                matriz[i+1][j] = matriz[i][j];
                matriz[i][j] = 0;
                cout<<"Movimiento Ejecutado correctamente"<<endl;

            }

            else
                cout<<"Movimiento Invalido"<<endl;
        }

        else
           {
             cout<<"Movimiento Invalido"<<endl;
           }

    }

    else
    {
        cout<<"Dato no encontrado"<<endl;
    }

    this->mostrarTablero();
    gana = this->comprobarGana();
    return gana;
}

int CuadroMagico::moverNumeroArriba(int numero)
{
    int i = 0;
    int j = 0;
    int encontrado = 0;
    int gana = 0;

    if(numero == 0)
       {
         encontrado = 1;
         j = -10;
         i = -10;
       }

    else
    {
        for(i = 0;i<this->filas;i++)
        {
            for(j = 0;j<this->columnas;j++)
            {
                if(encontrado == 1)
                {
                    break;
                }

                else if(numero == matriz[i][j])
                {
                   encontrado = 1;
                   //cout<<"Numero encontrado"<<"  renglon = "<<i+1<<"  columna = "<<j+1<<endl;
                   j--;
                }

            }

            if(encontrado == 1)
                break;
        }
    }


    if(encontrado == 1)
    {
        if(i>0)
        {
            if(matriz[i-1][j] == 0)
            {
                matriz[i-1][j] = matriz[i][j];
                matriz[i][j] = 0;
                cout<<"Movimiento Ejecutado correctamente"<<endl;
            }

            else
            {
                cout<<"Movimiento Invalido"<<endl;
            }
        }

        else
           {
             cout<<"Movimiento Invalido"<<endl;
           }
    }

    else
    {
        cout<<"Dato no encontrado"<<endl;
    }

    this->mostrarTablero();

    gana = this->comprobarGana();
    return gana;
}

int CuadroMagico::comprobarGana()
{
    int i = 0;
    int j = 0;
    int contador = 1;
    int gana = 1;

    for(i = 0;i<this->filas;i++)
    {
        for(j = 0;j<this->columnas;j++)
        {
            if(matriz[i][j] != contador)
            {
                gana = 0;
                break;
            }

            else
                contador++;
        }

        if(gana == 0)
        break;

    }

    if(gana == 0 && contador == 16)
        gana = 1;

    return gana;
}


