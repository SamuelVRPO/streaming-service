//
//  main.cpp
//  ServicioStreaming
//
//  Created by Samuel Vieira on 03/06/20.
//  Copyright © 2020 Samuel Vieira. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

#include "Pelicula.h"
#include "Episodio.h"
#include "Serie.h"

int main(int argc, const char * argv[]) {
    ifstream archivo;
    char tipoEntrada, genero;
    char generoDeseado;
    string titulo, director;
    int contV = 0;
    int contS = 0;
    int contP = 0;
    int contE = 0;
    int opcion;
    int calificacionDeseada;
    int duracion, numeroId, calificacion;
    int idSerie, numTemporada, numEpisodio;
    int cantTemporadas, cantEpisodios;
    int codigoDeseado;
    Video *listaVideos[10];
    Serie *listaSerie[10];
    
    Pelicula *listaPeliculas[10];
    Episodio *listaEpisodios[10];
    
    archivo.open("DocumentoVideos.txt");
    
    while (archivo >> tipoEntrada) { // Carga los archivos a los respectivos arreglos.
        if (tipoEntrada == 'p'){
            archivo >> titulo >> duracion >> genero >> numeroId >> calificacion >> director;
            listaVideos[contV] = new Pelicula(titulo, duracion, genero, numeroId, calificacion, director);
            contV++;
            listaPeliculas[contP] = new Pelicula(titulo, duracion, genero, numeroId, calificacion, director);
            contP++;
        }
        else if (tipoEntrada == 'e') {
            archivo >> titulo >> duracion >> genero >> numeroId >> calificacion >> idSerie >> numTemporada >> numEpisodio;
            listaVideos[contV] = new Episodio(titulo, duracion, genero, numeroId, calificacion, idSerie, numTemporada, numEpisodio);
            listaEpisodios[contE] = new Episodio(titulo, duracion, genero, numeroId, calificacion, idSerie, numTemporada, numEpisodio);
            contV++;
            contE++;
        }
        else if (tipoEntrada == 's') {
            archivo >> titulo >> idSerie >> cantTemporadas >> cantEpisodios;
            listaSerie[contS] = new Serie(titulo, idSerie, cantTemporadas, cantEpisodios);
            contS++;
        }
    }
    
    do {
        cout << "Escoje de las siguientes opciones: " << endl;
        cout << "1. Mostrar la lista de películas" << endl;
        cout << "2. Mostrar la lista de series" << endl;
        cout << "3. Mostrar los videos en general con una cierta calificación" << endl;
        cout << "4. Mostrar los videos en general de un cierto género" << endl;
        cout << "5. Mostrar los episodios de una determinada serie con sus calificaciones" << endl;
        cout << "6. Mostrar las películas con cierta calificación" << endl;
        cout << "0. Salir" << endl;
        
        cin >> opcion;
        switch(opcion) {
            case 1:
                for (int i = 0; i < contV; i++) {
                    if (typeid(*listaVideos[i]).name() == typeid(Pelicula).name()) {
                        listaVideos[i]->muestra();
                    }
                }
                break;
            case 2:
                for (int i = 0; i < contS; i++) {
                    listaSerie[i]->muestra();
                    }
                break;
            case 3:
                cout << "Que calificación deseas?" << endl;
                cin >> calificacionDeseada;
                for (int i = 0; i < contV; i++) {
                    if (listaVideos[i]->getCalificacion()) {
                    listaVideos[i]->muestra();
                    }
                }
                break;
            case 4:
                cout << "Que genero deseas ver?" << endl;
                cin >> generoDeseado;
                for (int i = 0; i < contV; i++) {
                    if (listaVideos[i]->getGenero() == generoDeseado) {
                        listaVideos[i]->muestra();
                    }
                }
            case 5:
                cout << "Ingresa el codigo de la serie" << endl;
                cin >> codigoDeseado;
                for (int i = 0; i < contS; i++) {
                    if (listaSerie[i]->getIdSerie() == codigoDeseado) {
                        cout << listaSerie[i]->getNombre();
                    }
                }
                for (int i = 0; i < contE; i++) {
                    if (listaEpisodios[i]->getIdSerie() == codigoDeseado) {
                        listaEpisodios[i]->muestra();
                    }
                }
                break;
            case 6:
                cout << "Que calificación deseas buscar?" << endl;
                cin >> calificacionDeseada;
                for (int i = 0; i < contV; i++) {
                    if (typeid(*listaVideos[i]).name() == typeid(Pelicula).name()) {
                        if (listaVideos[i]->getCalificacion() == calificacionDeseada) {
                            listaVideos[i]->muestra();
                        }
                    }
                }
                break;
        }
    } while (opcion != 0);
    archivo.close();
}
