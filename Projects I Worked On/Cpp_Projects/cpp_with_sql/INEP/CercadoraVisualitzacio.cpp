#include "CercadoraVisualitzacio.hpp"
#include "ConnexioBD.h"
#include <iostream>

std::vector<std::string> CercadoraVisualitzacio::cercaVisualitzacionsPelicules(const std::string& sobrenomUsuari) {
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string query = "SELECT titol_pelicula, data, num_visualitzacions "
        "FROM visualitzacio_pelicula WHERE sobrenom_usuari = '" + sobrenomUsuari + "'";
    auto resultats = con.consulta(query);

    std::vector<std::string> pelicules;
    for (const auto& fila : resultats) {
        pelicules.push_back("Pel·lícula: " + fila[0] + ", Data: " + fila[1] + ", Visualitzacions: " + fila[2]);
    }
    return pelicules;
}

std::vector<std::string> CercadoraVisualitzacio::cercaVisualitzacionsCapitols(const std::string& sobrenomUsuari) {
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string query = "SELECT titol_serie, num_temporada, num_capitol, data, num_visualitzacions "
        "FROM visualitzacio_capitol WHERE sobrenom_usuari = '" + sobrenomUsuari + "'";
    auto resultats = con.consulta(query);

    std::vector<std::string> capitols;
    for (const auto& fila : resultats) {
        capitols.push_back("Sèrie: " + fila[0] + ", Temporada: " + fila[1] + ", Capítol: " + fila[2] +
            ", Data: " + fila[3] + ", Visualitzacions: " + fila[4]);
    }
    return capitols;
}
