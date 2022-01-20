#ifndef CONSOLA_H
#define CONSOLA_H
#include "CuatroEnLineaEnergizado.h"
void iniciarNuevaPartida();
void iniciarConsola();

void iniciarCuatroEnLineaEnergizado()
{
    unsigned int filas,columnas,jugadores;
    cout<<"ingrese la cantidad de jugadores"<<endl;
    cin>>jugadores;
    cout<<"ingrese la cantidad de columnas que tentra el tablero"<<endl;
    cin>>columnas;
    cout<<"ingrese la cantidad de filas que tendra el tablero"<<endl;
    cin>>filas;
    cout<<"<<<<<<<<<PARTIDA INICIADA<<<<<<<<"<<endl;
    CuatroEnLineaEnergizado juego(filas,columnas,jugadores);
    juego.iniciarPartida();
}
void iniciarConsola()
{
    cout<<"<<<<<<<<<JUEGO 4 EN LINEA ENERGIZADO<<<<<<<<<"<<endl;
    iniciarCuatroEnLineaEnergizado();
    int opcion;
    do
    {
        cout<<endl<<"ingrese 1 para volver a jugar o 2 para salir del juego"<<endl;
        cin>>opcion;
        if(opcion == 1){iniciarCuatroEnLineaEnergizado();}
        else{cout<<"<<<<<<<<<<JUEGO CUATRO EN LINEA ENERGIZADO FINALIZADO<<<<<<<<<"<<endl;}
    }while(opcion == 1);
}

#endif // CONSOLA_H
