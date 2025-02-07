#include "ConnexioBD.h"

// Constructor privat per implementar el patró Singleton
ConnexioBD::ConnexioBD(const string& url, const string& user, const string& password, const string& schema) {
    driver = sql::mysql::get_mysql_driver_instance();
    conn = driver->connect(url, user, password);
    conn->setSchema(schema);  // Estableix l'esquema de la base de dades
}

// Destructor per tancar la connexió
ConnexioBD::~ConnexioBD() {
    if (conn != nullptr) {
        conn->close();
        delete conn;
    }
}

// Retorna la instància única de ConnexioBD (Singleton)
ConnexioBD& ConnexioBD::getInstance() {
    static ConnexioBD instance("URL_servidor:port", "usuari", "contrasenya", "nom_base_dades");
    return instance;
}

// Executa una comanda SQL (INSERT, UPDATE, DELETE) que no retorna resultats
void ConnexioBD::executa(const string& query) {
    sql::Statement* stmt = conn->createStatement();
    stmt->execute(query);
    delete stmt;  // Alliberem els recursos del Statement
}

// Executa una consulta SELECT que retorna resultats
sql::ResultSet* ConnexioBD::consulta(const string& query) {
    sql::Statement* stmt = conn->createStatement();
    return stmt->executeQuery(query); // Retorna el resultat de la consulta
}
