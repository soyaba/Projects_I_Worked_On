
/// -----------------------------------------
///
///  	Implementació classe Memoria
///
/// -----------------------------------------

#include "memoriaBST.hpp"

/* Cal que implementeu tots els mètodes, llevat de l'operator<< */

Memoria::Memoria() 
{};

// Constructor de còpia
Memoria::Memoria (const Memoria &m) 
{
   memoria = m.memoria;
};

Memoria::~Memoria() 
{};

// Operador d'assignació
Memoria& Memoria::operator= (const Memoria& m) 
{
if (this != &m) {

        memoria = m.memoria;
    }
    return *this;
};


// Estableix el valor per a una variable a la memòria
void Memoria::set(const string& c, int v)
{
    TUPLA buscada{c, 0};
    auto resultado = memoria.find(buscada);

    if (resultado.first) {

        TUPLA nueva_tupla{c, v};
        memoria.remove(buscada);  
        memoria.insert(nueva_tupla);  
    } else {

        TUPLA nueva_tupla{c, v};
        memoria.insert(nueva_tupla);
    }
};

// Obté el valor d'una variable de la memòria
int Memoria::get (const string& c)
{ 
    TUPLA buscada{c, 0};
    auto resultado = memoria.find(buscada);

    if (resultado.first) {

        return resultado.second.valor;
    } else {

        return 0;
    }
};

ostream& operator<<(ostream& os, const Memoria& m) 
{
	vector<Memoria::TUPLA> pre;
	
	m.memoria.preOrdre(pre);
	
	for (Memoria::TUPLA t : pre)	os << t << endl;
	
	return os;
};


