#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <iostream>
#include <cppconn/prepared_statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include<string>
#include "CapaDePresentacio.h"
#include <locale>
using namespace std; 

using namespace sql;


void procesarRegistreUsuari() {
    string sobrenom, nom, correu;

    cout << "Introdueix el sobrenom: ";
    getline(cin, sobrenom);
    cout << "Introdueix el nom complet: ";
    getline(cin, nom);
    cout << "Introdueix el correu electrònic: ";
    getline(cin, correu);

    if (sobrenom.empty() || nom.empty() || correu.empty()) {
        cout << "Error al registrar usuari." << endl;
        return;
    }

    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        sql::Connection* con = driver->connect("URL_servidor:port", "usuari", "contrasenya");
        con->setSchema("nom_base_dades");

        sql::Statement* stmt = con->createStatement();
        string sql = "INSERT INTO Usuari (sobrenom, nom, correu_electronic) VALUES ('" + sobrenom + "', '" + nom + "', '" + correu + "')";
        stmt->execute(sql);

        cout << "Usuari registrat correctament." << endl;
        con->close();
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
}

void consulta_usuari() {
    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        sql::Connection* con = driver->connect("URL_servidor:port", "usuari", "contrasenya");
        con->setSchema("nom_base_dades");

        sql::Statement* stmt = con->createStatement();
        string sql = "SELECT * FROM Usuari";
        sql::ResultSet* res = stmt->executeQuery(sql);

        while (res->next()) {
            cout << "Sobrenom: " << res->getString("sobrenom") << endl;
            cout << "Nom: " << res->getString("nom") << endl;
            cout << "Correu: " << res->getString("correu_electronic") << endl;
        }
        con->close();
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
}

void procesarModificaUsuari() {
    string sobrenom, nouNom, nouCorreu;

    cout << "Introdueix el sobrenom de l'usuari a modificar: ";
    getline(cin, sobrenom);
    cout << "Introdueix el nou nom: ";
    getline(cin, nouNom);
    cout << "Introdueix el nou correu electrònic: ";
    getline(cin, nouCorreu);

    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        sql::Connection* con = driver->connect("URL_servidor:port", "usuari", "contrasenya");
        con->setSchema("nom_base_dades");

        sql::Statement* stmt = con->createStatement();
        string sql = "UPDATE Usuari SET nom='" + nouNom + "', correu_electronic='" + nouCorreu + "' WHERE sobrenom='" + sobrenom + "'";
        stmt->execute(sql);

        cout << "Usuari modificat correctament." << endl;
        con->close();
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
}

void procesarEsborraUsuari() {
    string sobrenom;
    cout << "Introdueix el sobrenom de l'usuari a esborrar: ";
    getline(cin, sobrenom);

    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        sql::Connection* con = driver->connect("URL_servidor:port", "usuari", "contrasenya");
        con->setSchema("nom_base_dades");

        sql::Statement* stmt = con->createStatement();
        string sql = "DELETE FROM Usuari WHERE sobrenom='" + sobrenom + "'";
        stmt->execute(sql);

        cout << "Usuari esborrat correctament." << endl;
        con->close();
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
}



int main() {
    std::locale::global(std::locale("es_ES.UTF-8"));

    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();

    presentacio.menuPrincipalSessio();

   
}
