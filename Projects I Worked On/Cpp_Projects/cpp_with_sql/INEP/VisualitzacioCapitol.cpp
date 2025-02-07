#include "VisualitzacioCapitol.hpp"
#include <iostream>
#include <ctime>
#include <limits>

std::string VisualitzacioCapitol::obtenirDataActual() {
    std::time_t t = std::time(nullptr);
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", std::localtime(&t));
    return std::string(buffer);
}

void VisualitzacioCapitol::visualitzar(const std::string& sobrenomUsuari, const std::string& nomSerie, int temporada, int capitol) {
    std::string dataActual = obtenirDataActual();
    // Simulación de registro en la base de datos
    std::cout << "INSERT INTO visualitzacio_capitol (sobrenom_usuari, titol_serie, num_temporada, num_capitol, data, num_visualitzacions)\n"
        << "VALUES ('" << sobrenomUsuari << "', '" << nomSerie << "', " << temporada << ", " << capitol
        << ", '" << dataActual << "', 1) ON DUPLICATE KEY UPDATE num_visualitzacions = num_visualitzacions + 1;\n";
    std::cout << "Capítol " << capitol << " de la sèrie " << nomSerie << " visualitzat correctament." << std::endl;
}

void VisualitzacioCapitol::consultarVisualitzacions(const std::string& sobrenomUsuari) {
    // Simulación de consulta en la base de datos
    std::vector<std::string> resultats = {
        "Sèrie: Friends, Temporada: 1, Capítol: 1, Data: 2024-12-10, Visualitzacions: 5",
        "Sèrie: Friends, Temporada: 1, Capítol: 2, Data: 2024-12-15, Visualitzacions: 3"
    };

    if (resultats.empty()) {
        std::cout << "No s'han trobat visualitzacions per l'usuari '" << sobrenomUsuari << "'." << std::endl;
    }
    else {
        std::cout << "Visualitzacions de l'usuari " << sobrenomUsuari << ":" << std::endl;
        for (const auto& visualitzacio : resultats) {
            std::cout << visualitzacio << std::endl;
        }
    }
}

void menuVisualitzacioCapitol() {
    VisualitzacioCapitol visualitzacio;
    std::string sobrenomUsuari, nomSerie;
    int temporada, capitol;
    int opcio;

    while (true) {
        std::cout << "\n** Menú de Visualització de Capítols **" << std::endl;
        std::cout << "1. Visualitzar capítol" << std::endl;
        std::cout << "2. Consultar visualitzacions de capítols" << std::endl;
        std::cout << "3. Sortir" << std::endl;
        std::cout << "Selecciona una opció: ";
        std::cin >> opcio;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada no vàlida. Torna-ho a provar." << std::endl;
            continue;
        }

        if (opcio == 1) {
            std::cout << "Introdueix el sobrenom de l'usuari: ";
            std::cin >> sobrenomUsuari;
            std::cin.ignore();
            std::cout << "Introdueix el nom de la sèrie: ";
            std::getline(std::cin, nomSerie);
            std::cout << "Introdueix el número de temporada: ";
            std::cin >> temporada;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Número de temporada no vàlid. Torna-ho a provar." << std::endl;
                continue;
            }
            std::cout << "Introdueix el número de capítol: ";
            std::cin >> capitol;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Número de capítol no vàlid. Torna-ho a provar." << std::endl;
                continue;
            }
            visualitzacio.visualitzar(sobrenomUsuari, nomSerie, temporada, capitol);
        }
        else if (opcio == 2) {
            std::cout << "Introdueix el sobrenom de l'usuari: ";
            std::cin >> sobrenomUsuari;
            visualitzacio.consultarVisualitzacions(sobrenomUsuari);
        }
        else if (opcio == 3) {
            std::cout << "Sortint del menú." << std::endl;
            return;
        }
        else {
            std::cout << "Opció no vàlida. Torna-ho a provar." << std::endl;
        }
    }
}
