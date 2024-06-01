// Estructuras0224.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <stdio.h>
#include <stdlib.h>
#include <iostream>


//Definimos nuestra estructura, similar 
//como cuando hacemos una clase
// 
//Puntero centro (El puntero es un espacio 
//en memoria que reservamos)
//Este seria el padre
struct NodoArbol {
    //Se definen atributos
    int dato;//string, arreglo,
    struct NodoArbol* izquierda;
    //Que esto seria un puntero izquierda
    //Es el hijo izquiero
    struct NodoArbol* derecha;
    //Que esto seria un puntero derecha
    //El hijo derecho
};


///Crear el arbol???

//Crear el nodo, fue el 23 ingreso en datosEnviadosPorElUsuario
struct NodoArbol* crearNodo(int datosEnviadosPorElUsuario) {
    struct NodoArbol* nuevoNodo = (struct NodoArbol*)malloc(sizeof(struct NodoArbol));
    nuevoNodo->dato = datosEnviadosPorElUsuario;
    nuevoNodo->derecha = NULL;
    nuevoNodo->izquierda = NULL;

    return nuevoNodo;
}

struct NodoArbol* insertar(struct NodoArbol* raiz, int datosEnviadosPorElUsuario) {
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

void imprimirlos(struct NodoArbol* raiz) {
    if (raiz != NULL)
    {
        imprimirlos(raiz->izquierda);
        std::cout << " <--" << raiz->dato << " --> ";
        imprimirlos(raiz->derecha);
    }
}

int main()
{
    std::cout << "Hello ArbolBinario!\n";

    struct NodoArbol* raiz = NULL;
    raiz = insertar(raiz, 12);
    raiz = insertar(raiz, 15);
    raiz = insertar(raiz, 18);
    raiz = insertar(raiz, 112);
    raiz = insertar(raiz, 22);
    raiz = insertar(raiz, 132);
    raiz = insertar(raiz, 312);
    raiz = insertar(raiz, 2);
    raiz = insertar(raiz, 7);
    raiz = insertar(raiz, 12);
    raiz = insertar(raiz, 1);
    raiz = insertar(raiz, 8);


    std::cout << "Los elementos del arbol son???";
    imprimirlos(raiz);
    //????
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
