/*
Autor: Francisco Tonatihu Castro Flores    A01749518
Implementacion de la clase Pelicula
*/
#include "Pelicula.h"
using namespace std;

Pelicula::Pelicula(const string &id, const string &nombre, int duracion, const string &genero, int calificacion, const string &fechaEstreno) : Video(id, nombre, genero, calificacion, duracion, fechaEstreno)
{
}
