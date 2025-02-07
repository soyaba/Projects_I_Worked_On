#include "ConsultarVisualitzacions.hpp"
#include "ConnexioBD.h"
#include <iostream>
#include <vector>

void ConsultarVisualitzacions::mostrarVisualitzacions(const std::string& sobrenomUsuari) {
    auto pelicules = consultaPelicules(sobrenomUsuari);
    auto capitols = consultaCapitols(sobrenomUsuari);

    if (pelicules.empty() && capitols.empty()) {
        std::cout << "No s'han trobat visualitzacions per l'usuari '" << sobrenomUsuari << "'." << std::endl;
        return;
    }

    if (!pelicules.empty()) {
        std::cout << "Visualitzacions de pel·lícules:" << std::endl;
        for (const auto& pelicula : pelicules) {
            std::cout << pelicula << std::endl;
        }
    }

    if (!capitols.empty()) {
        std::cout << "\nVisualitzacions de capítols:" << std::endl;
        for (const auto& capitol : capitols) {
            std::cout << capitol << std::endl;
        }
    }
}

std::vector<std::string> ConsultarVisualitzacions::consultaPelicules(const std::string& sobrenomUsuari) {
    std::string query = "SELECT titol_pelicula, data, num_visualitzacions "
        "FROM visualitzacio_pelicula WHERE sobrenom_usuari = '" + sobrenomUsuari + "'";
    return executeQuery(query);
}

std::vector<std::string> ConsultarVisualitzacions::consultaCapitols(const std::string& sobrenomUsuari) {
    std::string query = "SELECT titol_serie, num_temporada, num_capitol, data, num_visualitzacions "
        "FROM visualitzacio_capitol WHERE sobrenom_usuari = '" + sobrenomUsuari + "'";
    return executeQuery(query);
}

std::vector<std::string> ConsultarVisualitzacions::executeQuery(const std::string& query) {
    ConnexioBD& con = ConnexioBD::getInstance();
    std::vector<std::string> registros;

    try {
        sql::ResultSet* resultats = con.consulta(query);

        while (resultats->next()) {
            std::string resultat = "Resultat: " + resultats->getString(1) +
                ", Data: " + resultats->getString(2) +
                ", Visualitzacions: " + resultats->getString(3);
            registros.push_back(resultat);
        }
        delete resultats; // Libera el ResultSet después de usarlo
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error en executeQuery: " << e.what() << std::endl;
    }

    return registros;
}
