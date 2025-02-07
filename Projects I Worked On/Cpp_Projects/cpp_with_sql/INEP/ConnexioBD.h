#ifndef CONNEXIOBD_H
#define CONNEXIOBD_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <cppconn/driver.h>

using namespace std;

class ConnexioBD {
private:
    sql::mysql::MySQL_Driver* driver; // Punter al driver MySQL
    sql::Connection* conn;            // Punter a la connexió

    // Constructor privat (patró Singleton)
    ConnexioBD(const std::string& url, const std::string& user, const std::string& password, const std::string& schema);

    // Destructor privat
    ~ConnexioBD();

    // Evitem la còpia i assignació
    ConnexioBD(const ConnexioBD&) = delete;
    ConnexioBD& operator=(const ConnexioBD&) = delete;

public:
    // Retorna la instància única (Singleton)
    static ConnexioBD& getInstance();

    // Executa una comanda SQL sense resultat (INSERT, UPDATE, DELETE)
    void executa(const std::string& query);

    // Executa una consulta SQL i retorna un punter a ResultSet (SELECT)
    sql::ResultSet* consulta(const std::string& query);
};

#endif 
