#include "Plataforma.hpp"
#include "BinaryTree.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "LlibreE.hpp"
#include "Data.hpp"

using namespace std;

int main() {
    // Leer la representación del árbol de clasificación desde la entrada
   
    string arbolStr;
    getline(cin, arbolStr);
    
    BinaryTree<string> arbreClassificacio;
    arbreClassificacio.createFromInput(arbolStr);
    arbreClassificacio.print();
    Plataforma plataforma(arbreClassificacio);
    string comando;
    while (cin >> comando) {
        if (comando == "alta_llibre") {
            string titol;
            string fechaStr;
            vector<string> paraulesClau;
            
            
            // Leer el título
            cin >> titol;
            
            // Leer la fecha
            cin >> fechaStr;
            int dia, mes, any;
            sscanf(fechaStr.c_str(), "%d/%d/%d", &dia, &mes, &any);
            Data dataPub(dia, mes, any);

            // Leer las palabras clave
            string paraulesClauStr;
            getline(cin, paraulesClauStr); // Leer el resto de la línea
            istringstream iss(paraulesClauStr);
            string paraula;
            while (iss >> paraula) {
                paraulesClau.push_back(paraula);
            }

            // Crear el libro y añadirlo a la plataforma
            LlibreE llibre(titol, dataPub, paraulesClau);
            plataforma.altaLlibre(llibre);
           
        } else if (comando == "baixa_llibre") {
            string titol;
            cin >> titol;
            plataforma.baixaLlibre(titol);
           
        } else if (comando == "classifica") {
            plataforma.classifica();
            
        } else if (comando == "classifica_llibre") {
            plataforma.classificaLlibre();
        } else if (comando == "mostra_llibres") {
            plataforma.mostraLlibres();
            
        } else if (comando == "mostra_area") {
            string area;
            cin >> area;
            plataforma.mostraLlibresArea(area);
        } else if (comando == "llista_pendents") {
            plataforma.llistaPendents();
            
        } else if (comando == "fi") {
            break;
        }
    }

    return 0;
}

