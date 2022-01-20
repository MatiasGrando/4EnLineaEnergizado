#ifndef FICHA_H
#define FICHA_H
#define ENERGIAMAXIMA 100
#define ENERGIAMINIMA 0
#define ENERGIAPERDIDAPORSINERGIAPERISFERICA 12
#define ENERGIAGANADAPORSINERGIAPERISFERICA 10

class Ficha
{

    private:
        unsigned int jugador;
        int energia;
        int turnos;
        int columna;
        int fila;
        Ficha* fichaAnterior;
        Ficha* fichaPosterior;
    public:
        //PRE:
        //POST: Crea una ficha con jugador = 0 y una energia = 0
        Ficha(unsigned int columna, unsigned int fila);
        //PRE:La energia no puede ser:
        //                          //menor de 0
        //                         // mayor a 100
        //POST: Modifica la energia Actual de la ficha
        void fluctuacionDeEnergia( int energiaFluctuada);
        //PRE:---
        //POST:Devuelve energia actual del nodo
        int obtenerEnergia();
        //PRE:----
        //POST:Devuelve el numero del jugador perteneciente al nodo
        unsigned int obtenerJugador();
        //PRE:nodo existente
        //POST:cambia el numero del jugador
        void cambiarJugador(unsigned int nuevoJugador);
        //pre la ficha no puede tener como jugador 0 o energia 0
        //post aumenta el turno de la ficha en 1
        void aumentarTurnos();
        //pre la ficha no puede tener energia 0 o jugador 0
        //post devuelve la cantidad de turnos que la ficha estuvo viva
        int obtenerTurnos();
        //pre
        //post devuelve la columna en la que se encuentra la ficha
        int obtenerColumna();
        //pre
        //post devuelve la columna en la que se encuentra la ficha
        int obtenerFila();
        //pre
        //post disminuye en 1 la fila en 1la que se encuentra la ficha
        void disminuirFila();
        //pre
        //post cambia la ficha anterior de la ficha actual
        void cambiarFichaAnterior(Ficha* nuevaFichaAnterior);
        //pre
        //post cambia la ficha posterior de la ficha actual
        void cambiarFichaPosterior(Ficha* nuevaFichaPosterior);
        //pre
        //post obtiene la ficha anterior de la ficha actual
        Ficha* obtenerFichaAnterior();
        //pre
        //post obtiene la ficha posterior de la ficha actual
        Ficha* obtenerFichaPosterior();

};
Ficha* Ficha::obtenerFichaPosterior()
{
    return this->fichaPosterior;
}
Ficha* Ficha::obtenerFichaAnterior()
{
    return this->fichaAnterior;
}
void Ficha::cambiarFichaPosterior(Ficha* nuevaFichaPosterior)
{
    this->fichaPosterior=nuevaFichaPosterior;
}
void Ficha::cambiarFichaAnterior(Ficha* nuevaFichaAnterior)
{
    this->fichaAnterior=nuevaFichaAnterior;
}
void Ficha::disminuirFila()
{
    this->fila--;
}

int Ficha::obtenerFila()
{
    return this->fila;
}
int Ficha::obtenerColumna()
{
    return this->columna;
}
Ficha::Ficha(unsigned int columna,unsigned int fila)
{
    this->energia = 0;
    this->jugador = 0;
    this->turnos = 0;
    this->columna =columna;
    this->fila=fila;
    this->fichaAnterior=0;
    this->fichaPosterior=0;

}
unsigned int Ficha::obtenerJugador()
{
    return this->jugador;
}
void Ficha::cambiarJugador(unsigned int nuevoJugador)
{
    this->jugador = nuevoJugador;
}

int Ficha::obtenerEnergia()
{
    return this->energia;
}
void Ficha::fluctuacionDeEnergia(int energiaFluctuada)
{
    this->energia = (this->energia + energiaFluctuada);
    if (this->energia < ENERGIAMINIMA){this->energia = ENERGIAMINIMA;}
    else if(this->energia > ENERGIAMAXIMA){this->energia = ENERGIAMAXIMA; };

}
void Ficha::aumentarTurnos()
{
    this->turnos++;
}
int Ficha::obtenerTurnos()
{
    return this->turnos;
}

#endif // FICHA_H
