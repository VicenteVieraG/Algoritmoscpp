/*
    Fecha de creación: 13-10-22
    Ultima fecha de modificación: 14-10-22

    Actividad 3.2: Implementación de "Dijkstra and Floyd"

    Equipo: 
    - Vicente Javier Viera Guízar | A01639784
    - Renet de Jesús Pérez Gómez | A01640555

    Breve explicacion del código
    Este codigo es la solución a la actividad 3.2, en la cual debemos implementar los algoritmos de Dijkstra y Floyd.

    El programa recibe como entrada un archivo txt con el grafo, el formato del archivo debe de ser:
        - Numero de archivo
        - Matriz de adyacencia (grafo) 

    Una vez el programa obtiene la informacion y la acomoda en una matriz, se pasa por medio de punteros
    a las funciones para ejecutarse y generar la respuesta.

    Primero se ejecuta el algoritmo de Dijkstra y despues el algoritmo de Floyd.
    En ambos casos nos darán el resultado con rutas con la menor distancia posible.
*/

#include <iostream>
#include "floyd-warshall.h"
#include "dijkstra.h"

using namespace std;

int main(int argc, char** argv){
    //Vertex number
    int V = 0;
    cin>>V;

    //Create the matrix
    int** matrix = new int*[V];

    for(int i=0;i<V;i++){
        matrix[i] = new int[V];
    }

    int aux = 0;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>aux;
            matrix[i][j] = aux;
        }
    }

    //Algorithms execution
    cout<<"dijkstra's algorithm"<<endl;
    dijkstraAlgorithm(V, matrix);
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"floyd-warshall's algorithm"<<endl;
    FW(matrix, V);

    return 0;
}