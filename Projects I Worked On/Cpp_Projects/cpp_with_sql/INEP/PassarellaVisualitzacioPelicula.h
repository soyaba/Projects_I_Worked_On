#ifndef PASSARELLAVISUALITZACIOPELICULA_HPP
#define PASSARELLAVISUALITZACIOPELICULA_HPP

#include <string>

// Declaración de la clase PassarellaVisualitzacioPelicula
class PassarellaVisualitzacioPelicula {
private:
    std::string sobrenomUsuari;
    std::string titolPelicula;
    std::string dataVisualitzacio;

public:
    PassarellaVisualitzacioPelicula(const std::string& sobrenom, const std::string& titol, const std::string& data);
    void registraVisualitzacio();
};

#endif // PASSARELLAVISUALITZACIOPELICULA_HPP

