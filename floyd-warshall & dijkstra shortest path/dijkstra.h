bool allPathFind(bool *arrSolution, int size){
    for(int i = 0; i < size; i++){
        if(!arrSolution[i]) {
            return 1;
        }
    }

    return 0;
}


void dijkstraAlgorithm(int sizeOfGraph, int **matrix){
    int** matGraph = new int*[sizeOfGraph];

    for(int i = 0; i < sizeOfGraph; i++){
        matGraph[i] = new int [sizeOfGraph];
    }

    for(int i = 0; i < sizeOfGraph; i++){
        for(int j=0; j < sizeOfGraph; j++){
            matGraph[i][j] = matrix[i][j];
        }
    }

    

    // int matGraph[sizeOfGraph][sizeOfGraph] = 
    // {
    //     {0, 2, -1, 3},
    //     {-1, 0, 1, 5},
    //     {2, 3, 0, -1},
    //     {3, -1, 4, 0}   
    // };
    
    // int matGraph[sizeOfGraph][sizeOfGraph] = 
    // {
    //     {-1, 4, -1, -1, -1, -1, -1, 8, -1},
    //     {4, -1,	8, -1, -1, -1, -1, 11, -1},
    //     {-1, 8, -1, 7, -1, 4, -1, -1, 2},
    //     {-1, -1, 7, -1, 9, 14, -1, -1, -1},
    //     {-1, -1, -1, 9, -1, 10, -1, -1, -1},
    //     {-1, -1, 4, 14, 10, -1, 2, -1, -1},
    //     {-1, -1, -1, -1, -1, 2, -1, 1, 6},
    //     {8, 11, -1, -1, -1, -1, 1, -1, 7},
    //     {-1, 2, -1, -1, -1, -1, 6, 7, -1},
    // };

    for(int k = 0; k < sizeOfGraph; k++){
        int sptSet[sizeOfGraph]; // Camino mas corto
        bool SPTBool[sizeOfGraph] = {0}; // ¿Ya se encontro el camino mas corto?
        int nodoActual = k;

        
        //Inicializando array
        for(int i = 0; i < sizeOfGraph; i++){
            sptSet[i] = INT32_MAX;
        }
        SPTBool[k] = 1; //El nodo en el comenzamos, ya se conoce su distancia    
        sptSet[k] = 0; //La distanica para llegar al nodo en el que iniciamos sera "0"


        while (allPathFind(SPTBool, sizeOfGraph))
        {
            //Visitamos nodos vecinos, obtenemos su distancia
            for(int i = 0; i < sizeOfGraph; i++) {
                //Verificamos que aún no se a encontrado el camino mas corto para ese nodo
                if(!SPTBool[i]){
                    //Verificamos que el nodo actual tenga realmente una conexión
                    if(matGraph[nodoActual][i] != -1) {
                        // Obtenemos "distancia" de ruta del nodo actual
                        int newPath;
                        // Cuando se inice por primera vez el algoritmo, siempre se 
                        // obtendra la distancia que tiene al nodo destino
                        if(i != k)
                            newPath = sptSet[nodoActual] + matGraph[nodoActual][i];     
                        else newPath = matGraph[nodoActual][i]; 

                        if(newPath < sptSet[i]){
                                sptSet[i] = newPath; 
                        }
                    }
                }
            }
            
            //Verificamos que nodo tiene la menor "distancia" para agregarlo a la solución
            int nodoConMenorDistancia = INT16_MAX;
            int dist = INT16_MAX;
            for(int i = 0; i < sizeOfGraph; i++){
                //Verificamos que el nodo actual no haya sido encontrado
                if(SPTBool[i] == 0){
                    if(sptSet[i] < dist){
                        nodoConMenorDistancia = i;
                        dist = sptSet[i];
                    }
                }
            }

            //Guardamos el menor nodo de esta iteración
            SPTBool[nodoConMenorDistancia] = 1; //Ya encontramos el camino mas corto
            nodoActual = nodoConMenorDistancia; //Actualizamos nodo actual
        }
        
        for(int i = 0; i < sizeOfGraph; i++){
            if(i != k){
                cout<<"node "<<k + 1<<" to "<<"node "<<i + 1<<": "<<sptSet[i]<<endl;
            }
        }
    }
}