#ifndef __FORME_H__
#define __FORME_H__

#include "Point.hpp"
#include <stdio.h>      
#include <stdlib.h>     
#include <math.h>
#include "../include/Point.hpp"
#include <iostream>

void cylindres(const int nbMeridiens, double rayon, double hauteur, float *TabOfApex, int *TabOfTriangle);
void cone(const int nbMeridiens);
void sphere(const int nbMeridiens, const int nbPara, Point pCentre, const int rayon);

Point Casteljau(Point TabControlPoint[],const long nbControlPoint, double u);

 #endif