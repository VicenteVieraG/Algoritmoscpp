#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <utility>

using namespace std;
typedef pair<int, int> PI;
typedef unsigned long long USLL;

//Returns a pair that contains the first and last position of the first longest common substring
//that is found in the files
//Complexity:O(nm)
//Space complexity:O(2n + 1) | n=secondText.lenght()
PI LCS(){
    //Variable declaration
    stringstream t1;
    stringstream t2;
    ifstream f1("transmission1.txt");
    ifstream f2("transmission2.txt");
    USLL max = 0;
    PI res;

    //Read files and saving them
    t1 << f1.rdbuf();
    t2 << f2.rdbuf();

    const USLL T1_LENGHT = t1.str().length();
    const USLL T2_LENGHT = t2.str().length();
 
    //Table to keep track of the LCS.
    //This table has a 2*T2_LENGHT + 1.
    //One column is added to make code easier and avoid bad comparisons
    USLL** t = new USLL*[2];

    t[0] = new USLL[T2_LENGHT + 1];
    t[1] = new USLL[T2_LENGHT + 1];

    //Fill the first column with 0s to avoid bad comparisons
    for(int i=0;i<2;i++){
        for(int j=0;j<=T2_LENGHT;j++){
            t[i][j] = 0;
        }
    }
    
    //Main algorithm
    //Each letter from each string is compared with each letter from
    //the oter string
    for(USLL i=1;i<=T1_LENGHT;i++){
        for(USLL j=1;j<=T2_LENGHT;j++){
            if(t1.str()[i-1] == t2.str()[j-1]){
                t[i%2][j] = t[(i-1)%2][j-1] + 1;
                if(t[i%2][j] > max){
                    //Set the current max subString
                    max = t[i%2][j];

                    //See in wich string it was foun first and asinging the start and end positions
                    //Appears first in the first strig
                    if(i <= j){
                        res.first = ((i - max) + 1);
                        res.second = i;
                    }else{//Appears first in the second string
                        res.first = ((j - max) + 1);
                        res.second = j;
                    }
                }
            }
        }
    }
    cout<<res.first<<" "<<res.second<<endl;
    return res;
}

int main(){
    LCS();

    return 0;
}