/*
Autor: 
Leer el archivo de texto en C++
*/

#include <iostream>
#include <fstream>//para  ifstream
#include <sstream> //para 
#include <vector>
using namespace std;

vector  <string > separar(string linea);

int main(int argc, char const* argv[])

{
    ifstream entrada;
    entrada.open("DatosPeliculas.csv");

    string lines;
    string linea; 
    int numeroLinea= 1;
    while (getline (entrada, linea))
    {
        //cout << (numeroLinea++) << " : " <<linea << endl; 
        vector<string> datos= separar (linea );
        if(datos.size()==6 )
        {
            cout << "pelicula: ";
            //new Peliculas(datos); 

        } else
        {
            cout << "episodio:"; 
            //new Series(datos); 
        }
        cout << endl; 
        //separar(linea );
        //numeroLinea++;
        //if (numeroLinea==5)
        //{
          //  break;
        //}
    }

    entrada.close(); 

    return 0; 
}

vector <string> separar(string linea)
{
    vector<string> tokens;  //componentes de la linea

    stringstream entrada(linea) ; //flujo de datos a partir de una 
    string dato; // token individual 

    int numeroTokens = 0 ;
    while (getline(entrada, dato, ','))
    {
        //cout << dato << endl; 
        if (dato != "" && dato != "\n" && dato != "\r")
        {
            //cout << dato << endl;
            tokens.push_back(dato); // Guarda en el vector  
            numeroTokens;
        }
        //numeroTokens ++; 
    }
    //cout << "tokens: " << numeroTokens << endl << endl; 
    return tokens; 
}