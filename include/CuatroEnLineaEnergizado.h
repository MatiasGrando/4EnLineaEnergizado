#ifndef CUATROENLINEAENERGIZADO_H
#define CUATROENLINEAENERGIZADO_H
#include "Lista.h"
#include "IndiceColumna.h"
#include <iostream>
#include "EasyBMP.h"
#define ENERGIAGANADAPORTURNO 20
using namespace std;
class CuatroEnLineaEnergizado
{
    private:
        unsigned int cantidadDeFichasEnELTablero;
        unsigned int cantidadDeJugadores;
        IndiceColumna* tableroColumnas;
        unsigned int cantidadColumnas;
        unsigned int cantidadFilas;
        Lista<unsigned int*> ganadores;
        Ficha* fichaAnterior;
        int turno;

        //pre tablero creado
		//post: crea una imagen bitmap mostrando un tablero dependiendo el numero de filas y columnas
		void crearTableroBitmap();
		//pre: tablero y "Tablero.bmp" creado
		//post: colorea el archivo "Tablero.bmp" dependiendo la fila, columna y posicion del jugador
        void pintarFicha(int fila,int columna, unsigned int jugador);
        //pre lista debe estar creada
        //post inicializa el cursor en la ultima posicion de la columna actual e imprime la ficha
        void inicializarCursorDeColumnaActualEImprimirFicha();
        //pre se debe haber inicializado el cursor en la ultima posicion
        //post retrocede el cursor de la columna actual e imprime la ficha actual
        void retrocederCursorDeColumnaActualEImprimirFicha();
        //pre tablero debe estar creado
        //post imprime la primera fila ( fila N) e inicializa los cursores de las listas de columnas en la ultima posicion
        void imprimirPrimeraFila();
        //pre
        //post -imprime las filas a exepcion de la primera
        //     -va retrocediendo el  cursor de la lista columnas e imprimiendo las fichas hasta llegar al primero
        void imprimirRestoDeFilas();
        //pre
        //post pide memoria y crea el tablero
        void crearTablero();
        //pre el tablero debe estar creado
        //post imprime el tablero
        void imprimirTablero();
        //pre tablero debe estar creado
        //post inserta una ficha con energia maxima y con el numero del jugador
        void insertarFicha(int jugador);
        //pre
        //post devuelve V si la columna se encuentra llena y F si hay lugar para almenos una ficha mas
        bool columnaLlena(int columna);
        //pre
        //post devuelve V  si alguno de los jugadores gano y F si aun no hay ganador
        bool comprobarSiGano(unsigned int jugador);
        //pre
        //post devuelve V sis se gano por 4 fichas en linea continua en una de  las columnas
        bool ganoPorColumna(unsigned int jugador);
        //pre
        //post duvuelve V sii se gano por 4 fichas en linea continua en una de las filas
        bool ganoPorFila(unsigned int jugador);
        //pre
        //post devuelve V  sii se gano por 4 fichas en linea continua en forma de escalera ascendente
        bool ganoPorEscaleraAscendente(unsigned int jugador);
        //pre
        //post devuelve V sii se gano por 4 fichas en linea continua en forma de escalera desendente
        bool ganoPorEscaleraDescendente(unsigned int jugador);
        //pre
        //post devuelve V sii segun la columna y fila dadas hay 4 fichas pertenecientes al mismo jugador en columna
        bool cuatroEnColumna(Columna* columnaActual,int fila,unsigned int jugador);
        //pre
        //post devuelve V sii segun la fila y columna dadas hay 4 fichas pertenecientes al mismo jugador en fila
        bool cuatroEnFila(int columna, int fila,unsigned int jugador);
        //pre
        //post devuelve  V sii segun la fila y columna dadas hay 4 fichas pertenecientes al mismo jugador en escalera ascendente
        bool cuatroEnEscaleraAscendente(int columna,int fila,unsigned int jugador);
        //pre
        //post devuelve V sii segun la fila y columna dadas hay 4 fichas pertenecientes al mismo jugador en escalera descendente
        bool cuatroEnEscaleraDescendente(int columna,int fila,unsigned int jugador);

        //pre
        //post -se posiciona en el numero de la columna pasada
        //     -devuelve la direccion de la columna
        Columna* posicionarseEnColumna(int columna);
        //pre
        //post -se posiciona en una ficha segun la columna y fila pasadas
        //     -devuelve la direccion de la ficha
        Ficha* posicionarseEnFicha(Columna* columnaActual,int fila);
        //pre
        //post - se posiciona en la fila libre de la culumna pasada
        //     . devuelve la direccion donde ira la ficha
        Ficha* posicionarseEnFilaLibre(Columna* columnaActual);
        //pre
        //post envia mensaje de finalizacion del juego, diciendo quien gano o si se empato
        void mensajeDeFinalizacionDelJuego(unsigned int jugador, bool hayGanador);
        //pre
        //post se encarga de manejar los cambios de energia
        void fluctuacionSinergia();
        //pre
        //post se encarga de cambiar las energias de las fichas por sinergia con las demas fichas
        //    - caso ficha que no se encuentra en ningun borde del tablero
        void fluctuacionMitadDelTablero(int columna, int fila);
        //pre
        //post se encarga de cambiar las energias de las fichas por sinergia con las demas fichas
        //    - caso ficha se encuentra en la esquina inferior izquierda del tablero
        void fluctuacionEsquinaInferiorIzquierda(int columna, int fila);
        //pre
        //post se encarga de cambiar las energias de las fichas por sinergia con las demas fichas
        //    - caso ficha se encuentra en la esquina inferior derecha del tablero
        void fluctuacionEsquinaInferiorDerecha(int columna, int fila);
        //pre
        //post se encarga de cambiar las energias de las fichas por sinergia con las demas fichas
        //    - caso ficha se encuentra en la esquina superior izquierda del tablero
        void fluctuacionEsquinaSuperiorIzquierda(int columna, int fila);
        //pre
        //post se encarga de cambiar las energias de las fichas por sinergia con las demas fichas
        //    - caso ficha se encuentra en la esquina superior derecha del tablero
        void fluctuacionEsquinaSuperiorDerecha(int columna, int fila);
        //pre
        //post se encarga de cambiar las energias de las fichas por sinergia con las demas fichas
        //    - caso ficha se encuentra en la primera columna,exepto en alguna de sus 2 esquinas
        void fluctuacionPrimeraColumna(int columna, int fila);
        //pre
        //post se encarga de cambiar las energias de las fichas por sinergia con las demas fichas
        //    - caso ficha se encuentra en la ultima columna exepto en alguna de sus 2 esquinas
        void fluctuacionUltimaColumna(int columna, int fila);
        //pre
        //post se encarga de cambiar las energias de las fichas por sinergia con las demas fichas
        //    - caso ficha se encuentra en la primera fila, exepto alguno de sus 2 extremos
        void fluctuacionPrimeraFila(int columna, int fila);
        //pre
        //post se encarga de cambiar las energias de las fichas por sinergia con las demas fichas
        //    - caso ficha se encuentra en la ultima fila, exepto en alguno de sus 2 extremos
        void fluctuacionUltimaFila(int columna, int fila);
        //pre
        //post suma o resta energia correspondiente a la ficha segun la ficha perisferica que se este viendo
        int fluctuacionSinergiaPerisferica(unsigned int jugador, int energia,Ficha* fichaPerisferica);
        //pre
        //post se encarga de manejar en que caso se encuentra la ficha para poder derivarlo y realizar la fluctuacion de energia
        void fluctuacionSinergiaPerisfericaSegunCasos(unsigned int columna, unsigned int fila);
        //pre
        //post elimina las fichas sin energia del tablero y hace caer las demas fichas tantos liberando espacio en la columna
        void eliminarFichasSinEnergia();
        //pre
        //post energiza energia correspondiente y aumenta el turno de vida de las fichas
        void energizarFichasSobrevivientes();
        //pre
        //post  deja caer las fichas un casillero segun la columna y segun la fila dada
        void dejarCaerFichasUnCasillero(Columna* columnaActual, unsigned int fila,unsigned int columna);
        //pre
        //post interactua con el usuario para obtener la columna a cual ingresar la ficha del jugador
        int obtenerColumnaAInsertarFicha(int jugador);
        //pre
        //post relaciona la ficha actual con la anterior
        void relacionarFichaActualConAnterior(Ficha* fichaActual);
        //pre
        //post se encarga de la fluctuacion de la sinergia de la ficha con su anterior y su posterior ficha
        void fluctuacionSinergiaConFichaAnteriorYPosterior(Ficha* fichaActual);
        //pre
        //post se encarga de modificar la energia con la ficha anterior de la ficha actual
        void fluctuacionSinergiaConFichaAnterior(Ficha* fichaActual);
        //pre
        //post  se encarga de modificar la energia con la ficha posterior de la ficha actual
        void fluctuacionSinergiaConFichaPosterior(Ficha* fichaActual);
        //
        //
        unsigned int comprobarSiHayGanador();
        //7
        //
        void procedimientosPosInsercionDeFicha(bool &hayGanador, unsigned int &jugador);
    public:
        //pre
        //post crea el tablero y lo inicializa
        //     crea una lista en donde se guardaran los ganadores en caso que haya mas de 1
        CuatroEnLineaEnergizado(unsigned int filas,unsigned int columnas,unsigned int jugadores);
        //pre
        //post libera la memoria pedida al crear el tablero
        ~CuatroEnLineaEnergizado();
        //pre tablero creado
        //post inicia la partida
        void iniciarPartida();

};
Ficha* CuatroEnLineaEnergizado::posicionarseEnFicha(Columna* columnaActual, int fila)
{
    columnaActual->obtenerColumna()->iniciarCursor();
    for(int i =1; i< fila;i++)
    {
        columnaActual->obtenerColumna()->avanzarCursor();
    }
    Ficha* filaActual=columnaActual->obtenerColumna()->obtenerCursor()->obtenerDato();
    return filaActual;
}
bool CuatroEnLineaEnergizado::cuatroEnColumna(Columna* columnaActual,int fila,unsigned int jugador)
{
    Ficha* ficha1;Ficha* ficha2;Ficha* ficha3;Ficha* ficha4;
    ficha1=posicionarseEnFicha(columnaActual,fila);
    ficha2=posicionarseEnFicha(columnaActual,fila+1);
    ficha3=posicionarseEnFicha(columnaActual,fila+2);
    ficha4=posicionarseEnFicha(columnaActual,fila+3);

    return (   (jugador == ficha1->obtenerJugador())
            && (jugador == ficha2->obtenerJugador())
            && (jugador == ficha3->obtenerJugador())
            && (jugador == ficha4->obtenerJugador()));
}
bool CuatroEnLineaEnergizado::cuatroEnFila(int columna, int fila,unsigned int jugador)
{
    Ficha* ficha1;Ficha* ficha2;Ficha* ficha3;Ficha* ficha4;
    Columna* columna1;Columna* columna2;Columna* columna3;Columna* columna4;
    columna1=posicionarseEnColumna(columna);
    columna2=posicionarseEnColumna(columna+1);
    columna3=posicionarseEnColumna(columna+2);
    columna4=posicionarseEnColumna(columna+3);
    ficha1=posicionarseEnFicha(columna1,fila);
    ficha2=posicionarseEnFicha(columna2,fila);
    ficha3=posicionarseEnFicha(columna3,fila);
    ficha4=posicionarseEnFicha(columna4,fila);
    return (   (jugador == ficha1->obtenerJugador())
            && (jugador == ficha2->obtenerJugador())
            && (jugador == ficha3->obtenerJugador())
            && (jugador == ficha4->obtenerJugador()));
}
bool CuatroEnLineaEnergizado::cuatroEnEscaleraAscendente(int columna, int fila,unsigned int jugador)
{
    Ficha* ficha1;Ficha* ficha2;Ficha* ficha3;Ficha* ficha4;
    Columna* columna1;Columna* columna2;Columna* columna3;Columna* columna4;
    columna1=posicionarseEnColumna(columna);
    columna2=posicionarseEnColumna(columna+1);
    columna3=posicionarseEnColumna(columna+2);
    columna4=posicionarseEnColumna(columna+3);
    ficha1=posicionarseEnFicha(columna1,fila);
    ficha2=posicionarseEnFicha(columna2,fila+1);
    ficha3=posicionarseEnFicha(columna3,fila+2);
    ficha4=posicionarseEnFicha(columna4,fila+3);
    return (   (jugador == ficha1->obtenerJugador())
            && (jugador == ficha2->obtenerJugador())
            && (jugador == ficha3->obtenerJugador())
            && (jugador == ficha4->obtenerJugador()));
}
bool CuatroEnLineaEnergizado::cuatroEnEscaleraDescendente(int columna, int fila,unsigned int jugador)
{
    Ficha* ficha1;Ficha* ficha2;Ficha* ficha3;Ficha* ficha4;
    Columna* columna1;Columna* columna2;Columna* columna3;Columna* columna4;
    columna1=posicionarseEnColumna(columna);
    columna2=posicionarseEnColumna(columna+1);
    columna3=posicionarseEnColumna(columna+2);
    columna4=posicionarseEnColumna(columna+3);
    ficha1=posicionarseEnFicha(columna1,fila+3);
    ficha2=posicionarseEnFicha(columna2,fila+2);
    ficha3=posicionarseEnFicha(columna3,fila+1);
    ficha4=posicionarseEnFicha(columna4,fila);
    return (   (jugador == ficha1->obtenerJugador())
            && (jugador == ficha2->obtenerJugador())
            && (jugador == ficha3->obtenerJugador())
            && (jugador == ficha4->obtenerJugador()));
}
bool CuatroEnLineaEnergizado::ganoPorEscaleraDescendente(unsigned int jugador)
{
    bool gano=false;
    unsigned int fila=1;
    while ((gano==false)&&((cantidadFilas-3)>=fila))
    {
        unsigned int columna=1;
        while ((columna<=(cantidadColumnas-3))&&(cuatroEnEscaleraDescendente(columna,fila,jugador)==false))
        {
            columna++;
        }
        if((columna<=(cantidadColumnas-3))&&(cuatroEnEscaleraDescendente(columna,fila,jugador)==true))
        {
            gano=true;
        }
        else
        {
            fila++;
        }
    }
    return(gano);
}

bool CuatroEnLineaEnergizado::ganoPorEscaleraAscendente(unsigned int jugador)
{
    bool gano=false;
    unsigned int fila=1;
    while ((gano==false)&&((cantidadFilas-3)>=fila))
    {
        unsigned int columna=1;
        while ((columna<=(cantidadColumnas-3))&&(cuatroEnEscaleraAscendente(columna,fila,jugador)==false))
        {
            columna++;
        }
        if((columna<=(cantidadColumnas-3))&&(cuatroEnEscaleraAscendente(columna,fila,jugador)==true))
        {
            gano=true;
        }
        else
        {
            fila++;
        }
    }
    return (gano);
}
bool CuatroEnLineaEnergizado::ganoPorColumna(unsigned int jugador)
{
    bool gano=false;
    unsigned int columna=1;
    while((gano==false) && ((cantidadColumnas)>=columna))
    {
        Columna* columnaActual=posicionarseEnColumna(columna);
        unsigned int fila=1;
        while ((fila<=(cantidadFilas-3))&&(cuatroEnColumna(columnaActual,fila,jugador)==false))
        {
            fila++;
        }
        if((fila<=(cantidadFilas-3))&&(cuatroEnColumna(columnaActual,fila,jugador)==true))
        {
            gano=true;
        }
        else
        {
            columna++;
        }
    }
    return gano;
}
bool CuatroEnLineaEnergizado::ganoPorFila(unsigned int jugador)
{
 bool gano=false;
 unsigned int fila=1;
 while ((gano==false)&&(cantidadFilas>=fila))
 {
    unsigned int columna=1;
    while ((columna<=(cantidadColumnas-3))&&(cuatroEnFila(columna,fila,jugador)==false))
    {
        columna++;
    }
    if((columna<=(cantidadColumnas-3))&&(cuatroEnFila(columna,fila,jugador)==true))
    {
        gano=true;
    }
    else
    {
        fila++;
    }
 }
 return (gano);
}
bool CuatroEnLineaEnergizado::columnaLlena(int columna)
{
    Columna* columnaActual= posicionarseEnColumna(columna);
    columnaActual->obtenerColumna()->iniciarCursorUltimo();
    Ficha* fichaActual= columnaActual->obtenerColumna()->obtenerCursor()->obtenerDato();
    return (fichaActual->obtenerJugador() != 0);
    }
bool CuatroEnLineaEnergizado::comprobarSiGano(unsigned int jugador)
{
    bool gano=false;
    gano = ganoPorColumna(jugador);
    if (gano==false)
    {
        gano = ganoPorFila( jugador);
        if(gano==false)
        {
            gano= ganoPorEscaleraAscendente(jugador);
            if(gano==false)
            {
                gano= ganoPorEscaleraDescendente( jugador);
            }
        }

    }
    return gano;
}
Columna* CuatroEnLineaEnergizado::posicionarseEnColumna(int columna)
{
    this->tableroColumnas->obtenerColumnas()->iniciarCursor();
    for(int i =1; i< columna;i++)
    {
        tableroColumnas->obtenerColumnas()->avanzarCursor();
    }
    Columna* columnaActual=this->tableroColumnas->obtenerColumnas()->obtenerCursor()->obtenerDato();
    return columnaActual;
}
Ficha* CuatroEnLineaEnergizado::posicionarseEnFilaLibre(Columna* columnaActual)
{
    columnaActual->obtenerColumna()->iniciarCursor();
    Ficha* fichaActual= columnaActual->obtenerColumna()->obtenerCursor()->obtenerDato();
    if(fichaActual->obtenerJugador()!= 0)
    {
        while (fichaActual->obtenerJugador()!=0)
        {
            columnaActual->obtenerColumna()->avanzarCursor();
            fichaActual= columnaActual->obtenerColumna()->obtenerCursor()->obtenerDato();
        }
        return fichaActual;
    }
    else
    {
        return fichaActual;
    }
}
void CuatroEnLineaEnergizado::relacionarFichaActualConAnterior(Ficha* fichaActual)
{
    if(turno == 0)
    {
        this->fichaAnterior=fichaActual;
    }
    else if (this->fichaAnterior != 0)
    {
        this->fichaAnterior->cambiarFichaPosterior(fichaActual);
        fichaActual->cambiarFichaAnterior(fichaAnterior);
        this->fichaAnterior=fichaActual;
    }
    else {this->fichaAnterior=fichaActual;}
}
int CuatroEnLineaEnergizado::obtenerColumnaAInsertarFicha(int jugador)
{
    int columna;
    do
    {
        cout<<endl<<"Turno del Jugador "<<jugador<<" -------- "<<"ingrese columna"<<endl;
        cin>>columna;
        if (columnaLlena(columna) == true)
        {
                cout<<endl<<"Columna llena, ingrese otra columna la cual no se encuentre llena"<<endl;
        }
    }while(columnaLlena(columna) == true);
    return columna;
}
void CuatroEnLineaEnergizado::insertarFicha(int jugador)
{
    int columna;
    this->cantidadDeFichasEnELTablero++;
    columna=obtenerColumnaAInsertarFicha(jugador);
    Columna* columnaActual= posicionarseEnColumna(columna);
    Ficha* fichaActual= posicionarseEnFilaLibre(columnaActual);
    fichaActual->cambiarJugador(jugador);
    fichaActual->fluctuacionDeEnergia(ENERGIAMAXIMA);
    relacionarFichaActualConAnterior(fichaActual);
    this->turno++;

}
void CuatroEnLineaEnergizado::fluctuacionSinergiaConFichaAnterior(Ficha* fichaActual)
{
    int energiaPerdida=0;
    if(fichaActual->obtenerFichaAnterior()!= 0)
    {
        Ficha* fichaAntecesora = (fichaActual->obtenerFichaAnterior());
        if(fichaAntecesora->obtenerFila()>fichaActual->obtenerFila())
        {
            energiaPerdida= fichaAntecesora->obtenerFila() - fichaActual->obtenerFila();
        }
        else
        {
            energiaPerdida= fichaActual->obtenerFila() - fichaAntecesora->obtenerFila();
        }
        if (energiaPerdida>fichaActual->obtenerTurnos())
        {
            energiaPerdida= -energiaPerdida + fichaActual->obtenerTurnos();
            fichaActual->fluctuacionDeEnergia(energiaPerdida);
        }
    }
}
void CuatroEnLineaEnergizado::fluctuacionSinergiaConFichaPosterior(Ficha* fichaActual)
{
    int energiaPerdida=0;
    if (fichaActual->obtenerFichaPosterior()!=0)
    {
        Ficha* fichaPosterior = (fichaActual->obtenerFichaPosterior());
        if (fichaPosterior->obtenerColumna()>fichaActual->obtenerColumna())
        {
            energiaPerdida=fichaPosterior->obtenerColumna()- fichaActual->obtenerColumna();
        }
        else
        {
            energiaPerdida=fichaActual->obtenerColumna()-fichaPosterior->obtenerColumna();
        }
        if(energiaPerdida > (fichaActual->obtenerTurnos()-1) )
        {
            energiaPerdida= -energiaPerdida +fichaActual->obtenerTurnos() - 1 ;
            fichaActual->fluctuacionDeEnergia(energiaPerdida);

        }
    }
}
void CuatroEnLineaEnergizado::fluctuacionSinergiaConFichaAnteriorYPosterior(Ficha* fichaActual)
{
    fluctuacionSinergiaConFichaAnterior(fichaActual);
    fluctuacionSinergiaConFichaPosterior(fichaActual);

}
void CuatroEnLineaEnergizado::mensajeDeFinalizacionDelJuego(unsigned int jugador, bool hayGanador)
{
    if(hayGanador==false)
    {
        cout<<endl<<"<<<<<<<<<<<EMPATE<<<<<<<<<<TABLERO LLENO<<<<<<<<<<"<<endl<<"----------PARTIDA FINALIZADA----------";
    }
    else if (jugador != 0 && jugador<= this->cantidadDeJugadores)
    {
        cout<<endl<<"<<<<<<<<<<GANADOR JUGADOR "<<jugador<<" <<<<<<<<<<"<<endl<<"----------PARTIDA FINALIZADA----------";
    }
    else if(jugador == 0)
    {
        this->ganadores.iniciarCursor();
        unsigned int jugadorActual=*(this->ganadores.obtenerCursor()->obtenerDato());
        cout<<"<<<<<EMPATE ENTRE JUGADORES  "<<jugadorActual;
        while (this->ganadores.avanzarCursor())
        {
            jugadorActual=*(this->ganadores.obtenerCursor()->obtenerDato());
            cout<<"  -  "<<jugadorActual;
        }
    }
    else
    {
        this->ganadores.iniciarCursor();
        cout<<endl<<"<<<<<<<<<<GANADOR JUGADOR "<<*(this->ganadores.obtenerCursor()->obtenerDato())<<" <<<<<<<<<<"<<endl<<"----------PARTIDA FINALIZADA----------";
    }
}
int CuatroEnLineaEnergizado::fluctuacionSinergiaPerisferica(unsigned int jugador, int energia,Ficha* fichaPerisferica)
{
    if(jugador == fichaPerisferica->obtenerJugador() && fichaPerisferica->obtenerTurnos()<ENERGIAGANADAPORSINERGIAPERISFERICA )
    {
        int turnoViva= fichaPerisferica->obtenerTurnos();
        energia=energia+ENERGIAGANADAPORSINERGIAPERISFERICA-turnoViva;

    }
    else if (fichaPerisferica->obtenerJugador()!= 0 && fichaPerisferica->obtenerTurnos()<ENERGIAPERDIDAPORSINERGIAPERISFERICA)
    {
        int turnoViva = fichaPerisferica->obtenerTurnos();
        energia=energia-ENERGIAPERDIDAPORSINERGIAPERISFERICA+turnoViva;
    }
    return energia;
}
void CuatroEnLineaEnergizado::fluctuacionMitadDelTablero(int columnaActual,int filaActual)
{
    int energia=0;
    unsigned int jugador;
    Ficha* fichaActual=posicionarseEnFicha(posicionarseEnColumna(columnaActual),filaActual);
    jugador= fichaActual->obtenerJugador();
    if(jugador!= 0)
    {
        Ficha* fichaPerisferica;

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual+1),filaActual);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual-1),filaActual);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual),filaActual+1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual),filaActual-1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual+1),filaActual+1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual+1),filaActual-1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual-1),filaActual+1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual-1),filaActual-1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaActual->fluctuacionDeEnergia(energia);
    }
}
void CuatroEnLineaEnergizado::fluctuacionEsquinaInferiorDerecha(int columnaActual, int fila)
{
    int energia=0;
    unsigned int jugador;
    Ficha* fichaActual=posicionarseEnFicha(posicionarseEnColumna(columnaActual),fila);
    jugador= fichaActual->obtenerJugador();
    if (jugador != 0)
    {
        Ficha* fichaPerisferica;

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual),fila+1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual-1),fila+1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual-1),fila);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaActual->fluctuacionDeEnergia(energia);
    }
}
void CuatroEnLineaEnergizado::fluctuacionEsquinaInferiorIzquierda(int columnaActual, int filaActual)
{
    int energia=0;
    unsigned int jugador;
    Ficha* fichaActual=posicionarseEnFicha(posicionarseEnColumna(columnaActual),filaActual);
    jugador= fichaActual->obtenerJugador();
    if(jugador!= 0)
    {
        Ficha* fichaPerisferica;

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual),filaActual+1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual+1),filaActual+1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual+1),filaActual);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaActual->fluctuacionDeEnergia(energia);

    }
}
void CuatroEnLineaEnergizado::fluctuacionEsquinaSuperiorDerecha(int columnaActual, int filaActual)
{
    int energia=0;
    unsigned int jugador;
    Ficha* fichaActual=posicionarseEnFicha(posicionarseEnColumna(columnaActual),filaActual);
    jugador= fichaActual->obtenerJugador();
    if(jugador!=0)
    {
        Ficha* fichaPerisferica;

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual),filaActual-1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual-1),filaActual-1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual-1),filaActual);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaActual->fluctuacionDeEnergia(energia);

    }
}
void CuatroEnLineaEnergizado::fluctuacionEsquinaSuperiorIzquierda(int columnaActual, int filaActual)
{
    int energia=0;
    unsigned int jugador;
    Ficha* fichaActual=posicionarseEnFicha(posicionarseEnColumna(columnaActual),filaActual);
    jugador= fichaActual->obtenerJugador();
    if (jugador !=0)
    {
        Ficha* fichaPerisferica;

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual),filaActual-1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual+1),filaActual-1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual+1),filaActual);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaActual->fluctuacionDeEnergia(energia);
    }
}
void CuatroEnLineaEnergizado::fluctuacionPrimeraColumna(int columnaActual, int filaActual)
{
    int energia=0;
    unsigned int jugador;
    Ficha* fichaActual=posicionarseEnFicha(posicionarseEnColumna(columnaActual),filaActual);
    jugador= fichaActual->obtenerJugador();
    if(jugador!=0)
    {
        Ficha* fichaPerisferica;

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual),filaActual+1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual+1),filaActual+1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual+1),filaActual);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual+1),filaActual-1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual),filaActual-1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaActual->fluctuacionDeEnergia(energia);
    }
}
void CuatroEnLineaEnergizado::fluctuacionUltimaColumna(int columnaActual, int filaActual)
{
    int energia=0;
    unsigned int jugador;
    Ficha* fichaActual=posicionarseEnFicha(posicionarseEnColumna(columnaActual),filaActual);
    jugador= fichaActual->obtenerJugador();
    if (jugador!=0)
    {
        Ficha* fichaPerisferica;

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual),filaActual+1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual-1),filaActual+1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual-1),filaActual);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual-1),filaActual-1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual),filaActual-1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaActual->fluctuacionDeEnergia(energia);

    }
}
void CuatroEnLineaEnergizado::fluctuacionPrimeraFila(int columnaActual, int filaActual)
{
    int energia=0;
    unsigned int jugador;
    Ficha* fichaActual=posicionarseEnFicha(posicionarseEnColumna(columnaActual),filaActual);
    jugador= fichaActual->obtenerJugador();
    if(jugador!= 0)
    {
        Ficha* fichaPerisferica;

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual+1),filaActual);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual),filaActual+1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual+1),filaActual+1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual-1),filaActual+1);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual-1),filaActual);
        energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

        fichaActual->fluctuacionDeEnergia(energia);
    }
}
void CuatroEnLineaEnergizado::fluctuacionUltimaFila(int columnaActual, int filaActual)
    {
        int energia=0;
        unsigned int jugador;
        Ficha* fichaActual=posicionarseEnFicha(posicionarseEnColumna(columnaActual),filaActual);
        jugador= fichaActual->obtenerJugador();
        if(jugador!= 0)
        {
            Ficha* fichaPerisferica;

            fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual+1),filaActual);
            energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

            fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual),filaActual-1);
            energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

            fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual+1),filaActual-1);
            energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

            fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual-1),filaActual-1);
            energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

            fichaPerisferica=posicionarseEnFicha(posicionarseEnColumna(columnaActual-1),filaActual);
            energia = fluctuacionSinergiaPerisferica(jugador,energia,fichaPerisferica);

            fichaActual->fluctuacionDeEnergia(energia);
        }
    }

void CuatroEnLineaEnergizado::fluctuacionSinergiaPerisfericaSegunCasos(unsigned int columna, unsigned int fila)
{
    if(fila==1 && columna ==1){fluctuacionEsquinaInferiorIzquierda(columna,fila);}
    else if(fila==cantidadFilas && columna ==1){fluctuacionEsquinaSuperiorIzquierda(columna,fila);}
    else if(fila==cantidadFilas && columna ==cantidadColumnas){fluctuacionEsquinaSuperiorDerecha(columna,fila);}
    else if(fila==1 && columna ==cantidadColumnas){fluctuacionEsquinaInferiorDerecha(columna,fila);}
    else if(columna ==1){fluctuacionPrimeraColumna(columna,fila);}
    else if(columna ==cantidadColumnas){fluctuacionUltimaColumna(columna,fila);}
    else if(fila==1){fluctuacionPrimeraFila(columna,fila);}
    else if(fila==cantidadFilas){fluctuacionUltimaFila(columna,fila);}
    else {fluctuacionMitadDelTablero(columna,fila);}
}
void CuatroEnLineaEnergizado::fluctuacionSinergia()
{
    unsigned int columna,fila;
    for (columna=1;columna<=cantidadColumnas;columna++)
    {
        for(fila=1;fila<=cantidadFilas;fila++)
        {
            fluctuacionSinergiaPerisfericaSegunCasos(columna,fila);
            Ficha* fichaActual=posicionarseEnFicha(posicionarseEnColumna(columna),fila);
            fluctuacionSinergiaConFichaAnteriorYPosterior(fichaActual);
        }
    }
}
void CuatroEnLineaEnergizado::dejarCaerFichasUnCasillero(Columna* columnaActual, unsigned int fila,unsigned int columna)
{
    Ficha* fichaActual = posicionarseEnFicha(columnaActual,fila);
    Ficha* fichaAnterior=fichaActual->obtenerFichaAnterior();
    Ficha* fichaPosterior=fichaActual->obtenerFichaPosterior();
    if (fichaAnterior != 0){fichaAnterior->cambiarFichaPosterior(0);}
    if (fichaPosterior !=0){fichaPosterior->cambiarFichaAnterior(0);}
    columnaActual->obtenerColumna()->eliminarElementoPosicion(fila);
    columnaActual->obtenerColumna()->agregarElemento(new Ficha(columna,this->cantidadFilas));
    for(unsigned int i =fila; i<this->cantidadFilas;i++)
    {
        fichaActual=posicionarseEnFicha(columnaActual, i);
        fichaActual->disminuirFila();
    }
}
void CuatroEnLineaEnergizado::eliminarFichasSinEnergia()
{
    unsigned int columna,fila;
    for (columna=1;columna<=cantidadColumnas;columna++)
    {
        Columna* columnaActual = posicionarseEnColumna(columna);
        for(fila=1;fila<=cantidadFilas;fila++)
        {
            Ficha* fichaActual = posicionarseEnFicha(columnaActual,fila);
            if (fichaActual->obtenerJugador()!=0 && fichaActual->obtenerEnergia()== 0)
            {
                    if(fichaActual==this->fichaAnterior){this->fichaAnterior=0;}
                    dejarCaerFichasUnCasillero(columnaActual,fila,columna);
                    fila--;
                    this->cantidadDeFichasEnELTablero--;
            }
        }
    }
}
void CuatroEnLineaEnergizado::energizarFichasSobrevivientes()
{
    unsigned int columna,fila;
    for (columna=1;columna<=cantidadColumnas;columna++)
    {
        Columna* columnaActual = posicionarseEnColumna(columna);
        for(fila=1;fila<=cantidadFilas;fila++)
        {
            Ficha* fichaActual = posicionarseEnFicha(columnaActual,fila);
            if (fichaActual->obtenerJugador()!= 0)
            {
                fichaActual->fluctuacionDeEnergia(ENERGIAGANADAPORTURNO);
                fichaActual->aumentarTurnos();
            }
        }
    }
}
unsigned int CuatroEnLineaEnergizado::comprobarSiHayGanador()
{
    unsigned int cantidadDeGanadores=0;
    bool hayGanador;
    for (unsigned int jugador=1;jugador <= this->cantidadDeJugadores; jugador ++)
    {
        hayGanador=false;
        hayGanador=comprobarSiGano(jugador);
        if(hayGanador==true)
        {
            cantidadDeGanadores++;
            unsigned int* punteroJugador = new unsigned int ;
            *punteroJugador = jugador;
            this->ganadores.agregarElemento(punteroJugador);
        }
    }
    return cantidadDeGanadores;
}
void CuatroEnLineaEnergizado::procedimientosPosInsercionDeFicha(bool& hayGanador, unsigned int &jugador)
{
    fluctuacionSinergia();
    eliminarFichasSinEnergia();
    unsigned int cantidadDeGanadores;
    cantidadDeGanadores= comprobarSiHayGanador();
    if (cantidadDeGanadores== 1)
    {
        hayGanador=true;
        jugador=this->cantidadDeJugadores+1;
    }
    else if( cantidadDeGanadores>1)
    {
        jugador= 0;
        hayGanador=true;
    }
    energizarFichasSobrevivientes();
}
void CuatroEnLineaEnergizado::iniciarPartida()
{
    crearTablero();
    imprimirTablero();
    bool hayGanador = false;
    unsigned int jugador;
    while ((hayGanador == false) &&(cantidadDeFichasEnELTablero<(cantidadColumnas*cantidadFilas)))
    {
        jugador=0;
        while((jugador < this->cantidadDeJugadores)&&(hayGanador == false)
            &&(cantidadDeFichasEnELTablero<(cantidadColumnas*cantidadFilas)))
        {
            jugador++;
            insertarFicha(jugador);
            hayGanador=comprobarSiGano(jugador);
            if (hayGanador == false)
            {
                procedimientosPosInsercionDeFicha(hayGanador,jugador);
            }
            imprimirTablero();
        }
    }
    mensajeDeFinalizacionDelJuego(jugador,hayGanador);
}
CuatroEnLineaEnergizado::CuatroEnLineaEnergizado(unsigned int filas,unsigned int columnas,unsigned int jugadores)
{
    this->cantidadColumnas=columnas;
    this->cantidadFilas=filas;
    this->cantidadDeJugadores=jugadores;
    this->cantidadDeFichasEnELTablero=0;
    this->turno=0;
    tableroColumnas= new IndiceColumna;
    crearTableroBitmap();

}
void CuatroEnLineaEnergizado::crearTablero()
{
    for (unsigned int columna=0; columna<(this->cantidadColumnas);columna++)
    {
        Columna* columnaActual= new Columna;
        tableroColumnas->obtenerColumnas()->agregarElemento(columnaActual);
        for (unsigned int fila=0; fila<(this->cantidadFilas);fila++)
        {
            columnaActual->obtenerColumna()->agregarElemento(new Ficha(columna,fila));
        }
    }
}
void CuatroEnLineaEnergizado::inicializarCursorDeColumnaActualEImprimirFicha()
{
    Columna* columnaActual;
    Ficha* fichaActual;
    columnaActual= this->tableroColumnas->obtenerColumnas()->obtenerCursor()->obtenerDato();
    columnaActual->obtenerColumna()->iniciarCursorUltimo();
    fichaActual=columnaActual->obtenerColumna()->obtenerCursor()->obtenerDato();
    pintarFicha(fichaActual->obtenerFila(), fichaActual->obtenerColumna(), fichaActual->obtenerJugador());
    cout<<fichaActual->obtenerJugador()<<" "<<fichaActual->obtenerEnergia()<<"     ";
}
void CuatroEnLineaEnergizado::retrocederCursorDeColumnaActualEImprimirFicha()
{
    Columna* columnaActual;
    Ficha* fichaActual;
    columnaActual= this->tableroColumnas->obtenerColumnas()->obtenerCursor()->obtenerDato();
    columnaActual->obtenerColumna()->retrocederCursor();
    fichaActual=columnaActual->obtenerColumna()->obtenerCursor()->obtenerDato();
    pintarFicha(fichaActual->obtenerFila(), fichaActual->obtenerColumna(), fichaActual->obtenerJugador());
    cout<<fichaActual->obtenerJugador()<<" "<<fichaActual->obtenerEnergia()<<"     ";

}
void CuatroEnLineaEnergizado::imprimirPrimeraFila()
{
    this->tableroColumnas->obtenerColumnas()->iniciarCursor();
    inicializarCursorDeColumnaActualEImprimirFicha();
    while(this->tableroColumnas->obtenerColumnas()->avanzarCursor())
    {
        inicializarCursorDeColumnaActualEImprimirFicha();
    }
}
void CuatroEnLineaEnergizado::imprimirRestoDeFilas()
{
    for (unsigned int i=1; i<(this->cantidadFilas);i++)
    {
        cout<<endl<<endl<<endl;
        this->tableroColumnas->obtenerColumnas()->iniciarCursor();
        retrocederCursorDeColumnaActualEImprimirFicha();
        while(this->tableroColumnas->obtenerColumnas()->avanzarCursor())
        {
            retrocederCursorDeColumnaActualEImprimirFicha();
        }
    }
}
void CuatroEnLineaEnergizado::imprimirTablero()
{
    imprimirPrimeraFila();
    imprimirRestoDeFilas();
}
CuatroEnLineaEnergizado::~CuatroEnLineaEnergizado()
{
    delete tableroColumnas;
}

void CuatroEnLineaEnergizado::crearTableroBitmap()
{
	BMP Tablero;
	Tablero.SetSize(100*this->cantidadColumnas, 100*this->cantidadFilas);
	Tablero.SetBitDepth(24);
	RGBApixel Temp;
	Temp= Tablero.GetPixel(0,0);
	Temp.Red = 0; Temp.Green = 0; Temp.Blue = 0; Temp.Alpha = 0;
	for (unsigned int i=0; i< this->cantidadColumnas*100 ; i+=100){
		for (unsigned int j = 0; j<this->cantidadFilas*100; j++){

			Tablero.SetPixel(i,j,Temp);
		}
	}
	for (unsigned int i=0; i< this->cantidadColumnas*100; i++){
		for (unsigned int j = 0; j<this->cantidadFilas*100; j+=100){
			Tablero.SetPixel(i,j,Temp);

		}
	}

	Tablero.WriteToFile("Tablero.bmp");

}

void CuatroEnLineaEnergizado::pintarFicha(int fila, int columna, unsigned int jugador)
{
	BMP ficha;
	ficha.ReadFromFile("Tablero.bmp");
	RGBApixel Temp;
	Temp = ficha.GetPixel(0, 0);
	if (jugador==1){
		Temp.Red = 255; Temp.Green = 0; Temp.Blue = 0; Temp.Alpha = 0;
	}else if(jugador ==2){
		Temp.Red = 0; Temp.Green = 0; Temp.Blue = 255; Temp.Alpha = 0;
	}else if (jugador ==0){
		return;
	}else{
		Temp.Red = jugador*70; Temp.Green = jugador*50; Temp.Blue = jugador*30; Temp.Alpha = 0;
	}

	fila = this->cantidadFilas - fila -1;

	//Temp.Red = 0; Temp.Green = 0; Temp.Blue = 255; Temp.Alpha = 0;
	for (int i=fila*100+1; i<= fila*100 +99; i++){
		for (int j = columna*100+1; j<=columna*100 +99; j++){

			ficha.SetPixel(j,i,Temp);
		}
	}
	ficha.WriteToFile("Tablero.bmp");

}
#endif // CUATROENLINEAENERGIZADO_H
