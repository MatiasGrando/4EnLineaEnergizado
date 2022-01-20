#include "Lista.h"
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
        this->primero= this->primero->obtenerSiguiente();
        delete cursor;
    }
}
template <typename T>
void Lista<T>::iniciarCursor()
{
    this->cursor=this->primero;
}
template <typename T>
bool Lista<T>::avanzarCursor()
{
    this->cursor = this->cursor->obtenerSiguiente();
    return(this->cursor !=0);
}
template <typename T>
void Lista<T>::retrocederCursor()
{
    this->cursor = this->cursor->obtenerAnterior();
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
    if (!listaVacia())
    {
        this->ultimo->cambiarSiguiente(nuevoElemento);
        this->ultimo = nuevoElemento;
    }
    else
    {
        this->primero=nuevoElemento;
        this->ultimo=nuevoElemento;
    }
}
template <typename T>
void Lista<T>::eliminarElemento(Nodo<T>* cursor)
{
    if(cursor == this->ultimo)
    {
        obtenerAnterior(cursor)->cambiarSiguiente(0);
        this->ultimo=obtenerAnterior(cursor);
        delete cursor;
    }
    else if (cursor == this->primero)
    {
        obtenerSiguiente(cursor)->cambiarAnterior(0);
        this->primero = obtenerSiguiente(cursor);
        delete cursor;
    }
    else
    {
        obtenerAnterior(cursor)->cambiarSiguiente(obtenerSiguiente(cursor));
        obtenerSiguiente(cursor)->cambiarAnterior(obtenerAnterior(cursor));
        delete cursor;
    }
}

