#ifndef PASSARELLAVISUALITZACIOCAPITOL_HPP
#define PASSARELLAVISUALITZACIOCAPITOL_HPP

#include <string>

// Declaración de la clase PassarellaVisualitzacioCapitol
class PassarellaVisualitzacioCapitol {
private:
    std::string sobrenomUsuari;
    std::string nomSerie;
    int temporada;
    int capitol;
    std::string dataVisualitzacio;

public:
    PassarellaVisualitzacioCapitol(const std::string& sobrenom, const std::string& serie, int temp, int cap, const std::string& data);
    void registraVisualitzacio();
};

#endif // PASSARELLAVISUALITZACIOCAPITOL_HPP

