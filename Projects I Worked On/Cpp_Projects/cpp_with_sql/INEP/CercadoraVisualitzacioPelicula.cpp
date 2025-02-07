#include "CercadoraVisualitzacioPelicula.hpp"
#include "ConnexioBD.h"

std::vector<std::string> CercadoraVisualitzacioPelicula::consultaVisualitzacions(const std::string& sobrenomUsuari) {
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string query = "SELECT titol_pelicula, data, num_visualitzacions "
        "FROM visualitzacio_pelicula WHERE sobrenom_usuari = '" + sobrenomUsuari + "'";
    auto resultats = con.consulta(query);

    std::vector<std::string> visualitzacions;
    for (auto fila : resultats) {
        std::string info = "Pel·lícula: " + fila[0] + ", Data: " + fila[1] + ", Visualitzacions: " + fila[2];
        visualitzacions.push_back(info);
    }
    return visualitzacions;
}
