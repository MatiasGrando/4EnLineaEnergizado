#ifndef FILA_H
#define FILA_H
#include "Ficha.h"


class Fila
{
    public:
        Fila();
        ~Fila();
        Lista<Ficha*>*  obtenerFilas();


    private:
        Lista<Ficha*>* filasDeFichas;
};
Fila::Fila()
{
    this->filasDeFichas=new Lista<Ficha*>;
}
Fila::~Fila()
{
    delete obtenerFilas();
}

Lista<Ficha*>* Fila::obtenerFilas()
{
    return this->filasDeFichas;
}
#endif // FILA_H
