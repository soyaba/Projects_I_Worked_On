
/// -----------------------------------------
///  	Implementació classe Programa
/// -----------------------------------------

#include "programa.hpp"

/*--------------------------------------------------------------------*/
/*                       Mètodes privats                              */
/*--------------------------------------------------------------------*/

// PRE: s és un string que correspon a una línia de codi.
// POST: torna un vector d'strings, un string per ítem a s.
// Exemple: si s = "GOTO 30"
// torna el vector ["GOTO", "30"]

vector<string> Programa::parse(const string& s)
{
	int N = s.size();
	int i = 0;
	int inici = 0, fi = 0;
	vector<string> r;
	
	while (i < N)
	{
		while (s[i] == ' ' and i < N)	i++;
		inici = i;
		while (s[i] != ' ' and i < N)	i++;
		fi = i - 1;
		if (inici <= fi)	r.push_back(s.substr(inici,fi - inici + 1));
	}

	return r;
}

bool Programa::totDigits(const string& s)		// Implementat
{
	if (s.size() == 0)							return false;
	
	if (s[0] != '-' and (not isdigit(s[0])))	return false;
	
	for (int i = 1 ; i < s.size() ; i++)
		if (not isdigit(s[i])) return false;
		
	return true;
}

/*--------------------------------------------------------------------*/

Programa::Programa(int id, int proc, int pri, Dispositiu d)
{
	_id 		= id;
	_proc 		= proc;
	_prioritat 	= pri;
	
	AC 			= 0;
	PC 			= 0;
	STATUS 		= 0;
	COMPARACIO	= 0;
	dispositiu	= d;
};

Programa::Programa()
{};

Programa::Programa(const Programa& P)
{
	_id 		= P._id;
	_proc 		= P._proc;
	_prioritat 	= P._prioritat;
	
	AC 			= P.AC;
	PC 			= P.PC;
	STATUS 		= P.STATUS;
	COMPARACIO	= P.COMPARACIO;
	
	dispositiu 	= P.dispositiu;
	
	pila		= P.pila;
	llistat		= P.llistat;
	memoria		= P.memoria;
};

/*********************************************************************/
/************* IMPLEMENTEU ELS MÈTODES A CONTINUACIÓ *****************/
/*********************************************************************/

Programa::~Programa() {};

int Programa::id() const {
    return _id;
}

int Programa::prioritat() const {
    return _prioritat;
}

void Programa::prioritat (int p) {
    _prioritat = p;
}


/*POST: añade i al dispositivo del programa*/
void Programa::afegeixDispositiu(int i){
    dispositiu << i;
}


// Escriu el contingut del dispositiu del programa
void Programa::escriuDispositiu(ostream& os) const {
   os << dispositiu << endl; 
 }


/* POST: torna true sii el paràmetre implícit és menor
		 que el paràmetre pro2.
		 Un programa és més gran que l'altre si la 
		 prioritat és superior. En cas de tenir la 
		 mateixa prioritat, és qui té _id menor.*/
bool Programa::compare(const Programa& prog2) const {
    if (_prioritat > prog2._prioritat) {
        return true;
    } else if (_prioritat == prog2._prioritat) {
        return (_id < prog2._id);
    } else {
        return false;
    }

}


/* interfície de compare*/
bool Programa::operator<(const Programa& prog2) const
{
	return this->compare(prog2);
}

Programa& Programa::operator=(const Programa& P)	// Implementat
{
    if (this == &P)        return *this;

	_id 		= P._id;
	_proc 		= P._proc;
	_prioritat 	= P._prioritat;
	
	AC 			= P.AC;
	PC 			= P.PC;
	STATUS 		= P.STATUS;
	COMPARACIO	= P.COMPARACIO;
 
	pila		= P.pila;
	llistat		= P.llistat;
	memoria		= P.memoria; 
 
	dispositiu	= P.dispositiu;

    return *this;
}

void Programa::escriuMemoria(ostream& os) const		// Implementat
{
	os << "Programa id: " << _id << " STATUS:" << STATUS << 
			" COMP: " << COMPARACIO << 
			" PC: " << (PC + 1) * 10 << endl;
			
	os << memoria << endl;

	return;
}

/*******************************************************
 * 				INSTRUCCIONS.
********************************************************/
/*
Totes les funcions següents implementen les operacions
que han estat especificades a l'enunciat.
*/



// Pre: Instr conté tres elements vàlids. 
// Post: Si la pila és plena STATUS = -1. Si hi ha una divisió per zero a "DIV", STATUS = -2.
int Programa::opAritmetica(const vector<string>& instr) {
     
    if (pila.size() == CAPACITAT) {
        STATUS = -1;
        return STATUS; }

    string op1_str = instr[1];
    string op2_str = instr[2];

    int op1, op2;

    //Convertir op1 a enter si és un nom de variable.
    if (!totDigits(op1_str)) {
        int op1_value = memoria.get(op1_str);
        if (op1_value != 0) {
            op1 = op1_value; } 
            else {
            STATUS = -5; // Error de acceso a memoria. 
            return STATUS; } }
        
        else {
        op1 = stoi(op1_str); }

    // Convertir op2 a enter si és un nom de variable.
    if (!totDigits(op2_str)) {
        int op2_value = memoria.get(op2_str);
        if (op2_value != 0) {
            op2 = op2_value; }
           else {
            STATUS = -5;  // Error de acceso a memoria. 
            return STATUS; }
            }
    else {
        op2 = stoi(op2_str); }

    //Realitzar l'operació arimetica.
    if (instr[0] == "SUMA") {
        pila.push(op1 + op2);
    } else if (instr[0] == "RESTA") {
        pila.push(op1 - op2);
    } else if (instr[0] == "MULT") {
        pila.push(op1 * op2);
    } else if (instr[0] == "DIV") {
        // Verificar si hi ha divisió per zero
        if (op2 == 0) {
            STATUS = -2;  
            return STATUS;
        } else {
            pila.push(op1 / op2);
        }
    }

    PC++; 

    return STATUS;
}

// Pre: Instr conté dos elements vàlids.
// Post: Si pila plena EMPILA i es queda STATUS = -1. Si pila buida DESEMPILA i es queda STATUS = -3.
int Programa::opPila(const vector<string>& instr) {
    if (instr[0] == "EMPILA") {

        if (pila.size() == CAPACITAT) {
            STATUS = -1; // Error: Pila llena
            return STATUS;
        }

        string op_str = instr[1];
        int op;


        if (!totDigits(op_str)) {
            int op_value = memoria.get(op_str);
            if (op_value != 0) {
                op = op_value;
            } else {

                STATUS = -5; 
                return STATUS;
            }
        } else {
            op = stoi(op_str);
        }

        // Empila el valor de op
        pila.push(op);
        
    } else if (instr[0] == "DESEMPILA") {

        if (pila.empty()) {
            STATUS = -3; // Pila buida
            return STATUS;
        }

        string op_str = instr[1];
        
        int op = pila.top();
        pila.pop();

        // Guarda el valor en la memoria
        memoria.set(op_str, op);
    }

    PC++;
    return STATUS;
}




// Pre: instr contiene dos elementos válidos.
// Post: Si op es "LLEGEIX" si el dispositivo no está vacío, se lee un valor y se almacena en la memoria.
//       si op es "ESCRIU", se escribe el valor de op_str en el dispositivo.
//       PC se incrementa.
int Programa::opDispositiu(const vector<string>& instr) {
   

    string op = instr[0];

    if (op == "LLEGEIX") {
       
        string op_str = instr[1];


        if (!dispositiu.buit()) {
            int value;
            if (dispositiu >> value) {

                memoria.set(op_str, value);
            } else {
                STATUS = -5; 
                return STATUS;
            }
        } else {
            STATUS = -8; 
            return STATUS;
        }
    }
    
    else if (op == "ESCRIU") {
        
        string op_str = instr[1];
        int value;


        if (!totDigits(op_str)) {
            int op_value = memoria.get(op_str);
            if (op_value != 0) {
                value = op_value;
            } else {
                STATUS = -5; 
                return STATUS;
            }
        } else {

            value = stoi(op_str);
        }


        if (!(dispositiu << value)) {
            STATUS = -9; 
            return STATUS;
        }
    }

    PC++;
    return STATUS;
}



// Pre: instr conté tres elements vàlids.
// Post: Assigna el valor op2 a l'adreça de memòria especificada per op1.
int Programa::opMemoria(const vector<string>& instr) {
    if (instr[0] == "MOU") {
        if (instr.size() == 3) {
            string op1 = instr[1];
            string op2_str = instr[2];
            int op2;

            // Verifica si op2 es una variable de memoria o un entero
            if (!totDigits(op2_str)) {
                int val_from_mem = memoria.get(op2_str);
                if (val_from_mem != 0) {
                    op2 = val_from_mem;
                } else {
                    // Error: dirección de memoria no encontrada
                    STATUS = -5;
                    return STATUS;
                }
            } else {
                op2 = stoi(op2_str);
            }

            // Asigna el valor de op2 a op1 en la memoria
            memoria.set(op1, op2);

            // Incrementa el contador de programa
            PC++;


        } else {

            STATUS = -5; // Adreça fora de rang
        }
    }

    return STATUS;
}



// Pre: instr conté almenys dos elements vàlids.
// Post: Realitza salts condicionals o incondicionals segons la instrucció proporcionada.
// Retorna STATUS s'actualitza en cas d'errors o condició no complerta.
int Programa::opSalt(const vector<string>& instr) {
    string instr_name = instr[0];
    int op = stoi(instr[1]);
     op = op/10;
     
     
     if(op >llistat.size() or op<0) STATUS = -5; 




        // Salto incondicional
        else if (instr_name == "GOTO") {
            PC = op-1;
        
        }

        // Salto condicional
        else if (instr_name == "MESGRAN" && COMPARACIO == 1) {
                        PC = op-1;
        } else if (instr_name == "MESPETITO" && COMPARACIO == 2) {
                        PC = op-1;
        } else if (instr_name == "IGUAL" && COMPARACIO == 3) {
                        PC = op-1;
        } else if (instr_name == "PILABUIDA" && pila.empty()) {
                        PC = op-1;
        } else if (instr_name == "DISPBUIT" && dispositiu.buit()) {
                       PC = op-1;
        }
     else {
       

    PC++;

   }
   
    return STATUS;
};


// Pre: instr conté almenys tres elements vàlids.
// Post: Retorna la comparació entre op1 i op2.
// COMPARACIO s'actualitza segons el resultat de la comparació (1: op1 > op2, 2: op1 < op2, 3: op1 == op2).
int Programa::opComparacio(const vector<string>& instr) {
    if (instr.size() == 3) {
        string op1_str = instr[1];
        string op2_str = instr[2];
        int op1, op2;

        // Verifica si op1 es una variable de memoria o un entero
        if (!totDigits(op1_str)) {
            int val_from_mem = memoria.get(op1_str);
            if (val_from_mem != 0) {
                op1 = val_from_mem;
            } else {
                // Error: dirección de memoria no encontrada
                STATUS = -5;
                return STATUS;
            }
        } else {
            op1 = stoi(op1_str);
        }

        // Verifica si op2 es una variable de memoria o un entero
        if (!totDigits(op2_str)) {
            int val_from_mem = memoria.get(op2_str);
            if (val_from_mem != 0) {
                op2 = val_from_mem;
            } else {
                // Error: dirección de memoria no encontrada
                STATUS = -5;
                return STATUS;
            }
        } else {
            op2 = stoi(op2_str);
        }

        // Compara los valores de op1 y op2 
        if (op1 > op2) {
            COMPARACIO = 1;
        } else if (op1 < op2) {
            COMPARACIO = 2;
        } else {
            COMPARACIO = 3;
        }


        PC++;

    } else {

        STATUS = -5; // Adreça fora de rang
    }

    return STATUS;
}

// Pre: instr conté dos elements vàlids.
// Post: Retorna l'operació d'increment o decrement a la variable de memòria especificada per op_str.
int Programa::opIncrement(const vector<string>& instr) {
    if (instr.size() == 2) {
        string op_str = instr[1];

        // Utiliza el método get para verificar si la variable de memoria existe
        int current_value = memoria.get(op_str);


        if (instr[0] == "INCREMENTA") {
            memoria.set(op_str, current_value + 1);  // Incrementa el valor de la variable de memoria
        } else if (instr[0] == "DECREMENTA") {
            memoria.set(op_str, current_value - 1);  // Decrementa el valor de la variable de memoria
        }

        PC++;  // Incrementa el contador de programa
    } else {

        STATUS = -5; // Adreça fora de rang
    }

    return STATUS;
}





int Programa::opNofares(const vector<string>& instr)	//Implementat
{
	if (instr[0] == "NOFARES")		PC++;	// per evitar error de compilació
											// "variable not used"
		
	return STATUS;
};

int Programa::executa ()		// Implementat
{
	if (STATUS < 0 )			return STATUS;
	if (PC >= llistat.size())	{STATUS = -10; return STATUS;} // programa acabat
	
	int RETORN = 0;
	
	assert (PC < llistat.size());

	string instr = llistat[PC][0];

	if (instr == "SUMA" or 
		instr == "RESTA" or 
		instr == "MULT" or 
		instr == "DIV")				RETORN = opAritmetica(llistat[PC]);
		
	if (instr == "EMPILA" or 
		instr == "DESEMPILA")		RETORN = opPila(llistat[PC]);

	if (instr == "LLEGEIX" or 
		instr == "ESCRIU")			RETORN = opDispositiu(llistat[PC]);

	if (instr == "MOU")				RETORN = opMemoria(llistat[PC]);
	
	if (instr == "GOTO" or 
		instr == "MESGRAN" or 
		instr == "MESPETIT" or 
		instr == "IGUAL" or
		instr == "PILABUIDA" or
		instr == "DISPBUIT")		RETORN = opSalt(llistat[PC]);
	
	if (instr == "CMP")				RETORN = opComparacio(llistat[PC]);
	
	if (instr == "INCREMENTA" or
		instr == "DECREMENTA")		RETORN = opIncrement(llistat[PC]);	

	if (instr == "NOFARES")			RETORN = opNofares(llistat[PC]);
			
	return RETORN;
};

string Programa::status() const		// Implementat
{
	string s;
	s = "PROGRAM ID: " 	+ to_string(_id) +
		" PRIO: " 	 	+ to_string(_prioritat) +
		" PROC#: " 	 	+ to_string(_proc) +
		" AC: " 		+ to_string(AC) +
		" PC: "			+ to_string( (PC + 1) * 10) +
		" STATUS: "		+ to_string(STATUS) +
		" STACK: " 		+ to_string(pila.size()) + "/" + to_string(CAPACITAT);

	return s;
};

/* Els operadors << i >> també us els donem implementats */

ostream& operator<<(ostream& os, const Programa& p) 
{
	os << "--------------------------------" << endl;
	os  << p.status() << endl;
	
	for (int i = 0 ; i < p.llistat.size() ; i++)
	{
		os << (i + 1) * 10 << ": ";
		
		for (int j = 0 ; j < p.llistat[i].size() ; j++)	
			os << p.llistat[i][j] << " ";
		
		if (p.PC == i)				os << " <- PC";

		os << endl;
	}
	
	os << "--------------------------------" << endl;
	
	return os;
};

istream& operator>>(istream& is, Programa& programa)
{	
	string linia;
	
	getline(is,linia);
	while (linia != "FINAL_PROGRAMA")
	{
		vector<string> llista = programa.parse(linia);		
		programa.llistat.push_back(llista);
		getline(is,linia);
	}
	
	return is;
};




