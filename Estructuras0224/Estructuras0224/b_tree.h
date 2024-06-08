#pragma once
//Las estructuras y funciones
//b_tree.h(h de encabezado o head)
#ifndef B_TREE_H
#define B_TREE_H

//[][][][]
#include <iostream>
#include <vector>

//B Arbol Nodo
class BTreeNode {

public:
	bool leaf; // es una hoja del nodo
	std::vector<int> keys;//las llaves que recibimos
	std::vector< BTreeNode*> children;//El arreglo de hijos que se encuentra en
	//el nodo.

	BTreeNode(bool leaf);

};


//La estructura del arbol B
class BTree {
	public:
		BTree(int t);//los datos que se envian por el usuario o el sistema
		void insert(int k);//El siguiente parametro que se envia se reubica
		void traverse();//Funcion auxilar para recorrer el arbol o nodo

	private:
		BTreeNode* root;
		int t = 3;//minimo de llaves que se puedan tener, grado de elementos
		void insertNotFull(BTreeNode* node, int k);//la idea con esta funcion es replicar los null
			//[12], [14], [], []
		//Divide el hijo y lo sube como un padre
		void splitChild(BTreeNode* parent, int i, BTreeNode* y);
		void traverse(BTreeNode* node);//Funcion de recorrido
		//temporal o auxiliar
};

#endif // B_TREE_H
