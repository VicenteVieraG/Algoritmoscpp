#include <iostream>
#include <cmath>

using namespace std;

double generalSolutioin(double y){
    //Chiharronera simplificada
    return (-1.0 + sqrt(1.0+8.0*y))/2.0;
}

int main(int argc, char** argv){
    //Read the input size
    int size;
    cin>>size;

    //Get the n value for each Y input in Y(n)=n(n+1)/2
    double Y;
    double res;
    for(int i=0;i<size;i++){
        cin>>Y;
        if(Y<0 || fmod(Y, 1.0) != 0){
            cout<<"NAI"<<endl;
        }else{
            res = generalSolutioin(Y);
            (fmod(res, 1.0) == 0.0) ? cout<<res<<endl : cout<<"NAI"<<endl;
        }
    }
    
    return 0;
}