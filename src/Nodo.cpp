#include "Nodo.h"
template < typename T >
Nodo<T>::Nodo(T nuevoDato)
{
        this->dato = nuevoDato;
        this->nodoSiguiente=0;
        this->nodoAnterior=0;
}
template < typename T >
Nodo<T>* Nodo<T>::obtenerSiguiente()
{
    return this->nodoSiguiente;
}
template < typename T >
Nodo<T>* Nodo<T>::obtenerAnterior()
{
    return this->nodoAnterior;
}
template < typename T >
void Nodo<T>::cambiarSiguiente(Nodo<T>* siguiente)
{
    this->nodoSiguiente = siguiente;
}
template < typename T >
void Nodo<T>::cambiarAnterior(Nodo<T>* anterior)
{
    this->nodoAnterior = anterior;
}
template < typename T >
void Nodo<T>::cambiarDato(T nuevoDato)
{
    this->dato =nuevoDato;
}
template < typename T >
T Nodo<T>::obtenerDato()
{
    return this->dato;
}
template < typename T >
bool Nodo<T>::esElUltimo()
{
    return (this->nodoSiguiente !=0);
}
template < typename T >
bool Nodo<T>::esElPrimero()
{
    return(this->nodoAnterior !=0);
}
