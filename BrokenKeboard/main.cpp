#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

int main(int argc, char** argv){
    //Create Alphabet Map and an iterator
    map<char,int> A;
    map<char,int>::iterator itr;

    A['a'] = 0;
    A['b'] = 0;
    A['c'] = 0;
    A['d'] = 0;
    A['e'] = 0;
    A['f'] = 0;
    A['g'] = 0;
    A['h'] = 0;
    A['i'] = 0;
    A['j'] = 0;
    A['k'] = 0;
    A['l'] = 0;
    A['m'] = 0;
    A['n'] = 0;
    A['o'] = 0;
    A['p'] = 0;
    A['q'] = 0;
    A['r'] = 0;
    A['s'] = 0;
    A['t'] = 0;
    A['u'] = 0;
    A['v'] = 0;
    A['w'] = 0;
    A['x'] = 0;
    A['y'] = 0;
    A['z'] = 0;

    //Declare Variables
    int T;
    int size;
    string aux;

    //Read the input
    cin>>T;

    //Iterate trhough each test
    for(int i=0;i<T;i++){
        cin>>aux;
        size = aux.length();

        //Iterate trough each char and count it
        for(int j=0;j<size;j++)A[aux[j]]++;
        
        //Output in alphabetic order
        for(itr = A.begin();itr!=A.end();++itr){
            if(itr->second % 2 != 0)cout<<itr->first;
            itr->second = 0;
        }
        cout<<endl;
    }

    return 0;
}