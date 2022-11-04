#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

typedef long double LD;

LD gradient(LD y2, LD y1, LD x2, LD x1){
    return (y2-y1)/(x2-x1);
}

auto getFunction(LD x, LD y, LD m){
    LD c = y-m*x;
    auto Y = [m,c](LD x){return m*x + c;};

    return Y;
}

int main(){
    //Declare Variables
    LD y1, y2, x1, x2, limitR, limitL, steps = 0;

    //Recive Inputs
    cin>>y1;
    cin>>x1;
    cin>>y2;
    cin>>x2;

    cin>>limitL;
    cin>>limitR;
    cin>>steps;

    //Get the function
    LD m = gradient(y2, y1, x2, x1);
    auto Y = getFunction(x1, y1, m);

    //Iterate and calculate y for each x in range
    for(LD x = limitL;x<=limitR;x+=steps){
        cout<<"("<<x<<","<<Y(x)<<")"<<endl;
        cout<<x;
    }

    //Plot the line

    //Get y's limits
    LD YtopLimit = Y(limitR);
    LD YButtonLimit = Y(limitL);

    //Create a matrix
    //LD yRange = abs(YtopLimit) + abs(YButtonLimit);
    //LD** plane = new LD[] 


    return 0;
}