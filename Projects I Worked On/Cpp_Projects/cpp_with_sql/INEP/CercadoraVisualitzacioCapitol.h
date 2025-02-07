#ifndef CERCADORAVISUALITZACIOCAPITOL_HPP
#define CERCADORAVISUALITZACIOCAPITOL_HPP

#include <string>
#include <vector>

// Declaración de la clase CercadoraVisualitzacioCapitol
class CercadoraVisualitzacioCapitol {
public:
    std::vector<std::string> consultaVisualitzacions(const std::string& sobrenomUsuari);
};

#endif // CERCADORAVISUALITZACIOCAPITOL_HPP
