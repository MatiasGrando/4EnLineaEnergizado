#ifndef INDICECOLUMNA_H
#define INDICECOLUMNA_H
#include "Columna.h"

class IndiceColumna
{
    public:
        //pre
        //post crea una lista de punteros a Columnas
        IndiceColumna();
        //pre
        //post libera la memoria pedida para crear la lista
        ~IndiceColumna();
        //pre lista creada
        //post devuelve la direccion para poder acceder a la lista de punteros a columnas
        Lista<Columna*>* obtenerColumnas();

    private:
        Lista<Columna*>* listaColumnas;
};

IndiceColumna::IndiceColumna()
{
    this->listaColumnas=new Lista<Columna*>;
}
IndiceColumna::~IndiceColumna()
{
    delete obtenerColumnas();
}

Lista<Columna*>* IndiceColumna::obtenerColumnas()
{
    return this->listaColumnas;
}

#endif // INDICECOLUMNA_H
