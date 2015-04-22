#include <iostream>
#include "juego15.h"
#include <time.h>
#include <conio.h>
#include <cstdio>


using namespace std;

int main()
{
    CuadroMagico tablero;

    time_t now;
    int opcion = 0;
    int dato = 0;
    char tecla;
    int t = 0;
    int gana = 0;

    tablero.inicializarTablero(4,4);

    while(opcion != 27)
       {
                   cout<<" 1  --- Resolver Juego del 15 Humano"<<endl;
                   cout<<" 2  --- Resolver Juego del 15 Maquina Busqueda Voraz"<<endl;
                   cout<<" 27 --- Salir de la aplicacion"<<endl;

                   cout<<endl;
                   cout<<"Ingrese una opcion: ";
                   cin>>opcion;
                   gana = 0;

                   if(opcion == 1)
                   {

                       gana = tablero.comprobarGana();

                       while(gana == 0)
                       {
                           if(t == 0)
                           {
                               cout<<"Numero que deseas mover: ";
                               cin>>dato;
                           }

                             tecla = getch();
                             t = 1;

                             switch(tecla)
                             {
                                 cout<<"Entro"<<endl;

                                 case 72:
                                    gana = tablero.moverNumeroArriba(dato);
                                    t = 0;
                                    break;


                                 case 80:
                                    gana = tablero.moverNumeroAbajo(dato);
                                    t = 0;
                                    break;

                                 case 75:
                                    gana = tablero.moverNumeroIzquierda(dato);
                                    t = 0;
                                    break;

                                 case 77:
                                    gana = tablero.moverNumeroDerecha(dato);
                                    t = 0;
                                    break;

                             }


                       }

                       if(gana == 1)
                       {
                           cout<<"Juego Completado con Exito"<<endl<<endl;
                       }
                   }

                   if(opcion == 2)
                   {
                        gana = tablero.comprobarGana();

                        tablero.evaluarMaquina();



                   }



       }

    return 0;
}

