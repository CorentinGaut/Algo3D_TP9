///////////////////////////////////////////////////////////////////////////////
// Imagina
// ----------------------------------------------------------------------------
// IN - Synth�se d'images - Mod�lisation g�om�trique
// Auteur : Gilles Gesqui�re
// ----------------------------------------------------------------------------
// Base du TP 1
// programme permettant de cr�er des formes de bases.
// La forme repr�sent�e ici est un polygone blanc dessin� sur un fond rouge
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/Point.hpp"
#include <iostream>
#include "../include/tga.h"
#include <iostream>
#include <string>
#include <fstream>
#include "../include/forme.h"
#include <list>

using namespace std;

/* Dans les salles de TP, vous avez g�n�ralement acc�s aux glut dans C:\Dev. Si ce n'est pas le cas, t�l�chargez les .h .lib ...
Vous pouvez ensuite y faire r�f�rence en sp�cifiant le chemin dans visual. Vous utiliserez alors #include <glut.h>.
Si vous mettez glut dans le r�pertoire courant, on aura alors #include "glut.h"
*/

#include <GL/glut.h>

using namespace std;

// D�finition de la taille de la fen�tre
#define WIDTH  480

#define HEIGHT 480

// D�finition de la couleur de la fen�tre
#define RED   1
#define GREEN 0
#define BLUE  0
#define ALPHA 1


// Touche echap (Esc) permet de sortir du programme
#define KEY_ESC 27


// Ent�tes de fonctions
void init_scene();
void render_scene();
GLvoid initGL();
GLvoid window_display();
GLvoid window_reshape(GLsizei width, GLsizei height);
GLvoid window_key(unsigned char key, int x, int y);
void decoupageTriangle4(Point p1, Point p2, Point p3);

int nbM; int nbP;
double zpos = 0.0, ypos = 0.0, xpos = 0.0;
float rAmb = 1.0, gAmb = 1.0, bAmb = 1.0;
float rDif = 1.0, gDif = 1.0, bDif = 1.0;
float rSpec = 1.0, gSpec = 1.0, bSpec = 1.0;

float _angle=0.0;
float _cameraangle=30.0;

// initialisation du fond de la fen�tre graphique : noir opaque
GLvoid initGL()

{
    glClearColor(1.0, 1.0, 1.0, ALPHA);
    glEnable(GL_DEPTH_TEST);
}

// Initialisation de la scene. Peut servir � stocker des variables de votre programme
// � initialiser
void init_scene()
{
}

// fonction de call-back pour l�affichage dans la fen�tre

GLvoid window_display()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // C'est l'endroit o� l'on peut dessiner. On peut aussi faire appel
    // � une fonction (render_scene() ici) qui contient les informations
    // que l'on veut dessiner
    render_scene();

    // trace la sc�ne grapnique qui vient juste d'�tre d�finie
    glFlush();
}

// fonction de call-back pour le redimensionnement de la fen�tre

GLvoid window_reshape(GLsizei width, GLsizei height)
{
  glViewport(0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // ici, vous verrez pendant le cours sur les projections qu'en modifiant les valeurs, il est
  // possible de changer la taille de l'objet dans la fen�tre. Augmentez ces valeurs si l'objet est
  // de trop grosse taille par rapport � la fen�tre.
  //glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
    //glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);

  // toutes les transformations suivantes s�appliquent au mod�le de vue
  glMatrixMode(GL_MODELVIEW);
}

// fonction de call-back pour la gestion des �v�nements clavier

GLvoid window_key(unsigned char key, int x, int y)
{
  switch (key) {
      case KEY_ESC:
        exit(1);
      case 43 :
          nbP++;
          nbM++;
          window_display();
          break;
      case 45 :
          if(nbP > 2)
              nbP--;
          if(nbM > 3)
              nbM--;
          window_display();
          break;
      case 122 :                   //Z
          xpos += 0.5;
          window_display();
          break;
      case 115 :                 //S
          xpos -= 0.5;
          window_display();
          break;
      case 101 :                   // Flèche vers le haut :
          zpos += 0.5;
          window_display();
          break;
      case 97 :                 //
          zpos -= 0.5;
          window_display();
          break;
      case 100 :                   //Q
          ypos += 0.5;
          window_display();
          break;

      case 113 :                 //D
          ypos -= 0.5;
          window_display();
          break;
      case 108 : // Touche L
          if(glIsEnabled(GL_LIGHTING)){
              glDisable(GL_LIGHTING);
              glDisable(GL_LIGHT0);
          } else {
              glEnable(GL_LIGHTING);
              glEnable(GL_LIGHT0);
          }
          window_display();
          break;
      case 102 : //F
          if(glIsEnabled(GL_FOG)){
              glDisable(GL_FOG);
          } else {
              glEnable(GL_FOG);
          }
          window_display();
          break;
  default:
    printf ("La touche %d n�est pas active.\n", key);
    break;
  }
}

void drawPoint(Point p){
    glPointSize(6);
    glBegin(GL_POINTS);
    glColor3f(0,1.0,0.0);
    glVertex3f(p.getX(), p.getY(), p.getZ());
    glEnd();

}

void drawLine(Point p1, Point p2){
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(p1.getX(), p1.getY(), p1.getZ());
    glVertex3f(p2.getX(), p2.getY(), p2.getZ());
    glEnd();
}

void drawTriangle(Point p1, Point p2,Point p3){
    glBegin(GL_TRIANGLES);
        //glColor3f(0.0,0.0,0.0);
        glVertex3f(p1.getX(), p1.getY(), p1.getZ());
        glVertex3f(p2.getX(), p2.getY(), p2.getZ());
        glVertex3f(p3.getX(), p3.getY(), p3.getZ());
    glEnd();
}

void drawLine(Vector v, Point p1){
    glColor3f(1.0f,0.9f,0.25f);
    glBegin(GL_LINES);
    glVertex3f(p1.getX(), p1.getY(), p1.getZ());
    glVertex3f(p1.getX() + v.getX(), p1.getY() + v.getY(), p1.getZ() + v.getZ());
    glEnd();
}

void drawCurve(Point TabPointOfCorve[],const long nbPoints){
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0,1.0,1.0);
    for (int i = 0; i < nbPoints; i++) {
        Point p = TabPointOfCorve[i];
        glVertex3f(p.getX(), p.getY(), p.getZ());
    }
    glEnd();
}

void drawCylindrique(Point **TabPointOfCorve1,const long nbPoints,const long nbV){
    for (int i = 0; i < nbV; i++) {
        drawCurve(TabPointOfCorve1[i],nbPoints);
    }
    for (int j = 0; j < nbPoints; j++) {
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < nbV; i++) {
            Point p = TabPointOfCorve1[i][j];
            glVertex3f(p.getX(), p.getY(), p.getZ());
        }
        glEnd();
    }
}

void update(int value){
    _angle+=2.0f;
    if(_angle>360.f)
    {
        _angle-=360;
    }
    glutPostRedisplay();
    glutTimerFunc(25,update,0);
}

void readFileOFF(string fileName){
    float *TabOfApex;
    int *TabOfTriangle; 
    float *TabOfNormale;
    Point *tabPoints;
    int nbSommet, nbTriangle;
    string s;

    ifstream file(fileName,ios::in);
    if(!file)
        exit(-1);
    
    file >> s; //OFF
    file >> s; //nbSommet
    nbSommet = stoi(s);
    TabOfApex = new float[stoi(s)*3];
    file >> s; //nbTriangle
    nbTriangle = stoi(s);
    TabOfTriangle = new int[stoi(s)*3];
    TabOfNormale = new float[stoi(s)*3];
    tabPoints = new Point[nbSommet];
    file >> s; //nbArrete

    int k = 0;
    for(int i = 0; i < nbSommet * 3; i+=3){
        file >> s;
        TabOfApex[i] = stof(s);
        file >> s;
        TabOfApex[i+1] = stof(s);
        file >> s;
        TabOfApex[i+2] = stof(s);

        //remplis un tableau de "point"
        tabPoints[k] = Point(TabOfApex[i],TabOfApex[i+1],TabOfApex[i+2]);
        k++;
    }

    for(int i = 0; i < nbTriangle * 3; i+=3){
        file >> s; //3 au débutddd
        file >> s;
        TabOfTriangle[i] = stoi(s);
        file >> s;
        TabOfTriangle[i+1] = stoi(s);
        file >> s;
        TabOfTriangle[i+2] = stoi(s);
    }

    float deltaX = 0.0 , deltaY = 0.0, deltaZ = 0.0;
    for(int i = 0; i < nbSommet * 3; i+=3){
        for(int j = i+3; j < nbSommet * 3; j+=3){
            deltaX = max(deltaX, TabOfApex[i] - TabOfApex[j]);
            deltaY = max(deltaY, TabOfApex[i+1] - TabOfApex[j+1]);
            deltaZ = max(deltaZ, TabOfApex[i+2] - TabOfApex[j+2]);
        }
    }

    float ortho = max(deltaX, deltaY);
    glOrtho(-ortho, ortho, -ortho, ortho, -ortho, ortho);
    gluLookAt(0 + xpos,deltaY/2 + ypos,deltaZ/2 + zpos,   0,deltaY/2,0,   0,1,0);

    glColor3f(1.0f,0.0f,0.0f);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glEnableClientState (GL_VERTEX_ARRAY);
    //glEnableClientState (GL_NORMAL_ARRAY);

    glVertexPointer (3, GL_FLOAT, 0, TabOfApex);
    //glNormalPointer (GL_FLOAT, 0, TabOfNormale);
    glDrawElements (GL_TRIANGLES, nbTriangle * 3, GL_UNSIGNED_INT, TabOfTriangle);

    //glDisableClientState (GL_NORMAL_ARRAY);
    glDisableClientState (GL_VERTEX_ARRAY);

    for(int i = 0; i < nbTriangle * 3; i+=3){
        decoupageTriangle4(tabPoints[TabOfTriangle[i]],tabPoints[TabOfTriangle[i+1]],tabPoints[TabOfTriangle[i+2]]);
    }

}

void VoisinsTriangle(){
    
}

void decoupageTriangle4(Point p1, Point p2, Point p3){
    //premiere arete
    Point m1 = Point((p1.getX() + p2.getX())/2, (p1.getY() + p2.getY())/2, (p1.getZ() + p2.getZ())/2);
    //seconde arete
    Point m2 = Point((p1.getX() + p3.getX())/2, (p1.getY() + p3.getY())/2, (p1.getZ() + p3.getZ())/2);
    //troisieme arete
    Point m3 = Point((p2.getX() + p3.getX())/2, (p2.getY() + p3.getY())/2, (p2.getZ() + p3.getZ())/2);

    drawTriangle(m1,m2,m3);
}

void ButterFly(){

}
//////////////////////////////////////////////////////////////////////////////////////////
// Fonction que vous allez modifier afin de dessiner
/////////////////////////////////////////////////////////////////////////////////////////
void render_scene() {

    const int nbMeridien = nbM;
    const int nbPara = nbP;
//dd
    //glOrtho(-30.0, 30.0, -30.0, 30.0, -30.0, 30.0);
    //gluLookAt(0 + xpos,5 + ypos,2 + zpos,   0,0,0,   0,1,0);
    readFileOFF("./TP9/triceratops.off");

    //glEnable(GL_COLOR_MATERIAL);
    //D�finition de la couleur
    //gluLookAt(xpos,ypos,zpos,   0,0,0,   0,1,0);
    //glRotatef(_cameraangle,0.0f,1.0f,0.0f);ssssss
    //glRotatef(_angle,0.0f,1.0f,0.0f);
}

int main(int argc, char **argv)
{
    nbM = 8; nbP = 8;
    // initialisation  des param�tres de GLUT en fonction
    // des arguments sur la ligne de commande
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);

    // d�finition et cr�ation de la fen�tre graphique, ainsi que son titre
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Premier exemple : carré");

    // initialisation de OpenGL et de la sc�ne
    initGL();
    init_scene();

    // choix des proc�dures de callback pour
    // le trac� graphique
    glutDisplayFunc(&window_display);
    // le redimensionnement de la fen�tre
    glutReshapeFunc(&window_reshape);
    // la gestion des �v�nements clavier
    glutKeyboardFunc(&window_key);

    //glutTimerFunc(25,update,0);

    // la boucle prinicipale de gestion des �v�nements utilisateur
    glutMainLoop();

    return 1;
}
