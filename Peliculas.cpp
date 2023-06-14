/*
Autor: Francisco Tonatihu Castro Flores    A01749518
Implementacion de la clase Peliculas 
*/
#include "Peliculas.h"
#include<iostream>
using namespace std; 

Peliculas::Peliculas(const string id, const string nombre, const string genero, int calificacion, int duracion, const string fechaEstreno): Video(id, nombre, genero, calificacion,duracion, fechaEstreno )
{

}

void Peliculas::mostrarInformacion() const
{
    cout<< "Peliculas: " << endl;
    cout <<"ID: " << id<< endl;
    cout <<"Nombre: " << nombre<< endl; 
    cout << "Genero: " << genero<< endl;
    cout << "Calificacion: " << calificacion<< endl; 
    cout << "Duracion: "<< duracion<< endl;
    cout<< "Fecha de estreno: " << fechaEstreno<< endl; 
    cout<< endl;

}
