#include "PassarellaVisualitzacio.hpp"
#include "ConnexioBD.h"
#include <iostream>

PassarellaVisualitzacio::PassarellaVisualitzacio(const std::string& sobrenom, const std::string& tipus, const std::string& titol, const std::string& data)
    : sobrenomUsuari(sobrenom), tipusVisualitzacio(tipus), titol(titol), data(data) {}

void PassarellaVisualitzacio::registraVisualitzacio() {
    try {
        ConnexioBD& con = ConnexioBD::getInstance();
        std::string query;

        if (tipusVisualitzacio == "pelicula") {
            query = "INSERT INTO visualitzacio_pelicula (sobrenom_usuari, titol_pelicula, data, num_visualitzacions) "
                "VALUES ('" + sobrenomUsuari + "', '" + titol + "', '" + data + "', 1) "
                "ON DUPLICATE KEY UPDATE num_visualitzacions = num_visualitzacions + 1";
        }
        else if (tipusVisualitzacio == "capitol") {
            query = "INSERT INTO visualitzacio_capitol (sobrenom_usuari, titol_serie, data, num_visualitzacions) "
                "VALUES ('" + sobrenomUsuari + "', '" + titol + "', '" + data + "', 1) "
                "ON DUPLICATE KEY UPDATE num_visualitzacions = num_visualitzacions + 1";
        }

        con.executa(query);
        std::cout << "Visualització registrada correctament." << std::endl;
    }
    catch (...) {
        std::cerr << "Error al registrar la visualització." << std::endl;
    }
}
