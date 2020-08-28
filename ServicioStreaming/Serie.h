//
//  Serie.h
//  ServicioStreaming
//
//  Created by Samuel Vieira on 03/06/20.
//  Copyright © 2020 Samuel Vieira. All rights reserved.
//

#ifndef Serie_h
#define Serie_h
using namespace std;

class Serie {
public:
    Serie();
    Serie(string nombre, int idSerie, int cantTemporadas, int cantEpisodios);
    
    void setNombre(string nombre) {this->nombre = nombre;};
    string getNombre() {return nombre;};
    
    void setIdSerie(int idSerie) {this->idSerie = idSerie;};
    int getIdSerie() {return idSerie;};
    
    void setCantTemporadas(int cantTemporadas) {this->cantTemporadas = cantTemporadas;};
    int getCantTemporadas() {return cantTemporadas;};
    
    void setCantEpisodios(int cantEpisodios) {this->cantEpisodios = cantEpisodios;};
    int getCantEpisodios() {return cantEpisodios;};
    
    void muestra();
private:
    string nombre;
    int idSerie;
    int cantTemporadas;
    int cantEpisodios;
};

Serie::Serie () {
    nombre = "";
    idSerie = 0;
    cantTemporadas = 0;
    cantEpisodios = 0;
}

Serie::Serie(string nombre, int idSerie, int cantTemporadas, int cantEpisodios){
    this->nombre = nombre;
    this->idSerie = idSerie;
    this->cantTemporadas = cantTemporadas;
    this->cantEpisodios = cantEpisodios;
}

void Serie::muestra() {
    cout << " - Serie - " << endl << "Titulo: " << nombre << endl << "Cantidad de temporadas: " << cantTemporadas << endl << "Cantidad de capitulos: " << cantEpisodios << endl;
}
#endif /* Serie_h */
