TP1=./TP1/TP_OPENGL.cpp
TP2=./TP2/TP_OPENGL.cpp
TP3=./TP3/TP_OPENGL.cpp
TP4=./TP4/TP_OPENGL.cpp
TP5=./TP5/TP_OPENGL.cpp
TP6=./TP6/TP_OPENGL.cpp
TP7=./TP7/TP_OPENGL.cpp
TP8=./TP8/TP_OPENGL.cpp
TP9=./TP9/TP_OPENGL.cpp
VECTEUR=./include/Vector.cpp
POINT=./include/Point.cpp
TGA=./include/tga.cpp
CFLAGS=
CC=g++

TP1 : $(TP1)
	$(CC) -o tp1 $(TP1) $(VECTEUR) $(POINT) -lglut -lGL -lGLU

TP2 : $(TP2) $(VECTEUR)
	$(CC) -o tp2 $(TP2) $(VECTEUR) $(POINT) -lglut -lGL -lGLU

TP3 : $(TP3) $(VECTEUR)
	$(CC) -o tp3 $(TP3) $(VECTEUR) $(POINT) -lglut -lGL -lGLU

TP4 : $(TP4) $(VECTEUR)
	$(CC) -o tp4 $(TP4) $(VECTEUR) $(POINT) -lglut -lGL -lGLU

TP5 : $(TP5) $(VECTEUR)
	$(CC) -o tp5 $(TP5) $(VECTEUR) $(POINT) $(TGA) -lglut -lGL -lGLU

TP6 : $(TP6) $(VECTEUR) $(POINT)
	$(CC) -o tp6 $(TP6) $(VECTEUR) $(POINT) $(TGA) -lglut -lGL -lGLU

TP7 : $(TP7) $(VECTEUR) $(POINT)
	$(CC) -o tp7 $(TP7) $(VECTEUR) $(POINT) $(TGA) -lglut -lGL -lGLU

TP8 : $(TP8) $(VECTEUR) $(POINT)
	$(CC) -o tp8 $(TP8) $(VECTEUR) $(POINT) $(TGA) -lglut -lGL -lGLU

TP9 : $(TP9) $(VECTEUR) $(POINT)
	$(CC) -o tp9 $(TP9) $(VECTEUR) $(POINT) $(TGA) -lglut -lGL -lGLU

clean : 
	rm *.o


