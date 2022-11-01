#include <iostream>

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
    LD y1, y2, x1, x2, limitR, limitL, steps = 0;

    cin>>y1;
    cin>>x1;
    cin>>y2;
    cin>>x2;

    cin>>limitL;
    cin>>limitR;
    cin>>steps;

    LD m = gradient(y2, y1, x2, x1);

    auto Y = getFunction(x1, y1, m);

    for(LD x = limitL;x<=limitR;x+=steps){
        cout<<"("<<x<<","<<Y(x)<<")"<<endl;
    }

    return 0;
}