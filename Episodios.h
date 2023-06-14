/*
Autor Francisco Tonatihu Castro Flores  A01749518
Creacion de la clase Episodios
*/

#ifndef EPISODIOS_H
#define EPISODIOS_H
#include "Video.h"
using namespace std;

class Episodios : public Video
{
    private: 
    string temporada; 
    int numeroEpisodio; 

    public:
    Episodios(const string id, const string nombre, const string genero, int calificacion, int duracion, const string fechaEstreno, const string temporada, int numeroEpisodio);


    void mostrarInformacion()const; 


};
#endif