#include <iostream>
#include <string>
#include <limits.h>

#define INF INT16_MAX

using namespace std;

//Time Complexity of the hole function: O(|V|+|V|^2(2+|V|))
//But the main algorithm is O(|V|^3)
//V = {x|x∈{set of vertex in a graph}}
void FW(int** M, int V){
    //Copy of matrix
    int** resultMatrix = new int*[V];

    for(int i=0;i<V;i++){
        resultMatrix[i] = new int[V];
    }

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            (M[i][j] == -1) ? (resultMatrix[i][j]=INF) : resultMatrix[i][j] = M[i][j];
        }
    }

    //Main algorithm
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(resultMatrix[i][k] + resultMatrix[k][j] < resultMatrix[i][j]){
                    resultMatrix[i][j] = resultMatrix[i][k] + resultMatrix[k][j];
                }
            }
        }
    }


    //Print the matrix
    for(int i=0;i<V;i++){
        if(i!=0)cout<<endl;
        for(int j=0;j<V;j++){
            cout<<resultMatrix[i][j]<<" ";
        }
    }
}