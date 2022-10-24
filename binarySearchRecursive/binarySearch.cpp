#include <iostream>

using namespace std;

//get the middlepoint
int getMiddlePoint(int i, int j){
    return (i+j)/2;
}

bool search(int i, int j, int m, int n, int* arr, int S){
    //BASS cases
    if(i >= j)return false;
    if(arr[m] == n)return true;

    if(n > m){
        i = m+1;
        m = getMiddlePoint(m, j);
        return search(i, j, m, n, arr, S);
    }else{
        j = m-1;
        m = getMiddlePoint(m, i);
        return search(i, j, m, n, arr, S);
    }
}

//Recursively makes a binary search
int binarySearch(int n, int* arr, int S){
    //Get the middlePoint
    int m = getMiddlePoint(0, S-1);
    return search(0, S-1, m, n, arr, S);
}

int main(int argc, char** argv){
    //Reading the array size
    int S;
    cin>>S;

    //Number Array
    int* arr = new int[S];
    for(int i=0;i<S;i++)cin>>arr[i];

    //Query number
    int Q;
    cin>>Q;

    //Current query
    int q;
    for(int i=0;i<Q;i++){
        cin>>q;
        cout<<binarySearch(q, arr, S)<<endl;
    }

    return 0;
}