// Estructuras0224.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "arbol.h"
#include "b_tree.h"


//Definimos nuestra estructura, similar 
//como cuando hacemos una clase
// 
//Puntero centro (El puntero es un espacio 
//en memoria que reservamos)
//Este seria el padre
//struct NodoArbol {
//    //Se definen atributos
//    int dato;//string, arreglo,
//    struct NodoArbol* izquierda;
//    //Que esto seria un puntero izquierda
//    //Es el hijo izquiero
//    struct NodoArbol* derecha;
//    //Que esto seria un puntero derecha
//    //El hijo derecho
//};
//
//
/////Crear el arbol???
//
////Crear el nodo, fue el 23 ingreso en datosEnviadosPorElUsuario
//struct NodoArbol* crearNodo(int datosEnviadosPorElUsuario) {
//    struct NodoArbol* nuevoNodo = (struct NodoArbol*)malloc(sizeof(struct NodoArbol));
//    nuevoNodo->dato = datosEnviadosPorElUsuario;
//    nuevoNodo->derecha = NULL;
//    nuevoNodo->izquierda = NULL;
//
//    return nuevoNodo;
//}
//
//struct NodoArbol* insertar(struct NodoArbol* raiz, int datosEnviadosPorElUsuario) {
//    //14 9 85
//    if (raiz == NULL) {
//        return crearNodo(datosEnviadosPorElUsuario);
//    }
//    //era un 17 raiz->dato
//    if (datosEnviadosPorElUsuario < raiz->dato) {
//        raiz->izquierda = insertar(raiz->izquierda, datosEnviadosPorElUsuario);
//    }
//    else if (datosEnviadosPorElUsuario > raiz->dato) {
//        raiz->derecha = insertar(raiz->derecha, datosEnviadosPorElUsuario);
//    }
//
//    return raiz;
//}
//
//void imprimirlos(struct NodoArbol* raiz) {
//    if (raiz != NULL)
//    {
//        imprimirlos(raiz->izquierda);
//        std::cout << " <--" << raiz->dato << " --> ";
//        imprimirlos(raiz->derecha);
//    }
//}


//Arbol Balanceado ejemplo*******************************************************

//Estructura del Nodo base
struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;

    int altura;
};

int obtenerAltura(Nodo* elNodo){
    if (elNodo == nullptr)//si viene el puntero vacio
    {
        return 0;//regresa la altura, si no tiene nada devuelve 0
    }

    return elNodo->altura;
}

int obtenerMaximo(int a, int b) {
    //(a > b) ? a : b =>
  /*  if (a > b) {
        return a;
    }
    else {
        return b;
    }*/
    return (a > b) ? a : b;
}

//Esta funcion permite crear un nodo, enviandole un dato
//e incrementando 1 en su altura.
Nodo* crearElNodo(int datosEnviadorUsuario) {
    Nodo* nodoNuevo = new Nodo();
    nodoNuevo->dato = datosEnviadorUsuario;
    nodoNuevo->izquierda = nullptr;
    nodoNuevo->derecha = nullptr;
    nodoNuevo->altura = 1; //cada vez uno nuevo la altura seria 1
    return nodoNuevo;
}


//Las operaciones
Nodo* rotarDerecha(Nodo* nodoBase) {
    Nodo* temp = nodoBase->izquierda;
    Nodo* temp2 = nodoBase->derecha;


    //Girar los datos, procesar los datos, o rotar datos
    temp->derecha = nodoBase;
    nodoBase->izquierda = temp2;


    //Modificar la base, (la altura)
    nodoBase->altura = obtenerMaximo(obtenerAltura(nodoBase->izquierda), obtenerAltura(nodoBase->derecha)) + 1;
    temp->altura = obtenerMaximo(obtenerAltura(temp->izquierda), obtenerAltura(temp->derecha)) + 1;

    return temp;
}

//Rotacion a la izquierda
Nodo* rotarIzquiera(Nodo* nodoBase) {
    Nodo* temp = nodoBase->derecha;
    Nodo* temp2 = nodoBase->izquierda;


    //Girar los datos, procesar los datos, o rotar datos
    temp->izquierda = nodoBase;
    nodoBase->derecha = temp2;


    //Modificar la base, (la altura)
    nodoBase->altura = obtenerMaximo(obtenerAltura(nodoBase->izquierda), obtenerAltura(nodoBase->derecha)) + 1;
    temp->altura = obtenerMaximo(obtenerAltura(temp->izquierda), obtenerAltura(temp->derecha)) + 1;

    return temp;
}

int obtenerBalance(Nodo* elNodo) {
    if (elNodo == nullptr) {
        return 0;
    }
    
    return obtenerAltura(elNodo->izquierda) - obtenerAltura(elNodo->derecha);

 }

Nodo* insertarDatosNodo(Nodo* elNodoEnviado, int datoEnviado) {

    //Analiza si el puntero viene vacio, y lo crea, con el dato enviado
    if (elNodoEnviado == nullptr) {
        return crearElNodo(datoEnviado);
    }

    //7 < 10
    if (datoEnviado < elNodoEnviado->dato) {
        elNodoEnviado->izquierda = insertarDatosNodo(elNodoEnviado->izquierda, datoEnviado);
    }
    //10 > 8
    else if (datoEnviado > elNodoEnviado->dato) {
        elNodoEnviado->derecha = insertarDatosNodo(elNodoEnviado->derecha, datoEnviado);
    }
    //8 8
    else {
        return elNodoEnviado;
    }

    //A la altura le suma 1 obteniendo el valor maximo de izq y der
    elNodoEnviado->altura = 1 + obtenerMaximo(obtenerAltura(elNodoEnviado->izquierda), obtenerAltura(elNodoEnviado->izquierda));

    int balance = obtenerBalance(elNodoEnviado); //Puede ser mayor a 1 o menor a -1
    //8 > 90
    //Rotamos hacia la derecha
    if (balance > 1 && datoEnviado < elNodoEnviado->izquierda->dato) {
        return rotarDerecha(elNodoEnviado);
    }

    if (balance > 1 && datoEnviado > elNodoEnviado->izquierda->dato) {
        elNodoEnviado->izquierda = rotarIzquiera(elNodoEnviado->izquierda);
        return rotarDerecha(elNodoEnviado);
    }


    //Rotamos hacia la izquierda
    if (balance < -1 && datoEnviado > elNodoEnviado->derecha->dato) {
        return rotarIzquiera(elNodoEnviado);
    }

    if (balance < -1 && datoEnviado < elNodoEnviado->derecha->dato) {
        elNodoEnviado->derecha = rotarDerecha(elNodoEnviado->derecha);
        return rotarIzquiera(elNodoEnviado);
    }

    return elNodoEnviado;
}


void recorridoEnOrden(Nodo* elNodoEnviado) {
    if (elNodoEnviado != nullptr)
    {
        recorridoEnOrden(elNodoEnviado->izquierda);
        std::cout << elNodoEnviado->dato << " ";
        recorridoEnOrden(elNodoEnviado->derecha);
    }
}


int main()
{
    BTree t(4);

    t.insert(10);
    t.insert(20);
    t.insert(1);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(15);
    t.insert(30);


    //Buscamos en el arbol y lo recorremos en un orden???




  //  std::cout << "Hello ArbolBinario!\n";

  //  //Esto es paa ABB

  // /* Nodo* raizABB = nullptr;

  //  raizABB = insertarDatosNodo(raizABB, 112);
  //  raizABB = insertarDatosNodo(raizABB, 22);
  //  raizABB = insertarDatosNodo(raizABB, 132);
  //  raizABB = insertarDatosNodo(raizABB, 5);
  //  raizABB = insertarDatosNodo(raizABB, 22);
  //  raizABB = insertarDatosNodo(raizABB, 4);
  //  raizABB = insertarDatosNodo(raizABB, 12);
  //  raizABB = insertarDatosNodo(raizABB, 15);
  //  raizABB = insertarDatosNodo(raizABB, 18);
  //raizABB = insertarDatosNodo(raizABB, 112);
  //  raizABB = insertarDatosNodo(raizABB, 22);
  //  raizABB = insertarDatosNodo(raizABB, 132);
  //  raizABB = insertarDatosNodo(raizABB, 312);*/
  ///*  raizABB = insertarDatosNodo(raizABB, 312);
  //  raizABB = insertarDatosNodo(raizABB, 2);
  //  raizABB = insertarDatosNodo(raizABB, 7);
  //  raizABB = insertarDatosNodo(raizABB, 12);
  //  raizABB = insertarDatosNodo(raizABB, 1);
  //  raizABB = insertarDatosNodo(raizABB, 8);
  //  raizABB = insertarDatosNodo(raizABB, 11);
  //  raizABB = insertarDatosNodo(raizABB, 21);
  //  raizABB = insertarDatosNodo(raizABB, 3);*/

  ///*  std::cout << "Los elementos del ABB son???";
  //  recorridoEnOrden(raizABB);*/



  //  

  //  //Esto es para binario
  //  NodoArbol* raiz = NULL;
  //  raiz = insertar(raiz, 12);
  //  raiz = insertar(raiz, 15);
  //  raiz = insertar(raiz, 18);
  //  raiz = insertar(raiz, 112);
  //  raiz = insertar(raiz, 22);
  //  raiz = insertar(raiz, 132);
  //  raiz = insertar(raiz, 312);
  //  raiz = insertar(raiz, 2);
  //  raiz = insertar(raiz, 7);
  //  raiz = insertar(raiz, 12);
  //  raiz = insertar(raiz, 1);
  //  raiz = insertar(raiz, 8);


  //  std::cout << "Los elementos del arbol son???";
  //  imprimirlos(raiz);

    system("pause");
    return 0;
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
