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
    cout << "Operaci� processada." << endl;
}

void procesarModificaUsuari() {
    cout << "Operaci� processada." << endl;
}

void procesarEsborraUsuari() {
    cout << "Operaci� processada." << endl;
}


void menuGestioUsuaris() {
    int opcio = 0;
    do {
        cout << "1. Registre usuari" << endl;
        cout << "2. Consulta usuari" << endl;
        cout << "3. Modifica usuari" << endl;
        cout << "4. Esborra usuari" << endl;
        cout << "5. Tornar" << endl;
        cout << "Selecciona una opci�: ";

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
            cout << "Tornant al men� principal..." << endl;
            break;

        default:
            cout << "Opci� no v�lida." << endl;
        }
    }


    while (opcio != 5);

}



void procesarGestioPelicules() {
    cout << "Operaci� processada." << endl;
}

void procesarGestioSeries() {
    cout << "Operaci� processada." << endl;
}

void menuGestioContinguts() {
    int opcio = 0;

    do {
        cout << "1. Gesti� pel�l�cules" << endl;
        cout << "2. Gesti� s�ries" << endl;
        cout << "3. Tornar" << endl;
        cout << "Selecciona una opci�: ";
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
            cout << "Tornant al men� principal..." << endl;
            break;
        default:
            cout << "Opci� no v�lida." << endl;
        }
    } while (opcio != 3);
}


void procesarConsultaQualificacioEdat() {
    cout << "Operaci� processada." << endl;
}

void procesarUltimesNovetats() {
    cout << "Operaci� processada." << endl;
}

void procesarProximesEstrenes() {
    cout << "Operaci� processada." << endl;
}

void menuConsultes() {
    int opcio = 0;

    do {
        cout << "1. Consulta per qualificaci� d'edat" << endl;
        cout << "2. �ltimes novetats" << endl;
        cout << "3. Pr�ximes estrenes" << endl;
        cout << "4. Tornar" << endl;
        cout << "Selecciona una opci�: ";
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
            cout << "Tornant al men� principal..." << endl;
            break;
        default:
            cout << "Opci� no v�lida." << endl;
        }
    } while (opcio != 4);
}


int main() {

    int opcio = 0;
    do {

        cout << "1. Gesti� usuaris" << endl;
        cout << "2. Gesti� continguts" << endl;
        cout << "3. Consultes" << endl;
        cout << "4. Sortir" << endl;
        cout << "Selecciona una opci�: ";

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
            cout << "Sortint de l'aplicaci�..." << endl;
            break;

        default:
            cout << "Opci� no v�lida. Si us plau, intenta-ho de nou." << endl;
        }

    } while (opcio != 4);

    return 0;

}

