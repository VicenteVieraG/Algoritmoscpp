/*
Developers=Vicente Javier Viera Guízar
ID=A01639784
Developers=Renet de Jesús Peréz Gómez
ID=A01640555
Date=23/08/2022
*/

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;

//O(log(n))
void merge(int left, int right, int mid, double* arr){
    int length = right - left + 1; 
    int cont = 0;
    int iterMid = mid+1;
    int iterLeft = left;
    double* sortedArr = new double[length];

    while (length > cont)
    {
        if(arr[iterLeft] < arr[iterMid] && !(iterMid > right) || iterLeft > mid){
            sortedArr[cont] = arr[iterMid];
            iterMid++;
        } else {
            sortedArr[cont] = arr[iterLeft];
            iterLeft++;
        }
        cont++;
    }

    for(int i = 0; i < cont; i++){
        arr[left + i] = sortedArr[i];
    }
    
}

//O(nlog(n))
void mergeSort(int left, int right, double *arr){
    if(left < right){
        int mid = (left + right)/2;
        mergeSort(left, mid, arr);
        mergeSort(mid + 1, right, arr);
        merge(left, right, mid, arr);
    }
}

//O(n+m+mlog(m)+m)
//n=numero de argumentos
//m=numero de datos a ordenar
int main(int argc, char** argv){
    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    clock_t begin = clock();

    for(int i = 1;i<argc;i++){
        if(argv[i] == NULL || argv[i] == "") return 0;

        string s;
        fstream* f = new fstream(argv[i]);

        if(f->is_open()){
            getline(*f, s);
            int size = std::stoi(s);
            double* arr = new double[size];
            int count = 0;

            while(!(f->eof())) {
                getline(*f,s);
                arr[count] = std::stof(s);
                count++;
            }

            mergeSort(0, size - 1, arr);

            for(int i=0; i < size; i++){
                cout<<arr[i]<<endl;
            }

            auto end = chrono::high_resolution_clock::now();

            double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

            cout<<time_taken<<endl;
            cout<<"-----------------------------------------------"<<endl;

        }else cerr << "Error de apertura del archivo." << endl;
    }
    return 0;
}