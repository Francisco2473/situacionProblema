/*
Autor: Francisco Tonatihu Castro Flores   A01749518
Declaracion de clase padre Video
*/

#ifndef ENVIO_H
#define ENVIO_H
#include <string>
using namespace std;

class Video
{
protected:
    string id;
    string nombre;
    string genero;
    int calificacion;
    int duracion;
    string fechaEstreno;

    public: 
    Video (const string id, const string nombre, const string genero, int calificacion, int duracion, int fechaEstreno);
    string getId()const;
    string getNombre()const;
    string getGenero()const;
    int getCalificacion()const;
    int getDuracion()const;
    string getFechaEstreno()const;


    void setCalificacion(int alificacion);

    virtual void mostrarInformacion()const=0;

public:
};

#endif