#include "juego15.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime>
#include <conio.h>
#include <time.h>

CuadroMagico::CuadroMagico()
{
  int i = 0;
  filas = 0;
  columnas = 0;
  matriz = NULL;
  checar = NULL;
  combinacionGanadora = NULL;

  this->checar = new int* [4];

  for(i=0;i<4;i++)
  {
      this->checar[i] = new int [4];
  }

  this->combinacionGanadora = new int* [4];

  for(i=0;i<4;i++)
  {
      this->combinacionGanadora[i] = new int [4];
  }

  combinacionGanadora[0][0] = 1;
  combinacionGanadora[0][1] = 2;
  combinacionGanadora[0][2] = 3;
  combinacionGanadora[0][3] = 4;
  combinacionGanadora[1][0] = 5;
  combinacionGanadora[1][1] = 6;
  combinacionGanadora[1][2] = 7;
  combinacionGanadora[1][3] = 8;
  combinacionGanadora[2][0] = 9;
  combinacionGanadora[2][1] = 10;
  combinacionGanadora[2][2] = 11;
  combinacionGanadora[2][3] = 12;
  combinacionGanadora[3][0] = 13;
  combinacionGanadora[3][1] = 14;
  combinacionGanadora[3][2] = 15;
  combinacionGanadora[3][3] = 0;


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


    matriz[0][0] = 3;
    matriz[0][1] = 7;
    matriz[0][2] = 9;
    matriz[0][3] = 4;
    matriz[1][0] = 5;
    matriz[1][1] = 0;
    matriz[1][2] = 11;
    matriz[1][3] = 8;
    matriz[2][0] = 1;
    matriz[2][1] = 2;
    matriz[2][2] = 10;
    matriz[2][3] = 14;
    matriz[3][0] = 13;
    matriz[3][1] = 6;
    matriz[3][2] = 15;
    matriz[3][3] = 12;

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

    this->calcularDistanciaManhattan();

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
                   ////cout<<"Numero encontrado"<<"  renglon = "<<i+1<<"  columna = "<<j+1<<endl;
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
                //cout<<"Movimiento Ejecutado correctamente"<<endl;

            }

            //else
                //cout<<"Movimiento Invalido"<<endl;
        }

        else
           {
             //cout<<"Movimiento Invalido"<<endl;
           }

    }

    else
    {
        //cout<<"Dato no encontrado"<<endl;
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
                   ////cout<<"Numero encontrado"<<"  renglon = "<<i+1<<"  columna = "<<j+1<<endl;
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
                //cout<<"Movimiento Ejecutado correctamente"<<endl;
            }

            else
            {
                //cout<<"Movimiento Invalido"<<endl;
            }
        }

        else
           {
             //cout<<"Movimiento Invalido"<<endl;
           }
    }

    else
    {
        //cout<<"Dato no encontrado"<<endl;
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
                   ////cout<<"Numero encontrado"<<"  renglon = "<<i+1<<"  columna = "<<j+1<<endl;
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
                //cout<<"Movimiento Ejecutado correctamente"<<endl;

            }

            //else
                //cout<<"Movimiento Invalido"<<endl;
        }

        else
           {
             //cout<<"Movimiento Invalido"<<endl;
           }

    }

    else
    {
        //cout<<"Dato no encontrado"<<endl;
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
                   ////cout<<"Numero encontrado"<<"  renglon = "<<i+1<<"  columna = "<<j+1<<endl;
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
                //cout<<"Movimiento Ejecutado correctamente"<<endl;
            }

            else
            {
                //cout<<"Movimiento Invalido"<<endl;
            }
        }

        else
           {
             //cout<<"Movimiento Invalido"<<endl;
           }
    }

    else
    {
        //cout<<"Dato no encontrado"<<endl;
    }

    this->mostrarTablero();

    gana = this->comprobarGana();
    return gana;
}

int CuadroMagico::comprobarGana()
{
    int i = 0;
    int j = 0;
    int gana = 1;

    for(i = 0;i<this->filas;i++)
    {
        for(j = 0;j<this->columnas;j++)
        {
            if(matriz[i][j] != combinacionGanadora[i][j])
            {
                gana = 0;
                break;
            }

        }

        if(gana == 0)
        break;

    }

    return gana;
}

void CuadroMagico::revolverTablero()
{
    srand(time(0));

}

void CuadroMagico::calcularDistanciaManhattan()
{
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int dManhattan = 0;
    int encontrado = 0;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {

            for(k=0;k<4;k++)
            {
                for(l=0;l<4;l++)
                {
                   if(matriz[i][j]==combinacionGanadora[k][l])
                   {
                       encontrado = 1;
                       dManhattan = dManhattan+(abs(i-k)+abs(j-l));
                       break;
                   }

                }

                if(encontrado == 1)
                {
                    encontrado = 0;
                    break;
                }


            }

        }
    }

    //cout<<"Distancia Manhattan = "<<dManhattan<<endl<<endl;

}

void CuadroMagico::evaluarMaquina()
{


    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
    printf("%s\n",output);

   int tecla = 0;
   int i = 0;
   int j = 0;
   int k = 0;
   int h = 0;
   int p1 = 0;
   int p2 = 0;
   int aux = 0;
   int gana = 0;
   int d_arriba = 0; //Nuevo Nodo evaluado distancia Manhattan arriba
   int d_abajo = 0; //Nuevo Nodo evaluado distancia Manhattan abajo
   int d_izquierda = 0; //Nuevo Nodo evaluado distancia Manhattan izquierda
   int d_derecha = 0; //Nuevo Nodo evaluado distancia Manhattan derecha
   int coordenadas[4];
   int up = 0;
   int right = 0;
   int left = 0;
   int inserto = 1;
   int check = 0;
   int down = 0;
   int bien = 1; //Sirve para saber si se a alcanzado la solucion del juego 1 Aun no, 0 Ya se alcanzo
   int adelante = 0; //Sirve para verificar los nodos repetidos 1 el Nodo no esta repetido, 0 repetido

   //Cargando configuracion Inicial

   for(i=0;i<this->filas;i++)
   {
       for(j=0;j<this->columnas;j++)
       {
           this->listaNodos.mat[i][j] = this->matriz[i][j];
           this->listaNodos.copia_mat[i][j] = this->matriz[i][j];
       }
   }


   this->listaNodos.insertarNodoAlFinal();

//Cambiar apartir de aqui


   while(bien == 1)
   {


       bien = this->listaNodos.revisarGana();

//      cin>>tecla;

       if(bien == 1)
       {
           adelante = 0;
           check = 0;

           this->direccionInicialListaNodos.cabeza = this->listaNodos.cabeza;

           while(adelante == 0)
           {
                 // cout<<"Nodo a evaluar"<<endl<<endl;





                   for(i=0;i<4;i++)
                   {
                       for(j=0;j<4;j++)
                       {
                           this->matriz[i][j] = this->listaNodos.cabeza->matrix[i][j];
                           this->listaNodos.copia_mat[i][j] = this->listaNodos.cabeza->matrix[i][j];
                           this->listaNodos.mat[i][j] = this->listaNodos.cabeza->matrix[i][j];
                           this->nodosVisitados.mat[i][j] = this->listaNodos.cabeza->matrix[i][j];
                           //cout<<this->matriz[i][j]<<" ";
                       }

                         //cout<<endl;
                   }



                   this->direccionInicialNodosVisitados.cabeza = this->nodosVisitados.cabeza;



                   adelante = this->nodosVisitados.revisarNodosRepetidos();

                   //cout<<"Aqui si"<<endl;


                   this->nodosVisitados.cabeza = this->direccionInicialNodosVisitados.cabeza;


                   if(adelante == 1)
                   this->nodosVisitados.insertarNodoCola();


                   else if(this->listaNodos.cabeza->siguiente != NULL)
                           {
                              this->listaNodos.cabeza = this->listaNodos.cabeza->siguiente;
                              //cout<<"Nodo Repetido"<<endl;
                             }
                   else
                   {
                       cout<<"Solucion no encontrada"<<endl;
                       break;
                   }
               }




           this->listaNodos.cabeza = this->direccionInicialListaNodos.cabeza;

           d_arriba = this->checarMoverArriba();
           d_abajo = this->checarMoverAbajo();
           d_derecha = this->checarMoverDerecha();
           d_izquierda = this->checarMoverIzquierda();
           coordenadas[0] = d_arriba;
           coordenadas[1] = d_abajo;
           coordenadas[2] = d_derecha;
           coordenadas[3] = d_izquierda;



           /*while(coordenadas[0] == -1 && coordenadas[1] == -1 && coordenadas[2] == -1 && coordenadas[3] == -1)
           {
               if(nueva_lista.cabeza != NULL)
               {


                   d_arriba = this->checarMoverArriba();
                   d_abajo = this->checarMoverAbajo();
                   d_derecha = this->checarMoverDerecha();
                   d_izquierda = this->checarMoverIzquierda();
                   coordenadas[0] = d_arriba;
                   coordenadas[1] = d_abajo;
                   coordenadas[2] = d_derecha;
                   coordenadas[3] = d_izquierda;

                   cout<<"en el ciclo"<<endl;

                   nueva_lista.cabeza = nueva_lista.cabeza->siguiente;
               }

               else
                   break;
           }*/

           for(p1=0;p1<4;p1++)
           {
               for(p2=p1;p2<4;p2++)
               {
                  if(coordenadas[p2]>coordenadas[p1])
                  {
                      aux = coordenadas[p2];
                      coordenadas[p2] = coordenadas[p1];
                      coordenadas[p1] = aux;
                  }
               }
           }

           //cout<<coordenadas[0]<<" "<<coordenadas[1]<<" "<<coordenadas[2]<<" "<<coordenadas[3]<<endl;

          /* for(i=0;i<4;i++)
           {
               for(j=0;j<4;j++)
               {
                   nueva_lista.mat[i][j] = this->matriz[i][j];

               }


           }*/



           for(i=0;i<4;i++)
           {

               if(check == 0 )
               {
                   check = 1;

                   for(k=0;k<4;k++)
                   {
                       for(h=0;h<4;h++)
                       {
                           this->listaNodos.otra[k][h] = this->listaNodos.cabeza->matrix[k][h];

                       }
                   }
               }

               if(coordenadas[0] == -1 && coordenadas[1] == -1 && coordenadas[2] == -1 && coordenadas[3] == -1)
               {adelante = 0;
                   while(adelante == 0)
                   {
                         // cout<<"Nodo a evaluar"<<endl<<endl;





                           for(i=0;i<4;i++)
                           {
                               for(j=0;j<4;j++)
                               {
                                   this->matriz[i][j] = this->listaNodos.cabeza->matrix[i][j];
                                   this->listaNodos.copia_mat[i][j] = this->listaNodos.cabeza->matrix[i][j];
                                   this->listaNodos.mat[i][j] = this->listaNodos.cabeza->matrix[i][j];
                                   this->nodosVisitados.mat[i][j] = this->listaNodos.cabeza->matrix[i][j];
                                   //cout<<this->matriz[i][j]<<" ";
                               }

                                 //cout<<endl;
                           }



                           this->direccionInicialNodosVisitados.cabeza = this->nodosVisitados.cabeza;



                           adelante = this->nodosVisitados.revisarNodosRepetidos();


                           this->nodosVisitados.cabeza = this->direccionInicialNodosVisitados.cabeza;


                           if(adelante == 1)
                           this->nodosVisitados.insertarNodoCola();


                           else if(this->listaNodos.cabeza->siguiente != NULL)
                                   {
                                      this->listaNodos.cabeza = this->listaNodos.cabeza->siguiente;
                                      //cout<<"Nodo Repetido"<<endl;
                                     }
                           else
                           {
                               cout<<"Solucion no encontrada"<<endl;
                               break;
                           }
                       }
               }

               if(coordenadas[i]==d_abajo && down==0 && coordenadas[i] != -1)
               {
                   this->listaNodos.insertarNodoAbajo();
                   down = 1;

               }

               else if(coordenadas[i]==d_izquierda && left==0 && coordenadas[i] != -1)
               {
                   this->listaNodos.insertarNodoIzquierda();
                   left = 1;

               }

               else if(coordenadas[i]==d_derecha && right==0 && coordenadas[i] != -1)
               {
                   this->listaNodos.insertarNodoDerecha();
                   right = 1;

               }

               else if(coordenadas[i]==d_arriba && up ==0 && coordenadas[i] != -1)
               {
                   this->listaNodos.insertarNodoArriba();
                   up = 1;

               }


           }

           up = 0;
           right = 0;
           left = 0;
           down = 0;

           //this->originalDireccionInicial.cabeza = nueva_lista.cabeza;
           //cout<<"Impresion Lista Prioridad"<<endl;
           //nueva_lista.verLista();
           //cout<<"Termina Impresion Lista Prioridad"<<endl;
           //nueva_lista.cabeza = this->originalDireccionInicial.cabeza;
           //this->direccionInicial.cabeza = this->nodosVisitados.cabeza;
           //cout<<"Impresion Nodos Visitados"<<endl;
           //this->nodosVisitados.verLista();
           //cout<<"Termina Impresion Nodos Visitados"<<endl;
           //this->nodosVisitados.cabeza=this->direccionInicial.cabeza;


           /*for(i=0;i<4;i++)
           {
               for(j=0;j<4;j++)
               {
                   cout<<this->nodosVisitados.cabeza->matrix[i][j]<<" ";

               }

               cout<<endl;


           }

           cout<<endl<<"Ingrese una tecla =";
           cin>>tecla;

           */
       }

       else
       {
              for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    cout<<this->listaNodos.cabeza->matrix[i][j]<<" ";

                }

                cout<<endl;


            }

           cout<<"Acomodo Exitoso"<<endl;
           tiempo = time(0);
           struct tm *tlocal = localtime(&tiempo);
           strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
           printf("%s\n",output);

           cin>>tecla;

           cout<<"Exportando datos a txt...";

           this->nodosVisitados.verLista();

           cout<<"Guardado completo!!!";

       }
   }

}

int CuadroMagico::checarMoverArriba()
{

    //cout<<"Checar Movimiento Arriba"<<endl;

    int i = 0;
    int j = 0;
    int encontrado = 0;
    int gana = 0;
    int distancia = -1; // Distancia Manhattan, Si distancia = -1, no se puede realizar el movimiento
    int aux = 0;
    int k = 0;
    int l = 0;
    int dManhattan = 0;
    int encontrado2 = 0;
    int igual = 1;

    this->direccionInicialNodosVisitados.cabeza = this->nodosVisitados.cabeza;


    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            this->checar[i][j] = this->listaNodos.cabeza->matrix[i][j];
        }
    }



        for(i = 0;i<this->filas;i++)
        {
            for(j = 0;j<this->columnas;j++)
            {
                if(encontrado == 1)
                {
                    break;
                }

                else if(0 == checar[i][j])
                {
                   encontrado = 1;
                   j--;
                }

            }

            if(encontrado == 1)
                break;
        }


    if(encontrado == 1)
    {
        if(i>0)
        {
            checar[i][j] = checar[i-1][j];
            checar[i-1][j] = 0;

            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {

                    for(k=0;k<4;k++)
                    {
                        for(l=0;l<4;l++)
                        {
                           if(checar[i][j]==combinacionGanadora[k][l])
                           {
                               encontrado2 = 1;
                               dManhattan = (dManhattan+((abs(i-k)+abs(j-l))));
                               break;
                           }


                        }

                        if(encontrado2 == 1)
                        {
                            encontrado2 = 0;
                            break;
                        }


                    }

                }
            }

            //cout<<"Se puede mover hacia arriba y Manhattan = "<<dManhattan<<endl;

            distancia = dManhattan;
        }

          //else
            //cout<<"No se puede mover hacia arriba"<<endl;

    }

    if(dManhattan != -1)
    {

        while(this->nodosVisitados.cabeza != NULL)
        {
            igual = 1;

            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(this->checar[i][j] != this->nodosVisitados.cabeza->matrix[i][j])
                    igual = 0;

                    if(igual == 0)
                        break;
                }

                if(igual == 0)
                    break;
            }


            if(igual == 0)
            {
                this->nodosVisitados.cabeza = this->nodosVisitados.cabeza->siguiente;

            }

            else
                break;
        }
    }

    if(igual == 1)
      {
        distancia = -1;
    }

    this->verTableroChecar();

    this->nodosVisitados.cabeza=this->direccionInicialNodosVisitados.cabeza;

    return distancia;

}

int CuadroMagico::checarMoverAbajo()
{
    //cout<<"Checar Movimiento Abajo"<<endl;

    int i = 0;
    int j = 0;
    int encontrado = 0;
    int gana = 0;
    int distancia = -1; // Distancia Manhattan, Si distancia = -1, no se puede realizar el movimiento
    int aux = 0;
    int k = 0;
    int l = 0;
    int dManhattan = 0;
    int encontrado2 = 0;
    int igual = 1;

    this->direccionInicialNodosVisitados.cabeza = this->nodosVisitados.cabeza;


    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            this->checar[i][j] = this->listaNodos.cabeza->matrix[i][j];
        }
    }



        for(i = 0;i<this->filas;i++)
        {
            for(j = 0;j<this->columnas;j++)
            {
                if(encontrado == 1)
                {
                    break;
                }

                else if(0 == checar[i][j])
                {
                   encontrado = 1;
                   j--;
                }

            }

            if(encontrado == 1)
                break;
        }


        if(encontrado == 1)
        {
            if(i<3)
            {
                checar[i][j] = checar[i+1][j];
                checar[i+1][j] = 0;

            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {

                    for(k=0;k<4;k++)
                    {
                        for(l=0;l<4;l++)
                        {
                           if(checar[i][j]==combinacionGanadora[k][l])
                           {
                               encontrado2 = 1;
                               dManhattan = (dManhattan+((abs(i-k)+abs(j-l))));
                               break;
                           }


                        }

                        if(encontrado2 == 1)
                        {
                            encontrado2 = 0;
                            break;
                        }


                    }

                }
            }

            //cout<<"Se puede mover hacia abajo y Manhattan = "<<dManhattan<<endl;

            distancia = dManhattan;
        }

          //else
            //cout<<"No se puede mover hacia abajo"<<endl;

    }

    if(dManhattan != -1)
    {

        while(this->nodosVisitados.cabeza != NULL)
        {
            igual = 1;

            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(this->checar[i][j] != this->nodosVisitados.cabeza->matrix[i][j])
                    igual = 0;

                    if(igual == 0)
                        break;
                }

                if(igual == 0)
                    break;
            }


            if(igual == 0)
            {
                this->nodosVisitados.cabeza = this->nodosVisitados.cabeza->siguiente;

            }

            else
                break;
        }
    }

    if(igual == 1)
      {
        distancia = -1;
    }

    this->verTableroChecar();

    this->nodosVisitados.cabeza=this->direccionInicialNodosVisitados.cabeza;

    return distancia;
}

int CuadroMagico::checarMoverDerecha()
{
    //cout<<"Checar Movimiento Derecha"<<endl;

    int i = 0;
    int j = 0;
    int encontrado = 0;
    int gana = 0;
    int distancia = -1; // Distancia Manhattan, Si distancia = -1, no se puede realizar el movimiento
    int aux = 0;
    int k = 0;
    int l = 0;
    int dManhattan = 0;
    int encontrado2 = 0;
    int igual = 1;

    this->direccionInicialNodosVisitados.cabeza = this->nodosVisitados.cabeza;


    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            this->checar[i][j] = this->listaNodos.cabeza->matrix[i][j];
        }
    }



        for(i = 0;i<this->filas;i++)
        {
            for(j = 0;j<this->columnas;j++)
            {
                if(encontrado == 1)
                {
                    break;
                }

                else if(0 == checar[i][j])
                {
                   encontrado = 1;
                   j--;
                }

            }

            if(encontrado == 1)
                break;
        }


        if(encontrado == 1)
        {
            if(j<3)
            {
                checar[i][j] = checar[i][j+1];
                checar[i][j+1] = 0;

            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {

                    for(k=0;k<4;k++)
                    {
                        for(l=0;l<4;l++)
                        {
                           if(checar[i][j]==combinacionGanadora[k][l])
                           {
                               encontrado2 = 1;
                               dManhattan = (dManhattan+((abs(i-k)+abs(j-l))));
                               break;
                           }


                        }

                        if(encontrado2 == 1)
                        {
                            encontrado2 = 0;
                            break;
                        }


                    }

                }
            }

            //cout<<"Se puede mover hacia derecha y Manhattan = "<<dManhattan<<endl;

            distancia = dManhattan;
        }

         // else
            //cout<<"No se puede mover hacia derecha"<<endl;

    }

    if(dManhattan != -1)
    {

        while(this->nodosVisitados.cabeza != NULL)
        {
            igual = 1;

            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(this->checar[i][j] != this->nodosVisitados.cabeza->matrix[i][j])
                    igual = 0;

                    if(igual == 0)
                        break;
                }

                if(igual == 0)
                    break;
            }


            if(igual == 0)
            {
                this->nodosVisitados.cabeza = this->nodosVisitados.cabeza->siguiente;

            }

            else
                break;
        }
    }

    if(igual == 1)
      {
        distancia = -1;
    }

    this->verTableroChecar();

    this->nodosVisitados.cabeza=this->direccionInicialNodosVisitados.cabeza;

    return distancia;
}

int CuadroMagico::checarMoverIzquierda()
{
    //cout<<"Checar Movimiento Izquierda"<<endl;

    int i = 0;
    int j = 0;
    int encontrado = 0;
    int gana = 0;
    int distancia = -1; // Distancia Manhattan, Si distancia = -1, no se puede realizar el movimiento
    int aux = 0;
    int k = 0;
    int l = 0;
    int dManhattan = 0;
    int encontrado2 = 0;
    int igual = 1;

    this->direccionInicialNodosVisitados.cabeza = this->nodosVisitados.cabeza;


    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            this->checar[i][j] = this->listaNodos.cabeza->matrix[i][j];
        }
    }



        for(i = 0;i<this->filas;i++)
        {
            for(j = 0;j<this->columnas;j++)
            {
                if(encontrado == 1)
                {
                    break;
                }

                else if(0 == checar[i][j])
                {
                   encontrado = 1;
                   j--;
                }

            }

            if(encontrado == 1)
                break;
        }


        if(encontrado == 1)
        {
            if(j>0)
            {
                checar[i][j] = checar[i][j-1];
                checar[i][j-1] = 0;

            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {

                    for(k=0;k<4;k++)
                    {
                        for(l=0;l<4;l++)
                        {
                           if(checar[i][j]==combinacionGanadora[k][l])
                           {
                               encontrado2 = 1;
                               dManhattan = (dManhattan+((abs(i-k)+abs(j-l))));
                               break;
                           }


                        }

                        if(encontrado2 == 1)
                        {
                            encontrado2 = 0;
                            break;
                        }


                    }

                }
            }

            //cout<<"Se puede mover hacia izquierda y Manhattan = "<<dManhattan<<endl;

            distancia = dManhattan;
        }

          //else
            //cout<<"No se puede mover hacia izquierda"<<endl;

    }

    if(dManhattan != -1)
    {

        while(this->nodosVisitados.cabeza != NULL)
        {
            igual = 1;

            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(this->checar[i][j] != this->nodosVisitados.cabeza->matrix[i][j])
                    igual = 0;

                    if(igual == 0)
                        break;
                }

                if(igual == 0)
                    break;
            }


            if(igual == 0)
            {
                this->nodosVisitados.cabeza = this->nodosVisitados.cabeza->siguiente;

            }

            else
                break;
        }
    }

    if(igual == 1)
      {
        distancia = -1;
    }

    this->verTableroChecar();

    this->nodosVisitados.cabeza=this->direccionInicialNodosVisitados.cabeza;

    return distancia;
}

void CuadroMagico::verTableroChecar()
{
    int i = 0;
    int j = 0;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            //cout<<checar[i][j]<<" ";
        }

        //cout<<endl;
    }
}





