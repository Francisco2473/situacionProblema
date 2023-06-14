/*
Autor Francisco Tonatihu Castro Flores  A01749518
Creacion de la clase Peliculas
*/

#ifndef PELICULAS_H
#define PELICULAS_H
#include "Video.h"
using namespace std;

class Peliculas: public Video
{
    public: 
    Peliculas(const string id, const string nombre, const string genero, int calificacion, int duracion, const string fechaEstreno);


    void mostrarInformacion()const;

};
#endif