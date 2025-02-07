#ifndef PLATAFORMA_HPP
#define PLATAFORMA_HPP

#include "LlibreE.hpp"
#include "PriorityQueue.hpp"
#include "BinaryTree.hpp"
#include "Classificacio.hpp"
#include <iostream>
class Plataforma {
private:
    Queue<LlibreE> llibres;
    Queue<LlibreE> pendents;
    Classificacio classificacio;

public:
    Plataforma(const BinaryTree<string> &arbreClassificacio);
    ~Plataforma();

    void altaLlibre(const LlibreE &llibre);
    void baixaLlibre(const string &titol);
    void classificaLlibre();
    void classifica();
    void mostraLlibres() const;
    void mostraLlibresArea(const string &area) const;
    void llistaPendents() const;
};

#endif

