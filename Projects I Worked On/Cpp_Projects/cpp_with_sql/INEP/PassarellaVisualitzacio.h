#ifndef PASSARELLAVISUALITZACIO_HPP
#define PASSARELLAVISUALITZACIO_HPP

#include <string>

class PassarellaVisualitzacio {
private:
    std::string sobrenomUsuari;
    std::string tipusVisualitzacio;
    std::string titol;
    std::string data;

public:
    PassarellaVisualitzacio(const std::string& sobrenom, const std::string& tipus, const std::string& titol, const std::string& data);
    void registraVisualitzacio();
};

#endif // PASSARELLAVISUALITZACIO_HPP

