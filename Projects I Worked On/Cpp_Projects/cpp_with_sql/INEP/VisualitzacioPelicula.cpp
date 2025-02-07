#include "VisualitzacioPelicula.hpp"
#include <iostream>
#include <string>

void menuVisualitzacio() {
    VisualitzacioPelicula visualitzacio;
    std::string sobrenomUsuari, titolPelicula;
    int opcio;

    do {
        std::cout << "\n** Menú de Visualització **" << std::endl;
        std::cout << "1. Visualitzar pel·lícula" << std::endl;
        std::cout << "2. Consultar visualitzacions" << std::endl;
        std::cout << "3. Sortir" << std::endl;
        std::cout << "Selecciona una opció: ";
        std::cin >> opcio;

        switch (opcio) {
        case 1:
            std::cout << "Introdueix el sobrenom de l'usuari: ";
            std::cin >> sobrenomUsuari;
            std::cin.ignore();
            std::cout << "Introdueix el títol de la pel·lícula: ";
            std::getline(std::cin, titolPelicula);
            visualitzacio.visualitzar(sobrenomUsuari, titolPelicula);
            break;

        case 2:
            std::cout << "Introdueix el sobrenom de l'usuari: ";
            std::cin >> sobrenomUsuari;
            visualitzacio.consultarVisualitzacions(sobrenomUsuari);
            break;

        case 3:
            std::cout << "Sortint del menú." << std::endl;
            break;

        default:
            std::cout << "Opció no vàlida." << std::endl;
        }
    } while (opcio != 3);
}
