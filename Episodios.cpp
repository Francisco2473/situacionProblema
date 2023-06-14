/*
Autor: Francisco Tonatihu Castro Flores    A01749518
Implementacion de la clase Episodios
*/
#include "Episodios.h"
#include<iostream>
using namespace std; 

Episodios::Episodios(const string id, const string nombre, const string genero, int calificacion, int duracion, const string fechaEstreno, const string temporada, int numeroEpisodio): Video(id, nombre, genero, calificacion,duracion, fechaEstreno), temporada(temporada), numeroEpisodio(numeroEpisodio)
{
}

void Episodios::mostrarInformacion() const
{
    cout<< "Episodio:  " << endl;
    cout <<"ID: " << id<< endl;
    cout <<"Nombre: " << nombre<< endl; 
    cout << "Genero: " << genero<< endl;
    cout << "Calificacion: " << calificacion<< endl; 
    cout << "Duracion: "<< duracion<< endl;
    cout<< "Fecha de estreno: " << fechaEstreno<< endl; 
    cout<< "Temporada: " << temporada << endl;
    cout << "Numero de episodio: "<< numeroEpisodio<< endl; 
    cout<< endl;
}
