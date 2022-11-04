#ifndef POINT_H
#define POINT_H

#include <math.h>

typedef long double LD;

class point{
    public:
        LD x = 0.0;
        LD y = 0.0;
        //Default contructor
        point() = default;
        //Overloaded Constructor
        point(LD x, LD y) : x(x), y(y){}
        //Overloaded operators
        bool operator>=(point& B){return abs(y) >= abs(B.y);}
        point operator=(point& B){this->x = B.x;this->y = B.y;}
};

#endif