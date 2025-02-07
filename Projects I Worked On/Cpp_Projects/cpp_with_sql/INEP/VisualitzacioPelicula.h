#ifndef VISUALITZACIOPELICULA_HPP
#define VISUALITZACIOPELICULA_HPP

#include <string>
#include <vector>
#include "ConnexioBD.h"


// Declaración de la clase VisualitzacioPelicula
class VisualitzacioPelicula {
public:
    void visualitzar(const std::string& sobrenomUsuari, const std::string& titolPelicula);
    void consultarVisualitzacions(const std::string& sobrenomUsuari);
};

#endif // VISUALITZACIOPELICULA_HPP
