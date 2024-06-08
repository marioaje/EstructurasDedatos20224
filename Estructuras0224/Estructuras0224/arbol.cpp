//arbol.cpp
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "arbol.h";


//Crear el nodo, fue el 23 ingreso en datosEnviadosPorElUsuario
NodoArbol* crearNodo(int datosEnviadosPorElUsuario) {
    struct NodoArbol* nuevoNodo = ( NodoArbol*)malloc(sizeof( NodoArbol));
    nuevoNodo->dato = datosEnviadosPorElUsuario;
    nuevoNodo->derecha = NULL;
    nuevoNodo->izquierda = NULL;

    return nuevoNodo;
}

NodoArbol* insertar(NodoArbol* raiz, int datosEnviadosPorElUsuario) {
    //14 9 85
    if (raiz == NULL) {
        return crearNodo(datosEnviadosPorElUsuario);
    }
    //era un 17 raiz->dato
    if (datosEnviadosPorElUsuario < raiz->dato) {
        raiz->izquierda = insertar(raiz->izquierda, datosEnviadosPorElUsuario);
    }
    else if (datosEnviadosPorElUsuario > raiz->dato) {
        raiz->derecha = insertar(raiz->derecha, datosEnviadosPorElUsuario);
    }

    return raiz;
}

void imprimirlos( NodoArbol* raiz) {
    if (raiz != NULL)
    {
        imprimirlos(raiz->izquierda);
        std::cout << " <--" << raiz->dato << " --> ";
        imprimirlos(raiz->derecha);
    }
}
