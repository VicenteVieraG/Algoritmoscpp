# Presentación
Fecha: 14-10-22
Tarea (actividad 3.2): Implementación de "Dijkstra and Floyd"
Equipo: 
 - Vicente Javier Viera Guízar | A01639784
 - Renet de Jesús Pérez Gómez | A01640555

# Formato de input
 - Tamaño de matriz
 - Matriz con datos

# Casos de prueba
1. Matriz de ejemplo de la tarea
**Input**
4
0  2 -1  3
-1 0  1  5
2  3  0 -1
3 -1  4  0

**Output**
*Algoritmo de Dijkstra* 
- node 1 to node 2: 2
- node 1 to node 3: 3
- node 1 to node 4: 3
- node 2 to node 1: 3
- node 2 to node 3: 1
- node 2 to node 4: 5
- node 3 to node 1: 2
- node 3 to node 2: 3
- node 3 to node 4: 5
- node 4 to node 1: 3
- node 4 to node 2: 5
- node 4 to node 3: 4
*Algoritmo de Floyd-Warshall*
0233
3015
2305

2. Matriz de ejemplo matriz no dirigida
9
-1  4 -1 -1 -1 -1 -1  8 -1
4  -1  8 -1 -1 -1 -1 11 -1
-1  8 -1  7 -1  4 -1 -1  2
-1 -1  7 -1  9 14 -1 -1 -1
-1 -1 -1  9 -1 10 -1 -1 -1
-1 -1  4 14 10 -1  2 -1 -1
-1 -1 -1 -1 -1  2 -1  1  6
8  11 -1 -1 -1 -1  1 -1  7
-1  2 -1 -1 -1 -1  6  7 -1

**Output**
*Algoritmo de Dijkstra* 
node 1 to node 2: 4 
node 1 to node 3: 12
node 1 to node 4: 19
node 1 to node 5: 21
node 1 to node 6: 11
node 1 to node 7: 9 
node 1 to node 8: 8 
node 1 to node 9: 14
node 2 to node 1: 4 
node 2 to node 3: 8 
node 2 to node 4: 15
node 2 to node 5: 22
node 2 to node 6: 12
node 2 to node 7: 12
node 2 to node 8: 11
node 2 to node 9: 10
node 3 to node 1: 8
node 3 to node 2: 4
node 3 to node 4: 7
node 3 to node 5: 14
node 3 to node 6: 4
node 3 to node 7: 6
node 3 to node 8: 7
node 3 to node 9: 2
node 4 to node 1: 15
node 4 to node 2: 11
node 4 to node 3: 7
node 4 to node 5: 9
node 4 to node 6: 11
node 4 to node 7: 13
node 4 to node 8: 14
node 4 to node 9: 9
node 5 to node 1: 21
node 5 to node 2: 18
node 5 to node 3: 14
node 5 to node 4: 9
node 5 to node 6: 10
node 5 to node 7: 12
node 5 to node 8: 13
node 5 to node 9: 16
node 6 to node 1: 11
node 6 to node 2: 8
node 6 to node 3: 4
node 6 to node 4: 11
node 6 to node 5: 10
node 6 to node 7: 2
node 6 to node 8: 3
node 6 to node 9: 6
node 7 to node 1: 9
node 7 to node 2: 8
node 7 to node 3: 6
node 7 to node 4: 13
node 7 to node 5: 12
node 7 to node 6: 2
node 7 to node 8: 1
node 7 to node 9: 6
node 8 to node 1: 8
node 8 to node 2: 9
node 8 to node 3: 7
node 8 to node 4: 14
node 8 to node 5: 13
node 8 to node 6: 3
node 8 to node 7: 1
node 8 to node 9: 7
node 9 to node 1: 6
node 9 to node 2: 2
node 9 to node 3: 10
node 9 to node 4: 17
node 9 to node 5: 18
node 9 to node 6: 8
node 9 to node 7: 6
node 9 to node 8: 7

*Algoritmo de Floyd-Warshall*
8 4 12 19 21 11 9 8 14
4 8 8 15 22 12 12 11 10
8 4 8 7 14 4 6 7 2
15 11 7 14 9 11 13 14 9
21 18 14 9 18 10 12 13 16
11 8 4 11 10 4 2 3 6
9 8 6 13 12 2 2 1 6
8 9 7 14 13 3 1 2 7
6 2 10 17 18 8 6 7 12

3. Matriz ejemplo 1
6
0   3 -1  4	-1 -1
-1  0 -1 -1	 3  4
-1 -1  0  1	-1 -1
-1 -1 -1  0	-1	1
3  -1  3 -1	 0 -1
-1 -1  2  2	 2  0

**Output**
*Algoritmo de Dijkstra* 
node 1 to node 2: 3
node 1 to node 3: 7
node 1 to node 4: 4
node 1 to node 5: 6
node 1 to node 6: 5
node 2 to node 1: 6
node 2 to node 3: 6
node 2 to node 4: 6
node 2 to node 5: 3
node 2 to node 6: 4
node 3 to node 1: 7
node 3 to node 2: 10
node 3 to node 4: 1
node 3 to node 5: 4
node 3 to node 6: 2
node 4 to node 1: 6
node 4 to node 2: 9
node 4 to node 3: 3
node 4 to node 5: 3
node 4 to node 6: 1
node 5 to node 1: 3
node 5 to node 2: 6
node 5 to node 3: 3
node 5 to node 4: 4
node 5 to node 6: 5
node 6 to node 1: 5
node 6 to node 2: 8
node 6 to node 3: 2
node 6 to node 4: 2
node 6 to node 5: 2

*Algoritmo de Floyd-Warshall*
0 3 7 4 6 5
6 0 6 6 3 4
7 10 0 1 4 2
6 9 3 0 3 1
3 6 3 4 0 5
5 8 2 2 2 0

4. Matriz ejemplo 2
4
0   2 -1 -1
3   0  3 -1
10 -1  0  1
-1  4 -1  0

**Output**
*Algoritmo de Dijkstra* 
node 1 to node 2: 2
node 1 to node 3: 5
node 1 to node 4: 6
node 2 to node 1: 3
node 2 to node 3: 3
node 2 to node 4: 4
node 3 to node 1: 8
node 3 to node 2: 5
node 3 to node 4: 1
node 4 to node 1: 7
node 4 to node 2: 4
node 4 to node 3: 7

*Algoritmo de Floyd-Warshall*
0 2 5 6
3 0 3 4
8 5 0 1
7 4 7 0