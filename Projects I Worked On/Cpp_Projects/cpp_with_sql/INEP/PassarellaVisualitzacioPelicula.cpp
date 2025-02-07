#include "PassarellaVisualitzacioPelicula.hpp"
#include "ConnexioBD.h"

PassarellaVisualitzacioPelicula::PassarellaVisualitzacioPelicula(const std::string& sobrenom, const std::string& titol, const std::string& data)
    : sobrenomUsuari(sobrenom), titolPelicula(titol), dataVisualitzacio(data) {}

void PassarellaVisualitzacioPelicula::registraVisualitzacio() {
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string query = "INSERT INTO visualitzacio_pelicula (sobrenom_usuari, titol_pelicula, data, num_visualitzacions) "
        "VALUES ('" + sobrenomUsuari + "', '" + titolPelicula + "', '" + dataVisualitzacio + "', 1) "
        "ON DUPLICATE KEY UPDATE num_visualitzacions = num_visualitzacions + 1";
    con.executa(query);
}

