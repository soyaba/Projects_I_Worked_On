#include<iostream>
#include<string>
using namespace std;


void procesarRegistreUsuari() {
    string sobrenom, nom_complet;

    cout << "Introdueix el sobrenom: ";
    getline(cin, sobrenom);

    cout << "Introdueix el nom complet: ";
    getline(cin, nom_complet);

    if (sobrenom.empty() || nom_complet.empty()) {
        cout << "Error al registrar usuari." << endl;
    }
    else {
        cout << "El registre de l'usuari " << nom_complet << " (" << sobrenom << ") s'ha processat correctament." << endl;
    }

}

void procesarConsultaUsuari() {
    cout << "Operació processada." << endl;
}

void procesarModificaUsuari() {
    cout << "Operació processada." << endl;
}

void procesarEsborraUsuari() {
    cout << "Operació processada." << endl;
}


void menuGestioUsuaris() {
    int opcio = 0;
    do {
        cout << "1. Registre usuari" << endl;
        cout << "2. Consulta usuari" << endl;
        cout << "3. Modifica usuari" << endl;
        cout << "4. Esborra usuari" << endl;
        cout << "5. Tornar" << endl;
        cout << "Selecciona una opció: ";

        cin >> opcio;
        cin.ignore();

        switch (opcio) {

        case 1:
            procesarRegistreUsuari();
            break;

        case 2:
            procesarConsultaUsuari();
            break;

        case 3:
            procesarModificaUsuari();
            break;

        case 4:
            procesarEsborraUsuari();
            break;

        case 5:
            cout << "Tornant al menú principal..." << endl;
            break;

        default:
            cout << "Opció no vàlida." << endl;
        }
    }


    while (opcio != 5);

}



void procesarGestioPelicules() {
    cout << "Operació processada." << endl;
}

void procesarGestioSeries() {
    cout << "Operació processada." << endl;
}

void menuGestioContinguts() {
    int opcio = 0;

    do {
        cout << "1. Gestió pel·lícules" << endl;
        cout << "2. Gestió sèries" << endl;
        cout << "3. Tornar" << endl;
        cout << "Selecciona una opció: ";
        cin >> opcio;
        cin.ignore();

        switch (opcio) {
        case 1:
            procesarGestioPelicules();
            break;
        case 2:
            procesarGestioSeries();
            break;
        case 3:
            cout << "Tornant al menú principal..." << endl;
            break;
        default:
            cout << "Opció no vàlida." << endl;
        }
    } while (opcio != 3);
}


void procesarConsultaQualificacioEdat() {
    cout << "Operació processada." << endl;
}

void procesarUltimesNovetats() {
    cout << "Operació processada." << endl;
}

void procesarProximesEstrenes() {
    cout << "Operació processada." << endl;
}

void menuConsultes() {
    int opcio = 0;

    do {
        cout << "1. Consulta per qualificació d'edat" << endl;
        cout << "2. Últimes novetats" << endl;
        cout << "3. Pròximes estrenes" << endl;
        cout << "4. Tornar" << endl;
        cout << "Selecciona una opció: ";
        cin >> opcio;
        cin.ignore();

        switch (opcio) {
        case 1:
            procesarConsultaQualificacioEdat();
            break;
        case 2:
            procesarUltimesNovetats();
            break;
        case 3:
            procesarProximesEstrenes();
            break;
        case 4:
            cout << "Tornant al menú principal..." << endl;
            break;
        default:
            cout << "Opció no vàlida." << endl;
        }
    } while (opcio != 4);
}


int main() {

    int opcio = 0;
    do {

        cout << "1. Gestió usuaris" << endl;
        cout << "2. Gestió continguts" << endl;
        cout << "3. Consultes" << endl;
        cout << "4. Sortir" << endl;
        cout << "Selecciona una opció: ";

        cin >> opcio;
        cin.ignore();

        switch (opcio) {

        case 1:
            menuGestioUsuaris();
            break;

        case 2:
            menuGestioContinguts();
            break;

        case 3:
            menuConsultes();
            break;

        case 4:
            cout << "Sortint de l'aplicació..." << endl;
            break;

        default:
            cout << "Opció no vàlida. Si us plau, intenta-ho de nou." << endl;
        }

    } while (opcio != 4);

    return 0;

}

