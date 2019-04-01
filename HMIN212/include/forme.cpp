#include "forme.h"

void cylindres(const int nbMeridiens, double rayon, double hauteur, float *TabOfApex, int *TabOfTriangle){
    Point Pi[nbMeridiens];
    Point Pi2[nbMeridiens];
    int ind = 0;
    int indTriangle = 0;

    for (int j = 0; j < nbMeridiens-1; j+=2) {
        double teta = 2 * M_PI * ((double) j/ (double) nbMeridiens);
        double teta2 = 2 * M_PI * ((double) j/ (double) nbMeridiens+1);
        Pi[j] = Point(cos(teta)*rayon,sin(teta)*rayon,-hauteur/2);
        Pi2[j] = Point(cos(teta)*rayon,sin(teta)*rayon,hauteur/2);
        //Pi
        TabOfApex[ind] = cos(teta)*rayon;
        TabOfApex[ind+1] = sin(teta)*rayon;
        TabOfApex[ind+2] = -hauteur/2;

        TabOfTriangle[indTriangle] = ind;
        TabOfTriangle[indTriangle+4] = ind;
        ind += 3;

        //Pi2
        TabOfApex[ind] = cos(teta)*rayon;
        TabOfApex[ind+1] = sin(teta)*rayon;
        TabOfApex[ind+2] = hauteur/2;

        TabOfTriangle[indTriangle+3] = ind;
        ind += 3;

        //Pi + 1
        TabOfApex[ind] = cos(teta2)*rayon;
        TabOfApex[ind+1] = sin(teta2)*rayon;
        TabOfApex[ind+2] = -hauteur/2;

        TabOfTriangle[indTriangle+1] = ind;
        ind += 3;

        //Pi2 + 1
        TabOfApex[ind] = cos(teta2)*rayon;
        TabOfApex[ind+1] = sin(teta2)*rayon;
        TabOfApex[ind+2] = hauteur/2;

        TabOfTriangle[indTriangle+2] = ind;
        TabOfTriangle[indTriangle+5] = ind;
        ind += 3;
    }

    /*glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    for (int j = 0; j < nbMeridiens; j++) {
        glVertex3f(Pi[j].getX(),Pi[j].getY(),Pi[j].getZ());
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    for (int j = nbMeridiens-1; j >= 0; j--) {
        glVertex3f(Pi2[j].getX(),Pi2[j].getY(),Pi2[j].getZ());
    }
    glEnd();

    for (int j = 0; j < nbMeridiens; j++) {
        drawPoint(Pi[j]);
        drawPoint(Pi2[j]);
    }*/
}

