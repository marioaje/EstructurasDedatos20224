//
////B Arbol Nodo
//class BTreeNode {
//
//public:
//	bool leaf; // es una hoja del nodo
//	std::vector<int> keys;//las llaves que recibimos
//	std::vector< BTreeNode*> children;//El arreglo de hijos que se encuentra en
//	//el nodo.
//
//	BTreeNode(bool leaf);
//
//};
//
//
////La estructura del arbol
//class BTree {
//public:
//	BTree(int t);//los datos que se envian por el usuario o el sistema
//	void insert(int k);//El siguiente parametro que se envia se reubica
//	void traverse();//Funcion auxilar para recorrer el arbol o nodo
//
//private:
//	BTreeNode* root;
//	int t = 3;//minimo de llaves que se puedan tener
//	void insertNotFull(BTreeNode* node, int k);//la idea con esta funcion es replicar los null
//		//[12], [14], [], []
//	//Divide el hijo y lo sube como un padre
//	void splitChild(BTreeNode* parent, int i, BTreeNode* y);
//	void traverse(BTreeNode* node);
//};
#include "b_tree.h"


////La estructura del nodo
BTreeNode::BTreeNode(bool leaf) {
	this->leaf = leaf;
}


////La estructura del arbol
BTree::BTree(int t) {
	this->root = nullptr;
	this->t = t;//Cantidad de elementos
}

void BTree::traverse() {
	if (root != nullptr) traverse(root);
}

void BTree::traverse(BTreeNode* node) {
	int i;
	//Recuerden que en el nodo, trae los elementos(llaves)
	for (i = 0; i < node->keys.size(); i++) {
		if (!node->leaf) traverse(node->children[i]);//[12], [14], [], []
		std::cout << " " << node->keys[i];//Imprime los que estan disponibles
	}
	//Verifica que la hoja no tenga datos
	if (!node->leaf) traverse(node->children[i]);
}

//Inserta un elemento o clave en el BTree
void BTree::insert(int k) {
	//int k nuestro parametro de envio 
	if (root == nullptr) {
		//leaf
		root = new BTreeNode(true);
		root->keys.push_back(k);//insertamos la nuevo llave en el array
	}
	else {
		//El máximo número de claves por nodo es m-1. m=t
		if (root->keys.size() == 2 * t - 1) {
			BTreeNode* s = new BTreeNode(false);
			s->children.push_back(root);
			splitChild(s, 0, root);
			int i = 0;
			if (s->keys[0] < k) i++;
			insertNotFull(s->children[i], k);
			root = s;
		}
	}

}

//	void insertNotFull(BTreeNode* node, int k);//la idea con esta funcion es replicar los null
//splitChild(BTreeNode* parent, int i, BTreeNode* y);
void BTree::insertNotFull(BTreeNode* node, int k) {
	int i = node->keys.size() - 1;//obtiene la posicion nueva 
	//con la cantidad de elementos en el arreglo

	if (node->leaf) {
		node->keys.push_back(0);
		while (i >= 0 && node->keys[i] > k) {
			node->keys[i + 1] = node->keys[i];//Mueve el elemento al
			//siguiente espacio del arreglo
			i--;
		}
		node->keys[1 + i] = k;
	}
	else {
		while (i >= 0 && node->keys[i] > k) i--;
		//4 +1
		i++;
		if (node->children[i]->keys.size() == 2 * t - 1){
			splitChild(node, i, node->children[i]);
			if (node->keys[i] < k) i++;
		}
		insertNotFull(node->children[i], k);
	}

}


void BTree::splitChild(BTreeNode* parent, int i, BTreeNode* y) {
	//int i es los elementos
	BTreeNode* z = new BTreeNode(y->leaf);//creacion de un nodo temporal
	//para moverme dentro del nodo
	z->keys.resize(t - 1);

	//uso j en lugar de i, porque la i, ya viene como parametro
	for (int j = 0; j < t - 1; j++)
		z->keys[j] = y->keys[j + 1];//lo mueve hacia la derecha el elemento
	if (!y->leaf) {
		//	this->t = t;//Cantidad de elementos
		z->children.resize(t);
		for (int j = 0; j < t; j++)
			z->children[j] = y->children[j + t];
	}
	y->keys.resize(t - 1);

	//nodo base
	//los elementos int i
	parent->children.insert(parent->children.begin() + i + 1, z);
	// a la llave le suma el elemento
	//El mínimo número de claves por nodo es (m/2)-1.
	parent->keys.insert(parent->keys.begin() + i, y->keys[t - 1]);

}

//void insert(int k);//El siguiente parametro que se envia se reubica
//	void traverse();//Funcion auxilar para recorrer el arbol o nodo
//	void splitChild(BTreeNode* parent, int i, BTreeNode* y);
