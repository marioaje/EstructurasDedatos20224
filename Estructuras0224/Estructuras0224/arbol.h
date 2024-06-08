//Arbol que viene de el main lo pasamos a un archivo h
//Los archivos h, son cabaceras, tienes estructuras y funciones
//arbol.h
#ifndef  ARBOL_H
#define ARBOL_H

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

NodoArbol* crearNodo(int dato);
NodoArbol* insertar(NodoArbol* raiz, int dato);
void imprimirlos(NodoArbol* raiz);



#endif //  ARBOL_H


