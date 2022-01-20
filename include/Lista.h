#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include "Ficha.h"

template <typename T>
class Lista
{
    private:
        Nodo<T>* primero;
        Nodo<T>* ultimo;
        Nodo<T>* cursor;
        unsigned int tamanio;

    public:
       //pre:
       //post: crea una lista vacia
       Lista();
       //pre:lista creada
       //post: libera la memoria pedida
       ~Lista();
       //pre; lista debe estar creada y la posicion debe ser valida, en caso contrario no eliminara ningun dato
       //post: elimina el nodo de la posicion dada
       void eliminarElementoPosicion(unsigned int posicion);
       //pre:lista no vacia
       //post: elemina un elemento de la lista

       void eliminarElemento(Nodo<T>* cursor);
       //pre:
       //post: agrega un nodo al final de la lista

       void agregarElemento(T nuevoDato);
       //pre:
       //post: devuelve V si la lista esta vacia

       bool listaVacia();
       //pre:
       //post: devuelve el tamanio de la lista

       unsigned int obtenerTamanio();
       //pre lista creada
       //post devuelve un puntero al ultimo nodo

       Nodo<T>* obtenerUltimo();

    //-----------------------------------------
        //pre:lista no vacia
       //post: unicia el cursor en la primera poscision
       void iniciarCursor();
       //pre:cursor inicializado
       //post: develve V si se puede avaanzar
        //     avanza una posicion el cursor
        // en caso contrario devuelve F y no hace nada
       bool avanzarCursor();
       //pre:lista no vacia
       //post: unicia el cursor en la ultima poscision
       void iniciarCursorUltimo();
       //pre:cursor inicializado
       //post: develve V si se puede retroceder
        //     retrocede una posicion el cursor
        //     en caso contrario devuelve F y no hace nada
       bool retrocederCursor();
       //pre: cursor se haya inicializado
       //post: devuelve un puntero al nodo al q apunta el cursor
       Nodo<T>* obtenerCursor();
};


template <typename T>
Lista<T>::Lista()
{
    primero=0;
    ultimo=0;
    tamanio=0;
    cursor=0;
}
template <typename T>
Lista<T>::~Lista()
{
    while(primero != 0)
    {
        iniciarCursor();
        delete cursor->obtenerDato();
        this->primero= this->primero->obtenerSiguiente();
        delete cursor;
    }
}
template <typename T>
Nodo<T>* Lista<T>::obtenerUltimo()
{
     return (this->ultimo);
}
template <typename T>
void Lista<T>::iniciarCursor()
{
    this->cursor=this->primero;
}
template <typename T>
void Lista<T>::iniciarCursorUltimo()
{
    this->cursor = this->ultimo;
}
template <typename T>
bool Lista<T>::avanzarCursor()
{
    this->cursor = (this->cursor->obtenerSiguiente());
    return(this->cursor !=0);
}
template <typename T>
bool Lista<T>::retrocederCursor()
{
    this->cursor = this->cursor->obtenerAnterior();
    return (this->cursor != 0);
}

template <typename T>
Nodo<T>* Lista<T>::obtenerCursor()
{
    return this->cursor;
}
template <typename T>
bool Lista<T>::listaVacia()
{
    return (this->primero==0);
}
template <typename T>
void Lista<T>::agregarElemento(T nuevoDato)
{
    Nodo<T>* nuevoElemento = new Nodo<T>(nuevoDato);
    this->tamanio++;
    if (!listaVacia())
    {
        this->ultimo->cambiarSiguiente(nuevoElemento);
        nuevoElemento->cambiarAnterior(this->ultimo);
        this->ultimo = nuevoElemento;
    }
    else
    {
        this->primero=nuevoElemento;
        this->ultimo=nuevoElemento;
    }
}
template <typename T>
void Lista<T>::eliminarElementoPosicion(unsigned int posicion)
{
    if (obtenerTamanio()>=posicion)
    {
        iniciarCursor();
        for (unsigned int i=1; i<posicion;i++)
        {
            avanzarCursor();
        }
        eliminarElemento(obtenerCursor());
    }
}
template <typename T>
void Lista<T>::eliminarElemento(Nodo<T>* cursor)
{
    if(cursor->esElUltimo())
    {
        cursor->obtenerAnterior()->cambiarSiguiente(0);
        this->ultimo=cursor->obtenerAnterior();
        delete cursor->obtenerDato();
        delete cursor;
    }
    else if (cursor->esElPrimero())
    {
        cursor->obtenerSiguiente()->cambiarAnterior(0);
        this->primero = cursor->obtenerSiguiente();
        delete cursor->obtenerDato();
        delete cursor;
    }
    else
    {
        cursor->obtenerAnterior()->cambiarSiguiente(cursor->obtenerSiguiente());
        cursor->obtenerSiguiente()->cambiarAnterior(cursor->obtenerAnterior());
        delete cursor->obtenerDato();
        delete cursor;
    }
}
template <typename T>
unsigned int Lista<T>::obtenerTamanio()
{
    return this-> tamanio;
}


#endif // LISTA_H
