#include "PassarellaUsuari.h"


PassarellaUsuari::PassarellaUsuari() { //creadora
}

PassarellaUsuari::PassarellaUsuari(string nomU, string sobrenomU, string contrasenyaU, string correuElectronicU, string dataNaixementU) { //???
	_nom = nomU;
	_sobrenom = sobrenomU;
	_contrasenya = contrasenyaU;
	_correuElectronic = correuElectronicU;
	_dataNaixement = dataNaixementU;
}

PassarellaUsuari& PassarellaUsuari::operator=(const PassarellaUsuari& pu) {
	_nom = pu._nom;
	_sobrenom = pu._sobrenom;
	_contrasenya = pu._contrasenya;
	_correuElectronic = pu._correuElectronic;
	_dataNaixement = pu._dataNaixement;
	return *this;
}

//getters i setters per si de cas menys el de SOBRENOM ja q no es pot modificar? o el possem per si de cas? hauria de fer una excep qui la crida en cas q fos el mateix
string PassarellaUsuari::obteNom() {
	return _nom;
}
string PassarellaUsuari::obteSobrenom() {
	return _sobrenom;
}
string PassarellaUsuari::obteContrasenya() {
	return _contrasenya;
}
string PassarellaUsuari::obtecorreuElectronic() {
	return _correuElectronic;
}
string PassarellaUsuari::obtedataNaixement() {
	return _dataNaixement;
}

string PassarellaUsuari::obteModalitat() {
	return _modalitat;
}

void PassarellaUsuari::posaNom(string nom) {
	_nom = nom;
}

void PassarellaUsuari::posaContrasenya(string contrasenya) {
	_contrasenya = contrasenya;
}
void PassarellaUsuari::posaCorreuElectronic(string correuElectronic) {
	_correuElectronic = correuElectronic;
}
void PassarellaUsuari::posaDataNaixement(string dataNaixement) {
	_dataNaixement = dataNaixement;
}

void PassarellaUsuari::posaModalitat(string modalitat) {
	_modalitat=modalitat;
}

void PassarellaUsuari::insereix() { //exc:UsuariExisteix or CorreuExisteix
	ConnexioBD& con = ConnexioBD::getInstance();
	string query = "INSERT INTO usuari (sobrenom, nom, correu_electronic) VALUES('" +
		_sobrenom + "', '" + _nom + "', '" + _correuElectronic + "')";
	con.executa(query);
}
void PassarellaUsuari::modifica() { //exc: UsuariNoExisteix
	ConnexioBD& con = ConnexioBD::getInstance();
	std::string query = "UPDATE usuari SET nom='" + _nom + "', contrasenya='" + _contrasenya +
		"', correu_electronic='" + _correuElectronic + "', data_naixement='" + _dataNaixement +
		"' WHERE sobrenom='" + _sobrenom + "'";
	con.executa(query);
}
void PassarellaUsuari::esborra() {  //exc:UsuariNoExisteix
	ConnexioBD& con = ConnexioBD::getInstance();
	std::string query = "DELETE FROM usuari WHERE sobrenom='" + _sobrenom + "'";
	con.executa(query);
}
