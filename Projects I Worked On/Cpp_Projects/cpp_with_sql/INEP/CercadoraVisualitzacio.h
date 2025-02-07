#ifndef CERCADORAVISUALITZACIO_HPP
#define CERCADORAVISUALITZACIO_HPP

#include <string>
#include <vector>

class CercadoraVisualitzacio {
public:
    std::vector<std::string> cercaVisualitzacionsPelicules(const std::string& sobrenomUsuari);
    std::vector<std::string> cercaVisualitzacionsCapitols(const std::string& sobrenomUsuari);
};

#endif // CERCADORAVISUALITZACIO_HPP

