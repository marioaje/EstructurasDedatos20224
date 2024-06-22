// ConsoleGrafos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;



//La clase que guarda el grafo o la informacion
class Grafo {
private:
    int Vertices;//numero de vertices
    vector<vector<int>> adj;//al verctor de las listas de las adyancencia 


public:
    //Contructor inicializa con //numero de vertices
    Grafo(int Vertices) {
        this->Vertices = Vertices; //numero de vertices
        adj.resize(Vertices);//Esto se ajusta a la cantidad de vertices, 
        //para que el vector tenga el numero de adyancencias
    }


    //Metodos
    //U va ser la lista representada, y v el dato a incrustar.
    void agregarAristas(int u, int v) {
        adj[u].push_back(v);//añadir el dato a la lista
    }

    void imprimirGrafo() {
        for (int i = 0; i < Vertices; i++) {
            cout << "Vertice: " << i << " --- ";
            for (auto item : adj[i]) {//se aplica un foreach, para recorrer dinamicamente la lista
                cout << "item: " << item << " --- ";
            }
            cout << endl;
        }
    }
};


int main()
{
    std::cout << "Hello World!\n";

    Grafo grafo(5);
    //Agregamos datos
    grafo.agregarAristas(0, 1);
    grafo.agregarAristas(0, 4);
    grafo.agregarAristas(1, 1);
    grafo.agregarAristas(1, 3);
    grafo.agregarAristas(1, 4);
    grafo.agregarAristas(2, 1);
    grafo.agregarAristas(2, 3);
    grafo.agregarAristas(3, 4);
    //grafo.agregarAristas(6, 6);


    cout << "Impresion" << endl;
    grafo.imprimirGrafo();

    return 0;

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
