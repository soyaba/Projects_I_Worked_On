#include "CercadoraVisualitzacioCapitol.hpp"
#include "ConnexioBD.h"

std::vector<std::string> CercadoraVisualitzacioCapitol::consultaVisualitzacions(const std::string& sobrenomUsuari) {
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string query = "SELECT titol_serie, num_temporada, num_capitol, data, num_visualitzacions "
        "FROM visualitzacio_capitol WHERE sobrenom_usuari = '" + sobrenomUsuari + "'";
    auto resultats = con.consulta(query);

    std::vector<std::string> visualitzacions;
    for (auto fila : resultats) {
        std::string info = "Sèrie: " + fila[0] + ", Temporada: " + fila[1] + ", Capítol: " + fila[2] + ", Data: " + fila[3] + ", Visualitzacions: " + fila[4];
        visualitzacions.push_back(info);
    }
    return visualitzacions;
}
