
/// -----------------------------------------
///
///  	Implementació classe Processador
///
/// -----------------------------------------

#include "processador.hpp"
#include "programa.hpp"
Processador::Processador()			// Implementat
{
	_id = -1;
	program_n = 0;
};

Processador::Processador(int i)		// Implementat
{
	_id = i;
	program_n = 0;
};

Processador::~Processador()			// Implementat
{};

int Processador::id() const {return _id;};	// Implementat

/********************************************************/
/*              Implementeu el que queda                */
/********************************************************/


/* POST: encua el programa p a la cua de prioritat del processador. */
void Processador::encuaPrograma(Programa &p)
{
        PROGRAMES.push(p);
}

/* POST: executa t unitats de temps (instruccions)
         del programa amb més prioritat */
         
void Processador::executa(int t) {
    int totalpassos = 0;

    while (!PROGRAMES.empty() and totalpassos < t) {
    
        // Obtener el programa 
        Programa actualProgram = PROGRAMES.front();
        PROGRAMES.pop();

        cout << "PROC: " << _id << " CARREGA " << actualProgram.id()
             << " PRIORITAT " << actualProgram.prioritat() << endl;

        int passosrestants = t - totalpassos;
        int executedpassos = 0;
        int status = 0;

       
        
    while (executedpassos < passosrestants && status >= 0 ) {
    status = actualProgram.executa();

    // Incrementar el número total de pasos ejecutados en cada ejecución
    totalpassos++;
    executedpassos++;
}


        cout << "PROC: " << _id << " EXECUTAT " << executedpassos
             << " PASSOS: " << totalpassos << " de " << t
             << " STATUS " << status << endl;

        if (status == -10) {
            // El programa ha terminado con éxito, imprimir información del dispositivo

            actualProgram.escriuDispositiu(cout); 
            
        }

        if (status >= 0) {
            // Verificar si el programa ha terminado
            if (!actualProgram.status().empty()) {
            
            // Programa no ha terminado, actualizar prioridad y reencolar
            int originalPriority = actualProgram.prioritat();
            
                int newPriority = actualProgram.prioritat() - 10;
                actualProgram.prioritat(max(newPriority, 0));

                cout << "PROGRAMA " << actualProgram.id() <<
                        " PRIORITAT " << originalPriority <<
                        " a " << newPriority << endl;

                // Volver a encolar el programa actualizado
                PROGRAMES.push(actualProgram);
            }
        }
    }
}





/*************************************************************/
/*           l'operador >> ja està implementat               */
/*************************************************************/

ostream& operator<<(ostream& os, const Processador& p) 
{
	os << "PROCESSADOR: " << p._id << " #PROG: " << p.PROGRAMES.size() << endl;

	Queue<Programa> 	copia = p.PROGRAMES;

	while (not copia.empty())
	{
		Programa prog = copia.front();	
		copia.pop();
		os << prog.status() << endl;
	}

	return os;
};

