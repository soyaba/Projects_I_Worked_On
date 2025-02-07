#include "CapaDePresentacio.h"
using namespace std;


void CapaDePresentacio::menuPrincipal() {

	string entrada;
	wcout << "*****************\n";
	wcout << "MENÚ PRINCIPAL\n";
	wcout << "*****************\n";
	wcout << "1.Iniciar sessió\n";
	wcout << "2.Registrar usuari\n";
	wcout << "3.Consultes\n";
	wcout << "4.Sortir\n";
	wcout << "Escriu opció:\n";
	cin >> entrada;

	if (entrada == "1") return;
	else if (entrada == "2") return; //GestioContinguts();
	else if (entrada == "3") menuConsultes();
	else if (entrada == "4") return;


}

void CapaDePresentacio::menuPrincipalSessio() {

	string entrada;
	wcout << "*****************\n";
	wcout << "MENÚ PRINCIPAL\n";
	wcout << "*****************\n";
	wcout << "1.Gestió usuaris\n";
	wcout << "2.Visualitzar\n";
	wcout << "3.Consultes\n";
	wcout << "4.Tancar sessió\n";
	wcout << "5.Sortir\n";
	wcout << "Escriu opció:\n";
	cin >> entrada;

	if (entrada == "1") gestioUsuaris(); 
	else if (entrada == "2") menuVisualitza(); 
	else if (entrada == "3") menuConsultes(); 
	else if (entrada == "4") {}



}



void CapaDePresentacio::menuVisualitza() {

	string entrada;
	wcout << "-----------------\n";
	wcout << "    Visualitzar   \n";
	wcout << "-----------------\n";
	wcout << "1.Visualitzar pel·lícula\n";
	wcout << "2.Visualitzar capítol\n";
	wcout << "3.Consulta visualitzacions\n";
	wcout << "4.Tornar\n";
	wcout << "Escriu opció:\n";
	cin >> entrada;

	if (entrada == "1") return;
	else if (entrada == "2") return;
	else if (entrada == "3") return;
	else if (entrada == "4") return;

}



void CapaDePresentacio::menuConsultes() {

	string entrada;
	wcout << "-----------------\n";
	wcout << "    Consultes   \n";
	wcout << "-----------------\n";
	wcout << "1.Properes estrenes\n";
	wcout << "2.Últimes novetats\n";
	wcout << "3.Pel·lícules més vistes\n";
	wcout << "4.Tornar\n";
	wcout << "Escriu opció:\n";
	cin >> entrada;

	if (entrada == "1") return;
	else if (entrada == "2") return;
	else if (entrada == "3") return;
	else if (entrada == "4") return;


}
void CapaDePresentacio::gestioUsuaris() {
	wcout << "Gestio Usuari\n";
	wcout << "----------\n";
	wcout << "1.Consulta usuaris\n";
	wcout << "2.Modifica usuari\n";
	wcout << "3.Modifica contrasenya\n";
	wcout << "4.Esborra usuari\n";
	wcout << "5.Tornar\n";
	wcout << "Escriu opcio\n";
	string op;
	cin >> op;
	if (op == "1") registreUsuari();
	else if (op == "2") {
		//consulta_usuari();
	}
	else if (op == "3") {
		//string usuari = "12346";
		//modifica_usuari(usuari);
	}
	else if (op == "4") {
		//esborrar();
	}
	else if (op == "5") {}
}

void CapaDePresentacio::registreUsuari() {

	string sobrenomU, nomU, correuU;
	wcout << "** Registra usuari **" << std::endl;
	wcout << "Sobrenom: ";
	cin >> sobrenomU;
	wcout << "Nom: ";
	cin >> nomU;
	wcout << "Correu electrònic: ";
	cin >> correuU;

	CapaDeDomini& domini = CapaDeDomini::getInstance();
	domini.registrarUsuari(sobrenomU, nomU, correuU);
}

void CapaDePresentacio::iniciarSessio() {

	string sobrenomU, contrasenya;
	wcout << "** Inici sessio **" << endl;
	wcout << "Sobrenom: ";
	cin >> sobrenomU;
	wcout << "Contrasenya: ";
	cin >> contrasenya;

}