#ifndef COLUMNA_H
#define COLUMNA_H
#include "Ficha.h"


class Columna
{
    public:
        //pre
        //post crea una lista de punteros a ficha
        Columna();
        //pre
        //post libera la memoria pedida para crear la lista
        ~Columna();
        //pre lista debe estar creada
        //post obtiene la direccion de la lista
        Lista<Ficha*>*  obtenerColumna();


    private:
        Lista<Ficha*>* ColumnaDeFichas;
};
Columna::Columna()
{
    this->ColumnaDeFichas=new Lista<Ficha*>;
}
Columna::~Columna()
{
    delete obtenerColumna();
}

Lista<Ficha*>* Columna::obtenerColumna()
{
    return this->ColumnaDeFichas;
}

#endif // COLUMNA_H
