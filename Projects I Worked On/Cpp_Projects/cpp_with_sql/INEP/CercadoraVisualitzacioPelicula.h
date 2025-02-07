#ifndef CERCADORAVISUALITZACIOPELICULA_HPP
#define CERCADORAVISUALITZACIOPELICULA_HPP

#include <string>
#include <vector>

// Declaración de la clase CercadoraVisualitzacioPelicula
class CercadoraVisualitzacioPelicula {
public:
    std::vector<std::string> consultaVisualitzacions(const std::string& sobrenomUsuari);
};

#endif // CERCADORAVISUALITZACIOPELICULA_HPP

