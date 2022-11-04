#ifndef LINE_H
#define LINE_H

#include "point.h"

typedef long double LD;

class line{
    public:
        point A;
        point B;
        LD m = (B.y-A.y)/(B.x-A.x);
        LD c = A.y-m*A.x;
        //Default constructor
        line() = default;
        //Overloaded Constructor
        line(point A, point B) : A(A), B(B){}
        //Functions

        //Return the intersection point of two lines
        point operator|=(const line& L2);
};

#endif