/*
Autor: Francisco Tonatihu Castro Flores   A01749518
Declaracion de clase padre Video
*/
#ifndef VIDEO_H
#define VIDEO_H
#include <string>
using namespace std;

class Video
{
protected: // Atributos
    string id;
    string nombre;
    string genero;
    int calificacion;
    int duracion;
    string fechaEstreno;

public: // Metodos
    Video(const string &id, const string &nombre, const string &genero,
          int calificacion, int duracion, const string &fechaEstreno);

    string getId() const;
    string getNombre() const;
    string getGenero() const;
    int getCalificacion() const;
    int getDuracion() const;
    string getFechaEstreno() const;

    void setCalificacion(int calificacion);

    virtual ~Video() = 0;
};

#endif