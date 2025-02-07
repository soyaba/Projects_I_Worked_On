#include "Plataforma.hpp"
#include "LlibreE.hpp"
#include <iostream>
#include <stdexcept>

Plataforma::Plataforma(const BinaryTree<string> &arbreClassificacio) : classificacio(arbreClassificacio) {}

Plataforma::~Plataforma() {}

void Plataforma::altaLlibre(const LlibreE &llibre) {
    Queue<LlibreE> temp = llibres;
    while (!temp.empty()) {
        if (temp.front().consultar_titol() == llibre.consultar_titol()) {
            std::cerr << "Error: el llibre ja existeix." << std::endl;
            return;
        }
        temp.pop();
    }
    llibres.push(llibre);
    pendents.push(llibre);

    // Imprimir los detalles del libro
    std::cout << "alta_llibre" << std::endl;
    std::cout << "títol: " << llibre.consultar_titol() << std::endl;
    std::cout << "data publicació: " << llibre.consultar_dataPub().getDia() << "/"
              << llibre.consultar_dataPub().getMes() << "/" << llibre.consultar_dataPub().getAny() << std::endl;
    
    std::cout << "paraules clau: ";
    const auto& paraulesClau = llibre.consultar_paraules_clau();
    for (size_t i = 0; i < paraulesClau.size(); ++i) {
        std::cout << paraulesClau[i];
        if (i < paraulesClau.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "àrea temàtica: " << llibre.consultar_area() << std::endl;
    std::cout << "--------------------" << std::endl;
}



void Plataforma::baixaLlibre(const string &titol) {
    Queue<LlibreE> temp;
    bool found = false;
    while (!llibres.empty()) {
        LlibreE llibre = llibres.front();
        llibres.pop();
        if (llibre.consultar_titol() == titol) {
            found = true;
        } else {
            temp.push(llibre);
        }
    }
    llibres = temp;

    if (!found) {
        std::cerr << "Error: el llibre no existeix." << std::endl;
    }

    // También necesitamos eliminar el libro de la cola de pendientes
    Queue<LlibreE> tempPendents;
    while (!pendents.empty()) {
        LlibreE llibre = pendents.front();
        pendents.pop();
        if (llibre.consultar_titol() != titol) {
            tempPendents.push(llibre);
        }
    }
    pendents = tempPendents;
}

void Plataforma::classificaLlibre() {
    if (pendents.empty()) {
        std::cerr << "Error: no hi ha cap llibre pendent de classificació." << std::endl;
        return;
    }
    LlibreE llibre = pendents.front();
    pendents.pop();
    string area = classificacio.classifica(llibre);

    // Actualizar el área del libro en la cola principal
    Queue<LlibreE> temp;
    while (!llibres.empty()) {
        LlibreE l = llibres.front();
        llibres.pop();
        if (l.consultar_titol() == llibre.consultar_titol()) {
            l.setArea(area);
        }
        temp.push(l);
    }
    llibres = temp;
}

void Plataforma::classifica() {
    while (!pendents.empty()) {
        classificaLlibre();
    }
}

void Plataforma::mostraLlibres() const {
    Queue<LlibreE> temp = llibres;
    while (!temp.empty()) {
        LlibreE llibre = temp.front();
        cout << "Titol: " << llibre.consultar_titol() << ", Data: " << llibre.consultar_dataPub().getDia() << "/"
             << llibre.consultar_dataPub().getMes() << "/" << llibre.consultar_dataPub().getAny() << ", Area: "
             << llibre.consultar_area() << endl;
        temp.pop();
    }
}

void Plataforma::mostraLlibresArea(const string &area) const {
    Queue<LlibreE> temp = llibres;
    while (!temp.empty()) {
        LlibreE llibre = temp.front();
        if (llibre.consultar_area() == area) {
            cout << "Titol: " << llibre.consultar_titol() << ", Data: " << llibre.consultar_dataPub().getDia() << "/"
                 << llibre.consultar_dataPub().getMes() << "/" << llibre.consultar_dataPub().getAny() << ", Area: "
                 << llibre.consultar_area() << endl;
        }
        temp.pop();
    }
}

void Plataforma::llistaPendents() const {
    Queue<LlibreE> temp = pendents;
    while (!temp.empty()) {
        LlibreE llibre = temp.front();
        
        cout << "llista_pendents" << endl;
        cout << "títol: " << llibre.consultar_titol() << endl;
        cout << "data publicació: " << llibre.consultar_dataPub().getDia() << "/"
             << llibre.consultar_dataPub().getMes() << "/" << llibre.consultar_dataPub().getAny() << endl;
        
        cout << "paraules clau: ";
        const vector<string>& paraulesClau = llibre.getParaulesClau();
        for (const string& paraula : paraulesClau) {
            cout << paraula << " ";
        }
        cout << endl;

        cout << "àrea temàtica: " << llibre.consultar_area() << endl;
        cout << " --------------------" << endl;

        temp.pop();
    }
}

