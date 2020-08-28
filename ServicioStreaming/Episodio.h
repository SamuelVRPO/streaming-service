//
//  Episodio.h
//  ServicioStreaming
//
//  Created by Samuel Vieira on 03/06/20.
//  Copyright © 2020 Samuel Vieira. All rights reserved.
//

#ifndef Episodio_h
#define Episodio_h

#include "Video.h"

class Episodio : public Video {
public:
    Episodio();
    Episodio(string titulo, int duracion, char genero, int numeroId, int calificacion, int idSerie, int numTemporada, int numEpisodio);
    
    void setIdSerie(int idSerie) {this->idSerie = idSerie;};
    int getIdSerie() {return idSerie;};
    
    void setNumTemporada(int numTemporada) {this->numTemporada = numTemporada;};
    int getNumTemporada() {return numTemporada;};
    
    void setNumEpisodio(int numEpisodio) {this->numEpisodio = numEpisodio;};
    int getNumEpisodio() {return numEpisodio;};
    
    void muestra();
private:
    int idSerie;
    int numTemporada;
    int numEpisodio;
};

Episodio::Episodio() : Video() {
    idSerie = 0;
    numTemporada = 0;
    numEpisodio = 0;
}

Episodio::Episodio(string titulo, int duracion, char genero, int numeroId, int calificacion, int idSerie, int numTemporada, int numEpisodio) : Video(titulo, duracion, genero, numeroId, calificacion) {
    this->idSerie = idSerie;
    this->numTemporada = numTemporada;
    this->numEpisodio = numEpisodio;
}

void Episodio::muestra() {
    cout << " - Episodio - " << endl << "Titulo: " << titulo << endl << "Duracion: " << duracion << " minutos"<< endl << "Genero: " << genero << endl << "Calificación: " << calificacion << "/5" << endl << "Identificación de la serie: " << idSerie << endl << "T" << numTemporada << "E" << numEpisodio << endl;
}
#endif /* Episodio_h */
