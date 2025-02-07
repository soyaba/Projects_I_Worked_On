
/// -----------------------------------------
///
///  	Implementació classe Dispositiu
///
/// -----------------------------------------

#include "dispositiu.hpp"

Dispositiu::Dispositiu()
{
};

// Pre: -
// Post: Crea una instància de Dispositiu amb l'identificador i la capacitat especificats.
Dispositiu::Dispositiu(int i, int c) : _id(i), capacitat(c)
{
};

Dispositiu::~Dispositiu()
{	
};

// Pre: -
// Post: Retorna true si el dispositiu està buit; false en cas contrari.
bool Dispositiu::buit() const
{
   return cua.empty();
};


// Pre: -
// Post: Afegeix l'enter al dispositiu si aquest no està ple. 
//Retorna true si s'afegeix correctament; false si el dispositiu és ple.
bool Dispositiu::operator << (int i)
{
      if (cua.size() < capacitat) {
        cua.push_back(i);
        return true;  
    } else {
        return false; 
    }
};

// Pre: -
// Post: Treu un element del dispositiu i el posa a la variable i si el dispositiu no està buit. 
//Retorna true si es va treure correctament; false si el dispositiu és buit.
bool Dispositiu::operator >> (int& i)
{
  if (!cua.empty()) {
        i = cua.front();
        cua.pop_front();
        return true;  
    } else {
        return false; 
    }
};

ostream& operator<<(ostream& os, const Dispositiu& d) 
{
	os << "DISPOSITIU_ID: " << d._id << " : ";
	
	deque<int>::const_iterator it = d.cua.begin();
	
	while (it != d.cua.end())
	{
		os << *it << " ";
		it++;
	}
	
	return os;
};

