#ifndef VISUALITZACIOCAPITOL_HPP
#define VISUALITZACIOCAPITOL_HPP

#include <string>
#include <vector>

class VisualitzacioCapitol {
public:
    void visualitzar(const std::string& sobrenomUsuari, const std::string& nomSerie, int temporada, int capitol);
    void consultarVisualitzacions(const std::string& sobrenomUsuari);

private:
    std::string obtenirDataActual();
};

void menuVisualitzacioCapitol();

#endif // VISUALITZACIOCAPITOL_HPP
