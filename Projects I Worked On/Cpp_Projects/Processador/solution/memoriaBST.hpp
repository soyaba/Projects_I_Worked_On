#ifndef MEMORIA_HPP
#define MEMORIA_HPP

#include <cassert>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

#include "BST.hpp"

/// ------------------------------------------------------
///  Declaració operacions tipus Memoria
/// ------------------------------------------------------

class Memoria
{
	public:

		Memoria						();								/**/
		Memoria						(const Memoria &);				/**/
		~Memoria					();								/**/

		void 						set(const string&, int);		/**/
		int 						get (const string&);			/**/
		
		Memoria& operator=			(const Memoria&);				/**/
		
		friend ostream& operator<<	(ostream&, const Memoria&);		/*!!*/

	private:
	
		struct TUPLA
		{
			string clau;
			int valor;

			// Cal que acabeu de definir el tipus TUPLA
			// amb els operadors de comparació i també 
			// l'operador operator<<
			
		       bool operator<(const TUPLA& rhs) const {
                       return clau < rhs.clau; }
    

                       bool operator>(const TUPLA& rhs) const {
                       return clau > rhs.clau; }
    

                       bool operator==(const TUPLA& rhs) const {
                       return clau == rhs.clau; }
    

                       friend ostream& operator<<(ostream& os, const TUPLA& tupla) {
                       os << tupla.clau << ": " << tupla.valor ;
                       return os; }

		};

		BST<Memoria::TUPLA> 						memoria;
		
};

#endif
