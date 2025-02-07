#include "PassarellaVisualitzacioCapitol.hpp"
#include "ConnexioBD.h"

PassarellaVisualitzacioCapitol::PassarellaVisualitzacioCapitol(const std::string& sobrenom, const std::string& serie, int temp, int cap, const std::string& data)
    : sobrenomUsuari(sobrenom), nomSerie(serie), temporada(temp), capitol(cap), dataVisualitzacio(data) {}

void PassarellaVisualitzacioCapitol::registraVisualitzacio() {
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string query = "INSERT INTO visualitzacio_capitol (sobrenom_usuari, titol_serie, num_temporada, num_capitol, data, num_visualitzacions) "
        "VALUES ('" + sobrenomUsuari + "', '" + nomSerie + "', " + std::to_string(temporada) + ", " + std::to_string(capitol) + ", '" + dataVisualitzacio + "', 1) "
        "ON DUPLICATE KEY UPDATE num_visualitzacions = num_visualitzacions + 1";
    con.executa(query);
}
