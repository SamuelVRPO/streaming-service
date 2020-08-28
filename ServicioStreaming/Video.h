//
//  Video.h
//  ServicioStreaming
//
//  Created by Samuel Vieira on 03/06/20.
//  Copyright © 2020 Samuel Vieira. All rights reserved.
//
using namespace std;

#ifndef Video_h
#define Video_h

class Video {
public:
    Video();
    Video(string titulo, int duracion, char genero, int numeroId, int calificacion);
    
    void setTitulo(string titulo) {this->titulo = titulo;};
    string getTitulo() {return titulo;};
    
    void setDuracion(int duracion) {this->duracion = duracion;};
    int getDuracion() {return duracion;};
    
    void setGenero(char genero) {this->genero = genero;};
    char getGenero() {return genero;};
    
    void setNumeroId(int numeroId) {this->numeroId = numeroId;};
    int getNumeroId() {return numeroId;};
    
    void setCalificacion(int calificacion) {this->calificacion = calificacion;};
    int getCalificacion() {return calificacion;};
    
    virtual void muestra() = 0;
protected:
    string titulo;
    int duracion;
    char genero;
    int numeroId;
    int calificacion;
};

Video::Video() {
    titulo = "";
    duracion = 0;
    genero = ' ';
    numeroId = 0;
    calificacion = 0;
}

Video::Video(string titulo, int duracion, char genero, int numeroId, int calificacion) {
    this->titulo = titulo;
    this->duracion = duracion;
    this->genero = genero;
    this->numeroId = numeroId;
    this->calificacion = calificacion;
}
#endif /* Video_h */
