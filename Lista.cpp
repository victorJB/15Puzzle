#include <iostream>
#include <cstdlib>
#include "Lista.h"
#include <vector>

using namespace std;

Lista::Lista()
{

    cabeza = NULL;
    mat = NULL;
    copia_mat = NULL;
    counter = 0;
    configuracionGanadora = NULL;

    int i = 0;
    int j = 0;

    mat = new int*[4];

    for(i = 0;i<4;i++)
       {

           mat[i] = new int[4];
    }

    copia_mat = new int*[4];

    for(i = 0;i<4;i++)
       {

           copia_mat[i] = new int[4];
    }


    otra = new int*[4];

    for(i = 0;i<4;i++)
       {

           otra[i] = new int[4];
    }

    configuracionGanadora = new int*[4];

    for(i = 0;i<4;i++)
       {

           configuracionGanadora[i] = new int[4];
    }


    configuracionGanadora[0][0] = 1;
    configuracionGanadora[0][1] = 2;
    configuracionGanadora[0][2] = 3;
    configuracionGanadora[0][3] = 4;
    configuracionGanadora[1][0] = 5;
    configuracionGanadora[1][1] = 6;
    configuracionGanadora[1][2] = 7;
    configuracionGanadora[1][3] = 8;
    configuracionGanadora[2][0] = 9;
    configuracionGanadora[2][1] = 10;
    configuracionGanadora[2][2] = 11;
    configuracionGanadora[2][3] = 12;
    configuracionGanadora[3][0] = 13;
    configuracionGanadora[3][1] = 14;
    configuracionGanadora[3][2] = 15;
    configuracionGanadora[3][3] = 0;

}

void Lista::insertarNodoAlFinal()
{
    Nodo * nuevo;

    nuevo = new Nodo;

    int i = 0;
    int j = 0;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            nuevo->matrix[i][j] = this->copia_mat[i][j];
        }
    }

    nuevo->siguiente = cabeza;

    this->cabeza = nuevo;


}

void Lista::insertarNodoCola()
{
    Nodo * nuevo;

    nuevo = new Nodo;

    int i = 0;
    int j = 0;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            nuevo->matrix[i][j] = this->mat[i][j];
        }
    }

    nuevo->siguiente = cabeza;

    this->cabeza = nuevo;
}

void Lista::insertarNodoArriba()
{
    //cout<<"Nodo que se guardara arriba"<<endl;

    int i = 0;
    int j = 0;
    int encontrado = 0;
    int gana = 0;
    int aux = 0;
    int k = 0;
    int l = 0;


    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            //this->copia_mat[i][j] = this->cabeza->matrix[i][j];
            this->copia_mat[i][j] = this->otra[i][j];
        }
    }

    //cout<<"Matriz que se checara"<<endl;

    /*for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cout<<copia_mat[i][j]<<" ";
        }

        cout<<endl;
    }

    cout<<endl;
*/

        for(i = 0;i<4;i++)
        {
            for(j = 0;j<4;j++)
            {
                if(encontrado == 1)
                {
                    break;
                }

                else if(0 == copia_mat[i][j])
                {
                   encontrado = 1;
                   j--;
                }

            }

            if(encontrado == 1)
                break;
        }


    copia_mat[i][j] = copia_mat[i-1][j];
    copia_mat[i-1][j] = 0;

  /*  for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cout<<copia_mat[i][j]<<" ";
        }

        cout<<endl;
    }

    cout<<endl;
*/
    this->insertarNodoAlFinal();

}

void Lista::insertarNodoAbajo()
{
  //  cout<<"Nodo que se guardara abajo"<<endl;

    int i = 0;
    int j = 0;
    int encontrado = 0;
    int gana = 0;
    int aux = 0;
    int k = 0;
    int l = 0;


    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            //this->copia_mat[i][j] = this->cabeza->matrix[i][j];
            this->copia_mat[i][j] = this->otra[i][j];
        }
    }


        for(i = 0;i<4;i++)
        {
            for(j = 0;j<4;j++)
            {
                if(encontrado == 1)
                {
                    break;
                }

                else if(0 == copia_mat[i][j])
                {
                   encontrado = 1;
                   j--;
                }

            }

            if(encontrado == 1)
                break;
        }


    copia_mat[i][j] = copia_mat[i+1][j];
    copia_mat[i+1][j] = 0;

    /*for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cout<<copia_mat[i][j]<<" ";
        }

        cout<<endl;
    }

    cout<<endl;
*/
    this->insertarNodoAlFinal();
}

void Lista::insertarNodoIzquierda()
{

  //  cout<<"Nodo que se guardara a la izquierda"<<endl;

    int i = 0;
    int j = 0;
    int encontrado = 0;
    int gana = 0;
    int aux = 0;
    int k = 0;
    int l = 0;


    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            //this->copia_mat[i][j] = this->cabeza->matrix[i][j];
            this->copia_mat[i][j] = this->otra[i][j];
        }
    }


        for(i = 0;i<4;i++)
        {
            for(j = 0;j<4;j++)
            {
                if(encontrado == 1)
                {
                    break;
                }

                else if(0 == copia_mat[i][j])
                {
                   encontrado = 1;
                   j--;
                }

            }

            if(encontrado == 1)
                break;
        }


    copia_mat[i][j] = copia_mat[i][j-1];
    copia_mat[i][j-1] = 0;

  /*  for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cout<<copia_mat[i][j]<<" ";
        }

        cout<<endl;
    }

    cout<<endl;
*/
    this->insertarNodoAlFinal();
}

void Lista::insertarNodoDerecha()
{
   // cout<<"Nodo que se guardara a la derecha"<<endl;

    int i = 0;
    int j = 0;
    int encontrado = 0;
    int gana = 0;
    int aux = 0;
    int k = 0;
    int l = 0;


    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            //this->copia_mat[i][j] = this->cabeza->matrix[i][j];
            this->copia_mat[i][j] = this->otra[i][j];
        }
    }


        for(i = 0;i<4;i++)
        {
            for(j = 0;j<4;j++)
            {
                if(encontrado == 1)
                {
                    break;
                }

                else if(0 == copia_mat[i][j])
                {
                   encontrado = 1;
                   j--;
                }

            }

            if(encontrado == 1)
                break;
        }


    copia_mat[i][j] = copia_mat[i][j+1];
    copia_mat[i][j+1] = 0;

   /* for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cout<<copia_mat[i][j]<<" ";
        }

        cout<<endl;
    }*/

    //cout<<endl;

    this->insertarNodoAlFinal();
}

void Lista::verLista()
{
    int contador = 1;
    int i = 0;
    int j = 0;
    int numero = 1;

    //cout<<"Abrir lista"<<endl;

     while(this->cabeza != NULL)
    {

        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
               //cout<<this->cabeza->matrix[i][j]<<" ";
            }

            //cout<<endl;
        }

        //cout<<endl;

        this->cabeza = this->cabeza->siguiente;
        contador = contador+1;
    }

    cout<<endl<<"Nodos Creados: "<<contador<<endl;


}

int Lista::revisarGana()
{
   int i = 0;
   int j = 0;
   int gana = 0; //Sirve para saber si se a alcanzado la solucion del juego 1 Aun no, 0 Ya se alcanzo

   if(this->cabeza != NULL)
   {
       for(i=0;i<4;i++)
       {
           for(j=0;j<4;j++)
           {
               if(this->cabeza->matrix[i][j] != this->configuracionGanadora[i][j])
                   gana = 1;

               if(gana == 1)
                   break;
           }

           if(gana == 1)
               break;
       }
   }

   else
       gana = 1;

   return gana;
}


int Lista::revisarNodosRepetidos()
{
  int i = 0;
  int j = 0;
  int adelante = 0; //Sirve para verificar los nodos repetidos 1 el Nodo no esta repetido, 0 repetido

  if(this->cabeza != NULL)
  {
      while(this->cabeza != NULL)
      {
          adelante = 0;

          for(i=0;i<4;i++)
          {
              for(j=0;j<4;j++)
              {
                  if(this->cabeza->matrix[i][j] != this->mat[i][j])
                  adelante = 1;

                  if(adelante == 1)
                      break;
              }

              if(adelante == 1)
                  break;
          }

          if(adelante == 0)
              break;

          this->cabeza = this->cabeza->siguiente;
      }
  }

  else
      adelante = 1;

  return adelante;
}


