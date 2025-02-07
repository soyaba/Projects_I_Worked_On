#ifndef PROGRAMA_HPP
#define PROGRAMA_HPP

#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <ctype.h>

using namespace std;

#include "dispositiu.hpp"
#include "memoriaBST.hpp"

/// ------------------------------------------------------
///  Declaració operacions tipus Programa
/// ------------------------------------------------------

/* 	
	Operacions aritmètiques.

	SUMA 		op1 op2
	RESTA 		op1 op2
	MULT		op1 op2
	DIV			op1 op2
	
	op1 i op2 poden ser:
	(1) enters
	(2) noms de variables
	 
	el resultat de l'operació s'empila a la pila del programa.
	 
	errors: 
	-1 pila plena
	-2 divisió per zero

	Operacions sobre pila.
		
	EMPILA 		op
	op pot ser un enter o un nom de variable. empila op a la pila del programa.
	
	errors: 
	-1 pila plena
	
	DESEMPILA	op
	op és un nom de variable. desempila el valor de la pila del programa
	i el posa a op.
	 
	errors:
	-3 pila buida

	Operacions sobre dispositiu.

	LLEGEIX		op
	op és un nom de variable. posa el valor contingut del dispositiu a
	la variable de memòria op.
	
	errors:
	-8 dispositiu buit
	
	ESCRIU		op
	op pot ser un enter o una variable. posa el valor d'op al dispositiu.
	
	errors:
	-8 dispositiu ple
	
	MOU			op1 op2
	op1 és una variable de memòria. op2 pot ser una variable de memòria
	o un enter.
	 
	assigna a op1 el valor d'op2
	
	GOTO		op
	op és un enter múltiple de 10 que indica una línia
	del programa. fa un salt incondicional a op.
	
	errors:
	-5 op és una línia que no existeix
	
	MESGRAN		op
	MESPETIT	op
	IGUAL		op
	PILABUIDA	op
	DISPBUIT	op

	op és un enter múltiple de 10 que indica una línia
	del programa. fa un salt condicionat a op:
	si el flag de comparació és més petit, més gran, igual,
	o la pila del programa és buida, o el dispositiu és buit.
	
	errors:
	-5 op és una línia que no existeix

	CMP			op1 op2
	op1 i op2 poden ser enters o variables de memòria.
	compara els valors continguts a op1 i op2 i posa el flag
	de comparació a:
	1: op1 > op2
	2: op1 < op2
	3: op1 = op2
	
	INCREMENTA 	op
	DECREMENTA 	op
	op és una variable de memòria. incrementa o decrementa en una
	unitat el valor de la variable de memòria op.

	NOFARES
	no fa res.
 * 
 * 
 */

/* STATUS: 
 * 
 * -1 Pila plena.
 * -2 Divisió per zero.
 * -3 Desempilar pila buida.
 * 
 * -5 Adreça fora de rang
 * -8 Error lectura dispositiu.
 * -9 Error escriptura dispositiu.
 * -10 Programa acabat.
 */
 
/* COMPARACIÓ:
 * 0: neutre
 * 1: més gran
 * 2: més petit
 * 3: igual
 * 
 */ 

class Programa
{
	const int 						CAPACITAT = 100;

	private:
    
		int							_id;
		int							_proc;
		int							_prioritat;

		int							PC;
		int 						AC;
		int							STATUS;
		int							COMPARACIO;
	
		stack<int> 					pila;
		vector<vector<string>>		llistat;
		Dispositiu					dispositiu;

		Memoria						memoria;
		
	public:

		Programa					(int, int, int, Dispositiu);	
		Programa					();								
		Programa					(const Programa&);				

		~Programa();												
		
		int id						() const;
		int executa					();								
		int prioritat 				() const;
		void prioritat 				(int);
		void escriuMemoria			(ostream& os) const;

    
		void afegeixDispositiu		(int);
		void escriuDispositiu		(ostream&) const;

		string status				() const;						
			
		// Operadors:
				
		bool compare				(const Programa&) const;		
		bool operator<				(const Programa&) const;		
		Programa& operator=			(const Programa&);				
		
		// Operacions:
		
		int opAritmetica			(const vector<string>&);
		int opPila					(const vector<string>&);
		int opDispositiu			(const vector<string>&);
		int opMemoria				(const vector<string>&);
		int opSalt					(const vector<string>&);
		int opComparacio			(const vector<string>&);
		int opIncrement				(const vector<string>&);
		int opNofares				(const vector<string>&);

		friend ostream& operator<<	(ostream&, const Programa&);	
		friend istream& operator>>	(istream&, Programa&);			


	private:
	
		vector<string> parse		(const string&);
		bool totDigits				(const string&);
};

#endif
