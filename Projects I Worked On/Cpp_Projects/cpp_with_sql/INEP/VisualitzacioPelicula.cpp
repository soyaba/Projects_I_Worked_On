#include "VisualitzacioPelicula.hpp"
#include <iostream>
#include <string>

void menuVisualitzacio() {
    VisualitzacioPelicula visualitzacio;
    std::string sobrenomUsuari, titolPelicula;
    int opcio;

    do {
        std::cout << "\n** Men� de Visualitzaci� **" << std::endl;
        std::cout << "1. Visualitzar pel�l�cula" << std::endl;
        std::cout << "2. Consultar visualitzacions" << std::endl;
        std::cout << "3. Sortir" << std::endl;
        std::cout << "Selecciona una opci�: ";
        std::cin >> opcio;

        switch (opcio) {
        case 1:
            std::cout << "Introdueix el sobrenom de l'usuari: ";
            std::cin >> sobrenomUsuari;
            std::cin.ignore();
            std::cout << "Introdueix el t�tol de la pel�l�cula: ";
            std::getline(std::cin, titolPelicula);
            visualitzacio.visualitzar(sobrenomUsuari, titolPelicula);
            break;

        case 2:
            std::cout << "Introdueix el sobrenom de l'usuari: ";
            std::cin >> sobrenomUsuari;
            visualitzacio.consultarVisualitzacions(sobrenomUsuari);
            break;

        case 3:
            std::cout << "Sortint del men�." << std::endl;
            break;

        default:
            std::cout << "Opci� no v�lida." << std::endl;
        }
    } while (opcio != 3);
}
