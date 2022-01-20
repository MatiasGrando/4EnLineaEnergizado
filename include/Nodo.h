#ifndef NODO_H
#define NODO_H


template <typename T>
class Nodo
{
    private:
        T dato;
        Nodo<T>* nodoSiguiente;
        Nodo<T>* nodoAnterior;
    public:
        //pre:
       //post:crea un nuevo nodo con el nuevoDato

        Nodo(T nuevoDato);
        //pre:
       //post: devuelve el siguiente elemento, en caso de ser el ultimo devuelve 0

        Nodo<T>* obtenerSiguiente();
        //pre:
       //post: devuelve el elemento anterior, en caso de ser el primero devuelve 0

        Nodo<T>* obtenerAnterior();
        //pre:
       //post: cambia el nodoSiguiente del nodo

        void cambiarSiguiente(Nodo<T>* siguiente);
        //pre:
       //post: cambia el nodoAnterior del nodo

        void cambiarAnterior(Nodo<T>* anterior);
        //pre:
       //post: Modifica el dato del nodo

        void cambiarDato(T nuevoDato);
        //pre:
       //post: devuelve el dato del nodo

        T obtenerDato();
        //pre:
       //post: Devuelve V si es el ultimo elemento

        bool esElUltimo();
        //pre:
       //post: devuelve V si es el primero elemento

        bool esElPrimero();



};
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
    return (this->nodoSiguiente ==0);
}
template < typename T >
bool Nodo<T>::esElPrimero()
{
    return(this->nodoAnterior == 0);
}

#endif // NODO_H
