/*
Autor Francisco Tonatihu Castro Flores  A01749518
Declaracion de la clase Pelicula
*/

#ifndef PELICULA_H
#define PELICULA_H
#include "Video.h"
using namespace std;

class Pelicula : public Video
{
public: // Metodo
    Pelicula(const string &id, const string &nombre, int duracion, const string &genero,
             int calificacion, const string &fechaEstreno);
};

#endif
