/*
Autor: Francisco Tonatihu Castro Flores    A01749518
Implementacion de la clase Serie
*/

#include "Serie.h"
using namespace std;

Serie::Serie(const string &id, const string &nombre, int duracion, const string &genero, int calificacion, const string &fechaEstreno, const string &IDepisodio, const string &nombreEpisodio, const string &temporada, int numeroEpisodio) : Video(id, nombre, genero, calificacion, duracion, fechaEstreno),
                                                                                                                                                                                                                                              IDepisodio(IDepisodio), nombreEpisodio(nombreEpisodio), temporada(temporada), numeroEpisodio(numeroEpisodio)
{
}

string Serie::getIDepisodio() const
{
    return IDepisodio;
}

string Serie::getNombreEpisodio() const
{
    return nombreEpisodio;
}

string Serie::getTemporada() const
{
    return temporada;
}

int Serie::getNumeroEpisodio() const
{
    return numeroEpisodio;
}
