//
//  Pelicula.h
//  ServicioStreaming
//
//  Created by Samuel Vieira on 03/06/20.
//  Copyright © 2020 Samuel Vieira. All rights reserved.
//

#ifndef Pelicula_h
#define Pelicula_h

#include "Video.h"

using namespace std;

class Pelicula : public Video {
public:
    Pelicula();
    Pelicula(string titulo, int duracion, char genero, int numeroId, int calificacion, string director);
    
    void setDirector(string director) {this->director = director;};
    string getDirector() {return director;};
    
    void muestra();
private:
    string director;
};

Pelicula::Pelicula() : Video() {
    director = "";
}

Pelicula::Pelicula(string titulo, int duracion, char genero, int numeroId, int calificacion, string director) : Video(titulo, duracion, genero, numeroId, calificacion) {
    this->director = director;
}

void Pelicula::muestra() {
    cout << " - Pelicula - " << endl << "Titulo: " << titulo << endl << "Duracion: " << duracion << " minutos" << endl << "Genero: " << genero << endl << "Calificación: " << calificacion << "/5" << endl << "Director: " << director << endl;
}

#endif /* Pelicula_h */
