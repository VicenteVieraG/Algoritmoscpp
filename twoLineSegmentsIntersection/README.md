# Two line segments intersection
## Created by:
>- Vicente Javier Viera Guízar |A01639784|  
>- Renet de Jesús Pérez Gómez |A01640555|
## File data:
### Created: __*31/10/2022*__
### Last modified date: __*04/11/2022*__
# Code description
This program recives two pairs of points with which a pair of lines are created. After this the program g¿creates the lines and gets is´s ecuation and variables, with this info the intersection between the two lines is calculated, but, before anything else the program checks wheter the lines are parallel or if they are the same line by ussing the denominator of the the two lines. If the denominator is 0 then the lines are parellel or are the same. If the denominator is different from 0 then y order the points of the lines making the second point I recive(B, D) getting always the point B and D the ones with the biggest y element. Moreovere I get the absloute value of the point´s y element and also from the intersction point. With this i only need to compare ranges. If L1.B>=intersectionPoint && L2.D>=intersectionPoint then i return true.
# Test Cases
## Input:
-4,-2,-8,-4,-7,-2,-4,-8  
4,4,0,0,3,2,5,0  
3,-4,1,-1,2.86,-1.02,2,-3  
0,0,3,3,1,0,3,2
## output:
true  
false  
true  
false
