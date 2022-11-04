#include "line.h"

typedef long double LD;

point line::operator|=(const line& L2){
    //Solve the ecuation by igualation method
    LD x = (L2.c-this->c)/(this->m-L2.m);
    LD y = (this->m*L2.c-L2.m*this->c)/(this->m-L2.m);
    
    point X(x,y);

    return X;
}