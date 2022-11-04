#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include "point.h"
#include "line.h"

using namespace std;

bool Intersect(line& L1, line& L2){
    //Get the intersection
    point X = L1|=L2;

    //Change all points´ y to absolute value and compare if is in range
    L1.B.y = fabs(L1.B.y);
    L2.B.y = fabs(L2.B.y);
    X.y = fabs(X.y);

    //Check the range
    return (L1.B>=X && L2.B>=X);
}

//Check if the lines are equal or parallel.
//Returns true if the lines are parallel or coincident
//Else returns false and the lines hava an intersection
bool areLinesSameOrParallel(const line& L1, const line& L2){
    return !((L1.A.x-L1.B.x)*(L2.A.y-L2.B.y)-(L1.A.y-L1.B.y)*(L2.A.x-L2.B.x));
}

void swapPoints(point& A, point& B){
    point aux(A.x, A.y);
    A.x = B.x;
    A.y = B.y;
    B.x = aux.x;
    B.y = aux.y;
}

//The B and D points of the lines need to be the ones with the grater |y|
int main(int argc, char** argv){
    //Variables
    string aux;
    string num = "";
    LD positions[8];
    point points[4];
    queue<bool> results;

    while(cin>>aux){
        int j = 0;
        int k = 0;

        //Read the input
        for(int i=0;i<aux.length();i++){
            if(aux[i]!=','){
                if(i==aux.length()-1){
                    num+=aux[i];
                    positions[j] = stold(num);
                    j++;
                    num = "";
                }else{
                    num+=aux[i];
                }
            }else{
                positions[j] = stold(num);
                j++;
                num = "";
            }
        }

        //Make the points
        for(int i=0;i<j;i+=2){
            point P(positions[i], positions[i+1]);
            points[k] = P;
            k++;
        }

        //Order the points in the order B>A D>C
        if(points[0]>=points[1])swapPoints(points[0], points[1]);
        if(points[2]>=points[3])swapPoints(points[2], points[3]);

        //Make the lines
        line L1(points[0], points[1]);
        line L2(points[2], points[3]);

        //Check if the segments intersect
        if(areLinesSameOrParallel(L1, L2)){
            results.push(false);
        }else if(Intersect(L1, L2)){
            results.push(true);
        }else{
            results.push(false);
        }
    }

    //Print results
    int size = results.size();
    for(int i=0;i<size;i++){
        cout<<boolalpha<<results.front()<<endl;
        results.pop();
    }
    
    return 0;
}

/*░░░████▌█████▌█░████████▐▀██▀
░▄█████░█████▌░█░▀██████▌█▄▄▀▄
░▌███▌█░▐███▌▌░░▄▄░▌█▌███▐███░▀
▐░▐██░░▄▄▐▀█░░░▐▄█▀▌█▐███▐█
░░███░▌▄█▌░░▀░░▀██░░▀██████▌
░░░▀█▌▀██▀░▄░░░░░░░░░███▐███
░░░░██▌░░░░░░░░░░░░░▐███████▌
░░░░███░░░░░▀█▀░░░░░▐██▐███▀▌
░░░░▌█▌█▄░░░░░░░░░▄▄████▀░▀
░░░░░░█▀██▄▄▄░▄▄▀▀▒█▀█░*/