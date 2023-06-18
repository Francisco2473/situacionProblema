/*
Autor: Francisco Tonatihu Castro Flores A01749518
Programa de prueba
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
using namespace std;

vector<std::string> split(const string &linea, char delimiter)
{
    vector<std::string> tokens;
    stringstream ss(linea);
    string token;

    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}
// Se carga el archivo con los datos a analizar
vector<Video *> cargarVideosDesdeArchivo(const string &nombreArchivo)
{
    vector<Video *> videos;
    ifstream archivo(nombreArchivo);

    if (!archivo)
    {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return videos;
    }

    string linea;
    int numeroLinea = 0;

    while (getline(archivo, linea))
    {
        numeroLinea++;

        if (numeroLinea == 1)
        {
            continue; // Saltar la primera línea, ya que no contiene datos
        }

        vector<std::string> datos = split(linea, ',');
        // Metodo para identificar las pelicula
        if (datos.size() == 6)
        {
            string id = datos[0];
            string nombre = datos[1];
            int duracion = stoi(datos[2]);
            string genero = datos[3];
            int calificacion = stoi(datos[4]);
            string fechaEstreno = datos[5];

            Pelicula *pelicula = new Pelicula(id, nombre, duracion, genero, calificacion, fechaEstreno);
            videos.push_back(pelicula);
        }
        else if (datos.size() == 10) // Metodo para identificar las series
        {
            string id = datos[0];
            string nombre = datos[1];
            int duracion = stoi(datos[2]);
            string genero = datos[3];
            int calificacion = stoi(datos[4]);
            string fechaEstreno = datos[5];
            string IDepisodio = datos[6];
            string nombreEpisodio = datos[7];
            string temporada = datos[8];
            int numeroEpisodio = stoi(datos[9]);

            Serie *serie = new Serie(id, nombre, duracion, genero, calificacion, fechaEstreno, IDepisodio, nombreEpisodio,
                                     temporada, numeroEpisodio);
            videos.push_back(serie);
        }
        else
        {
            cout << "Error en el formato de la línea " << numeroLinea << endl;
        }
    }

    archivo.close();
    return videos;
}
// A partir de aqui comienzan las operaciones a realizar
void mostrarVideosConCalificacion(const vector<Video *> &videos, int calificacionMinima)
{
    cout << "Videos con calificación mayor o igual a " << calificacionMinima << ":" << endl;

    for (const auto &video : videos)
    {
        if (video->getCalificacion() >= calificacionMinima)
        {
            cout << "ID: " << video->getId() << endl;
            cout << "Nombre: " << video->getNombre() << endl;
            cout << "Duración: " << video->getDuracion() << " minutos" << endl;
            cout << "Género: " << video->getGenero() << endl;
            cout << "Calificación: " << video->getCalificacion() << endl;
            cout << "Fecha de estreno: " << video->getFechaEstreno() << endl;
            cout << "-------------------------------------" << endl;
        }
    }

    cout << endl;
}

void mostrarVideosPorGenero(const vector<Video *> &videos, const string &genero)
{
    cout << "Videos del género \"" << genero << "\":" << endl;

    for (const auto &video : videos)
    {
        string generoVideo = video->getGenero();
        size_t posicion = generoVideo.find(genero);

        if (posicion != string::npos)
        {
            cout << "ID: " << video->getId() << endl;
            cout << "Nombre: " << video->getNombre() << endl;
            cout << "Duración: " << video->getDuracion() << " minutos" << endl;
            cout << "Género: " << video->getGenero() << endl;
            cout << "Calificación: " << video->getCalificacion() << endl;
            cout << "Fecha de estreno: " << video->getFechaEstreno() << endl;
            cout << "-------------------------------------" << endl;
        }
    }

    cout << endl;
}

void mostrarEpisodiosDeSerie(const vector<Video *> &videos, const string &nombreSerie)
{
    cout << "Episodios de la serie \"" << nombreSerie << "\":" << endl;

    for (const auto &video : videos)
    {
        Serie *serie = dynamic_cast<Serie *>(video);

        if (serie && serie->getNombre() == nombreSerie)
        {
            cout << "ID: " << serie->getId() << endl;
            cout << "Nombre: " << serie->getNombre() << endl;
            cout << "Duración: " << serie->getDuracion() << " minutos" << endl;
            cout << "Género: " << serie->getGenero() << endl;
            cout << "Calificación: " << serie->getCalificacion() << endl;
            cout << "Fecha de estreno: " << serie->getFechaEstreno() << endl;
            cout << "Nombre del Episodio: " << serie->getNombreEpisodio() << endl;
            cout << "Temporada: " << serie->getTemporada() << endl;
            cout << "Número de episodio: " << serie->getNumeroEpisodio() << endl;
            cout << "-------------------------------------" << endl;
        }
    }

    cout << endl;
}

void mostrarPeliculasConCalificacion(const vector<Video *> &videos, int calificacionMinima)
{
    cout << "Películas con calificación mayor a " << calificacionMinima << ":" << endl;

    for (const auto &video : videos)
    {
        Pelicula *pelicula = dynamic_cast<Pelicula *>(video);

        if (pelicula && pelicula->getCalificacion() > calificacionMinima)
        {
            cout << "ID: " << pelicula->getId() << endl;
            cout << "Nombre: " << pelicula->getNombre() << endl;
            cout << "Género: " << pelicula->getGenero() << endl;
            cout << "Calificación: " << pelicula->getCalificacion() << endl;
            cout << "Duración: " << pelicula->getDuracion() << " minutos" << endl;
            cout << "Fecha de estreno: " << pelicula->getFechaEstreno() << endl;
            cout << "-------------------------------------" << endl;
        }
    }

    cout << endl;
}

void calificarVideo(vector<Video *> &videos, const string &titulo)
{
    cout << "Ingrese la nueva calificación para el video \"" << titulo << "\": ";
    int nuevaCalificacion;
    cin >> nuevaCalificacion;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (auto &video : videos)
    {
        if (video->getNombre() == titulo)
        {
            video->setCalificacion(nuevaCalificacion);
            cout << "Se ha asignado la nueva calificación correctamente." << endl;
            return;
        }
    }

    cout << "No se encontró ningún video con el título especificado." << endl;
}

float calcularPromedioCalificacionSerie(const vector<Video *> &videos, const string &nombreSerie)
{
    int totalCalificacion = 0;
    int totalEpisodios = 0;

    for (const auto &video : videos)
    {
        Serie *serie = dynamic_cast<Serie *>(video);

        if (serie && serie->getNombre() == nombreSerie)
        {
            totalCalificacion += serie->getCalificacion();
            totalEpisodios++;
        }
    }

    if (totalEpisodios == 0)
    {
        cout << "No se encontró ninguna serie con el nombre especificado." << endl;
        return 0.0f;
    }

    return static_cast<float>(totalCalificacion) / totalEpisodios;
}
// Tablero de opciones
int main()
{
    vector<Video *> videos;
    bool salir = false;

    while (!salir)
    {
        cout << "----------- MENU -----------" << endl;
        cout << "1. Cargar archivo de datos en formato CSV" << endl;
        cout << "2. Mostrar videos con calificación mayor o igual a un valor" << endl;
        cout << "3. Mostrar todos los episodios de una serie" << endl;
        cout << "4. Mostrar películas con calificación mayor a un valor" << endl;
        cout << "5. Calificar un video" << endl;
        cout << "6. Calcular promedio de calificación de una serie" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese su opción: ";

        int opcion;
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion)
        {
        case 1:
        {
            cout << "Ingrese el nombre del archivo CSV: ";
            string nombreArchivo;
            cin >> nombreArchivo;
            videos = cargarVideosDesdeArchivo(nombreArchivo);
            break;
        }
        case 2:
        {
            cout << "Ingrese la calificación mínima: ";
            int calificacionMinima;
            cin >> calificacionMinima;
            mostrarVideosConCalificacion(videos, calificacionMinima);
            break;
        }
        case 3:
        {
            cout << "Ingrese el nombre de la serie: ";
            string nombreSerie;
            cin >> nombreSerie;
            mostrarEpisodiosDeSerie(videos, nombreSerie);
            break;
        }
        case 4:
        {
            cout << "Ingrese la calificación mínima: ";
            int calificacionMinima;
            cin >> calificacionMinima;
            mostrarPeliculasConCalificacion(videos, calificacionMinima);
            break;
        }
        case 5:
        {
            cout << "Ingrese el título de la película o nombre del episodio de la serie: ";
            string titulo;
            cin.ignore();
            getline(cin, titulo);
            calificarVideo(videos, titulo);
            break;
        }
        case 6:
        {
            cout << "Ingrese el nombre de la serie: ";
            string nombreSerie;
            cin >> nombreSerie;
            float promedio = calcularPromedioCalificacionSerie(videos, nombreSerie);

            if (promedio != 0.0f)
            {
                cout << "El promedio de calificación de la serie \"" << nombreSerie << "\" es: "
                     << promedio << endl;
            }

            break;
        }
        case 7:
        {
            salir = true;
            break;
        }
        default:
        {
            cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
            break;
        }
        }

        cout << endl;
    }

    // Liberar memoria de los videos
    for (auto &video : videos)
    {
        delete video;
    }

    return 0;
}