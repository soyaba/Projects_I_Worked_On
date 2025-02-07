#ifndef CONSULTARVISUALITZACIONS_HPP
#define CONSULTARVISUALITZACIONS_HPP

#include <string>
#include <vector>

class ConsultarVisualitzacions {
public:
    void mostrarVisualitzacions(const std::string& sobrenomUsuari);
    std::vector<std::string> consultaPelicules(const std::string& sobrenomUsuari);
    std::vector<std::string> consultaCapitols(const std::string& sobrenomUsuari);

private:
    std::vector<std::string> executeQuery(const std::string& query);
};

#endif // CONSULTARVISUALITZACIONS_HPP

