#include <iostream>

#define NCOLORS 4

using namespace std;

void printSolution(int* color, int V){
    for (int i=0;i<V;i++){
        cout<<"Node: "<<i<<","<<"Assigned Color: "<<color[i]-1<<endl;
    }
}

bool isSafe(int v, int** M, int* color, int c, int V){
    for(int i=0;i<V;i++){
        if(M[v][i] && c == color[i])return false;
    }

    return true;
}

bool graphColoringUtil(int** M, int m, int* color, int v, int V){
    if(v == V)return true;

    for(int c=1;c<=m;c++){
        if(isSafe(v, M, color, c, V)){
            color[v] = c;
            if(graphColoringUtil(M, m, color, v + 1, V) == true)return true;

            color[v] = 0;
        }
    }

    return false;
}

bool graphColoring(int** M, int m, int V){
    int* color = new int[V];
    for(int i=0;i<V;i++)color[i] = 0;

    if(graphColoringUtil(M, m, color, 0, V) == false){
        cout << "Solution does not exist";
        return false;
    }

    printSolution(color, V);
    return true;
}

int main(){
    int V;
    cin>>V;

    //Create the matrix
    int** M = new int*[V];

    for(int i=0;i<V;i++){
        M[i] = new int[V];
    }

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>M[i][j];
        }
    }

    graphColoring(M, NCOLORS, V);

    return 0;
}