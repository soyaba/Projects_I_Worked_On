#pragma once
#include <iostream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include "ConnexioBD.h"
using namespace std;

class PassarellaUsuari
{
public:

	PassarellaUsuari(); //creadora
	PassarellaUsuari(string nomU, string sobrenomU, string contrasenyaU, string correuElectronicU, string dataNaixementU);
	PassarellaUsuari& operator=(const PassarellaUsuari& pu);

	//getters i setters 
	string obteNom();
	string obteSobrenom();
	string obteContrasenya();
	string obtecorreuElectronic();
	string obtedataNaixement();
	string obteModalitat();

	void posaNom(string nom);
	void posaContrasenya(string contrasenya);
	void posaCorreuElectronic(string correuElectronic);
	void posaDataNaixement(string dataNaixement);
	void posaModalitat(string modalitat);


	void insereix(); 
	void modifica(); 
	void esborra();  


private:
	string _nom;
	string _sobrenom;
	string _contrasenya;
	string _correuElectronic;
	string _dataNaixement;
	string _modalitat;

};