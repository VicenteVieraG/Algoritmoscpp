# Vertex Colororing of a Graph
## Using a BackTracking approach
- ### Fecha de Creación: 20/10/2022
- ### Última fecha de edición: 25/10/2022
## Created by:
- Vicente Javier Viera Guízar |A01639784|
- Renet de Jesús Pérez Gómez |A01640555|

Descripción del código
=====================================================
Toma como entrada una matriz de adyacencia. Posteriormente es trasladada hacia una matriz de ints sobre la cual es aplicada la función.

La función principal toma como parametro la matriz recien creada y la cantidad de colores con los que se quiere pintar la gráfica. Esta utiliza un método recursivo de backtracking enfocado en DFS para encontrar la primera solción que logre encontrar. Cabe resaltar que no garantiza encontrar la solución óptima y solo regresa una solución.

Complejidad Cómputacional
=====================================================
- ## O(|M|^2) : M = {m | m ∈ {Set of all Colors} ^ |M| < 4}
- ## T(|V|) : V = {x | x ∈ V} <=> G(V,E) = gráfo creado por un set de vertices(V) y conecciones(E)

Casos de Prueba
=====================================================
## Caso 1
5
||||||
|---|---|---|---|---|
|0 |0 |1 |0 |1|
|0 |0 |1 |1 |1|
|1 |1 |0 |1 |0|
|0 |1 |1 |0 |1|
|1 |1 |0 |1 |0|
### Output:
>Node: 0,Assigned Color: 0
>
>Node: 1,Assigned Color: 0
>
>Node: 2,Assigned Color: 1
>
>Node: 3,Assigned Color: 2
>
>Node: 4,Assigned Color: 1
***
## Caso 2
4
|||||
|---|---|---|---|
|0 |1 |1 |1| 
|1 |0 |1 |0| 
|1 |1 |0 |1| 
|1 |0 |1 |0|
### Output:
>Node: 0,Assigned Color: 0
>
>Node: 1,Assigned Color: 1
>
>Node: 2,Assigned Color: 2
>
>Node: 3,Assigned Color: 1
***
## Caso 3
5
||||||
|---|---|---|---|---|
|0 |1 |1 |1 |1|
|1 |0 |1 |1 |1|
|1 |1 |0 |1 |1|
|1 |1 |1 |0 |1|
|1 |1 |1 |1 |0|
### Output:
>Solution does not exist
***
## Case 4
5
||||||
|---|---|---|---|---|
|0 |1 |0 |1 |1|
|1 |0 |1 |0 |0|
|0 |1 |0 |1 |0|
|1 |0 |1 |0 |1|
|1 |0 |0 |1 |0|
### Output:
>Node: 0,Assigned Color: 0
>
>Node: 1,Assigned Color: 1
>
>Node: 2,Assigned Color: 0
>
>Node: 3,Assigned Color: 1
>
>Node: 4,Assigned Color: 2