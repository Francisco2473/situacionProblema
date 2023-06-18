/*
Autor Francisco Tonatihu Castro Flores  A01749518
Declaracion de la clase Serie
*/

#ifndef SERIE_H
#define SERIE_H
#include "Video.h"
using namespace std;

class Serie : public Video
{
private: // Atributos
    string IDepisodio;
    string nombreEpisodio;
    string temporada;
    int numeroEpisodio;

public: // Metodos
    Serie(const string &id, const string &nombre, int duracion, const string &genero,
          int calificacion, const string &fechaEstreno, const string &IDepisodio, const string &nombreEpisodio,
          const string &temporada, int numeroEpisodio);

    string getIDepisodio() const;
    string getNombreEpisodio() const;
    string getTemporada() const;
    int getNumeroEpisodio() const;
};

#endif
