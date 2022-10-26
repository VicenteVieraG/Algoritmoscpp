#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool trySteps(int n, int d, int pos, int pathL, int* solutions, int* path, int sol, int* solutionIndex){
    //BASS case
    if(pos == n-1){
        //Add the solution
        solutions[*solutionIndex] = sol+1;
        ++*solutionIndex;
        return true;
    }

    //A lock for only add a step in sol only the first time it enters trySteps()
    bool hasAllreadyEntered = false;
    
    //Try for d steps
    for(int i=d;i>0;i--){
        //More BASS cases
        //Check if my position is valid or if we are out of range
        if(!path[pos] || pos>=pathL)return false;
        //If passes all the BASS cases try the step in the current position + d
        if(!hasAllreadyEntered){sol+=1;hasAllreadyEntered=true;}
        trySteps(n, d, pos+i, pathL, solutions, path, sol, solutionIndex);
    }

    //if There is a solution index, means that at least a solution was found
    if(*solutionIndex>0)return true;
    return false;
}

int steps(int n, int d, int* solutions, int* path, int sol, int pathL){
    //Setting values
    int InitialPosition = 0;
    int* solutionIndex = new int;
    *solutionIndex = 0;

    if(trySteps(n, d, InitialPosition, pathL, solutions, path, sol, solutionIndex)){
        cout<<"--------------------------------------------------"<<endl;
        cout<<"Possible Solutions: "<<*solutionIndex<<endl;
        cout<<"Best Solution: "<<*min_element(solutions, solutions + *solutionIndex)<<endl;
        cout<<"--------------------------------------------------"<<endl;

        return *min_element(solutions,solutions + *solutionIndex);
    }else{
        cout<<"-1"<<endl;
        return -1;
    }
}

int main(int argc, char** argv){
    int n;
    int d;
    int onesCoutn = 0;
    int sol = -1;
    string inputArr;

    //Read the input
    cin>>n;
    cin>>d;
    cin>>inputArr;
    
    int pathLenght = inputArr.length();

    //Positions array
    int* path = new int[pathLenght];

    //Make inputArr an int array
    for(int i=0;i<pathLenght;i++){
        path[i] = inputArr[i]-'0';
        if(path[i] == 1)onesCoutn++;
    }

    //Solution array
    int* solutions = new int[onesCoutn-1];

    //Call to the main function
    steps(n, d, solutions, path, sol, pathLenght);

    return 0;
}