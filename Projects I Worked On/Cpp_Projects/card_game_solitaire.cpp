#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Carta {
    int rang;  //Inv: 1 <= rang <= 13
    char pal; //Inv: pal ha de ser C, D, P o T
};

void imprimirCarta(const Carta &carta) {
//Accio que imprimeix per pantalla una carta en un format diferent al d'abans.
//Pre: carta es de tipus Carta passat per referència constant. 
//Post: modifica la estructura de carta segons el seu rang i pal i el passa a un string.

    bool vermell = false;
    string rangStr;
    if (carta.rang == 1)
    {
        rangStr = "A";
    }
    else if (carta.rang == 11)
    {
        rangStr = "J";
    }
    else if (carta.rang == 12)
    {
        rangStr = "Q";
    }
    else if (carta.rang == 13)
    {
        rangStr = "K";
    }
    else
    {
        rangStr = to_string(carta.rang);
    }

    string palStr;
    if (carta.pal == 'C')
    {
        palStr = "\033[0;31m\u2665";
        vermell = true;
    }
    else if (carta.pal == 'D')
    {
        palStr = "\033[0;31m\u2666";
        vermell = true;
    }
    else if (carta.pal == 'P')
    {
        palStr = "\u2660";
    }
    else if (carta.pal == 'T')
    {
        palStr = "\u2663";
    }

    cout << rangStr << palStr;
    
    if (vermell) {
        cout << "\033[0m";
    }
}

bool esVermellCarta(const Carta &carta) {
//Funcio booleana que ens indica si una carta es vermella veient el seu pal.
//Pre: carta es de tipus Carta passat per referencia constant.
//Post: retorna true en cas de que el pal de carta sigui C o D, false en cas contrari.

    return carta.pal == 'C' or carta.pal == 'D';
}


Carta analizarCarta(const string &cartaString) {
//Funcio de tipus Carta que analitza el rang que rep com a string (cartaString) 
//Pre: cartaString es un string de dos o tres caracters passat per referencia constant
//Post: retorna una Carta analitzant el string que rep com a entrada i li asigna el rang 

    Carta carta;
    carta.pal = cartaString.back();

    if (cartaString.size() == 3 and cartaString[0] == '1' and cartaString[1] == '0') {
        carta.rang = 10;
    } else {
        char rankChar = cartaString[0];

        if (rankChar == 'A')
        {
            carta.rang = 1;
        }

        else if (rankChar == 'J')
        {
            carta.rang = 11;
        }

        else if (rankChar == 'Q')
        {
            carta.rang = 12;
        }

        else if (rankChar == 'K')
        {
            carta.rang = 13;
        }

        else
        {
            carta.rang = rankChar - '0';
        }
    }
    return carta;
}

struct Pila {
    vector<Carta> cartes;
};

bool estaBuit(const Pila &pila) {
//Funcio booleana que ens indica si una pila està buida o no.
//Pre: Pila es de tipus Pila (vector de de tipus Carta) passat per referencia constant.
//Post: Retorna true en cas que la pila estigui buida i fals en cas de que no estigui buida

    return pila.cartes.size() == 0;
}

Pila llegirPilaDeEntrada() {
//Funcio de tipus Pila que llegeix una Pila d'entrada.
//Post: retorna una pila llegida com a string que rep pel canal d'entrada.

    Pila pila;
    int cartaCont;
    cin >> cartaCont;
    for (int i = 0; i < cartaCont; i++)
    {
        string cartaString;
        cin >> cartaString;
        Carta carta = analizarCarta(cartaString);
        pila.cartes.push_back(carta);
    }
    return pila;
}

void imprimirPila(const Pila &pila, bool showString) {
//Procediment que ens imprimeix pel canal de sortida el primer element de la pila, en cas que
//la pila estigui buida ens treu un '-' pel canal de sortida
//Pre: Pila es de tipus Pila passat per referencia constant i showString es un boolea
//Post: Ens treu per pantalla el primer element de la pila  i si no hi ha ens treu un guio

    if (showString) cout << "Pila: ";

    if (pila.cartes.size() == 0) {
        cout << "-";
    } else {
        imprimirCarta(pila.cartes[0]);
    }
    cout << endl;
}


void descartarIMostrarSeguent(Pila &pila) {
//Procediment que ens treu per pantalla la carta seguent de la que hem descartat de la pila, la carta descartada
//es possa al final del vector pila i totes les altres les possa cap una posició abans.
//Pre: Pila es de tipus Pila passat per referencia.
//Post: Imprimeix per pantalla la seguent carta que hem descartat de la pila.

    if (pila.cartes.empty()) {
        cout << "La pila esta buida" << endl;
    } else {
        Carta descartar = pila.cartes[0];
        for (int i = 0; i < pila.cartes.size() - 1; i++) {
            pila.cartes[i] = pila.cartes[i + 1];
        }
        pila.cartes[pila.cartes.size() - 1] = descartar;
    }
    imprimirPila(pila, false);
}

struct Magatzem {
    vector<Carta> cartes;
};

bool estaPle(const Magatzem &magatzem) {
//Funcio booleana que ens indica si un magatzem esta ple (te 13 cartes) o no
//Pre: Magatzem es de tipus Magatzem passat per referencia constant.
//Post: Retorna true si el magatzem esta ple, o sigui te dins tretze cartes, retorna false en cas contrari
    return magatzem.cartes.size() == 13;
}

bool estaBuit(const Magatzem &magatzem) {
//Funcio booleana que ens indica si un magatzem esta buit o no
//Pre: Magatzem es de tipus Magatzem passat per referencia constant.
//Post: Retorna true si dins del vector de magatzem no hi ha cap carta, retorna false en cas contrari.

    return magatzem.cartes.size() == 0;
}

bool potColocarCarta(const Magatzem &magatzem, const Carta &carta){
//Funció booleana verifica si una carta pot ser col·locada en un magatzem de cartes.
//pre: Magatzem es de tipus Magatzem passat per referencia constant i carta es de tipus Carta passat per referencia constant.
//post: La funció torna true si la carta compleix les condicions per ser col·locada al magatzem, en cas contrari, torna false.
    if (estaBuit(magatzem))
    {
        return carta.rang == 1;
    }

    const Carta ultimaCarta = magatzem.cartes.back();

    if (ultimaCarta.rang == 13)
    {
        return false; // esta lleno
    }

    return carta.rang == ultimaCarta.rang + 1 && carta.pal == ultimaCarta.pal;
}

void llocDeCarta(Magatzem &magatzem, const Carta &carta){
//La funció afegeix una carta al magatzem de cartes especificat.
//Pre: Magatzem es de tipus Magatzem passat per referencia constant i carta es de tipus Carta passat per referencia constant.
//Post: No es realitzen altres operacions al magatzem i no es torna cap valor.

    magatzem.cartes.push_back(carta);
}

void eliminarCarta(Magatzem &magatzem){
//La funció elimina la darrera carta del magatzem de cartes especificat
//pre:Modificant l'estat del magatzem passat com a referència. 
//post:No es realitzen altres operacions al magatzem i no es torna cap valor.
    magatzem.cartes.pop_back();
}

struct Magatzems
{
    vector<Magatzem> m = vector<Magatzem>(4);
};


Magatzems llegirMagatzemsDeEntrada(){
//Llegeix les cartes dels magatzems de cartes des de l'entrada estàndard.
//post:La funció retorna l'objecte magatzem que conté els magatzems de cartes llegits des de l'entrada estàndard.
    Magatzems magatzems;

    for (int i = 0; i < 4; i++)
    {
        int cartaCont;
        cin >> cartaCont;
        for (int j = 0; j < cartaCont; j++)
        {
            string cartaString;
            cin >> cartaString;
            Carta carta = analizarCarta(cartaString);
            llocDeCarta(magatzems.m[i], carta);
        }
    }
    return magatzems;
}

void imprimirMagatzem(const Magatzem &m, const int index){
//La funció recorre el vector de cartes del magatzem i imprimeix cada carta en un format específic.
//Pre: m que és una referència constant a un objecte de tipus Magatzem  i index que és un enter que representa líndex del magatzem.
//Post: Si el magatzem és buit, s'imprimeix un guió ("-") per indicar que no hi ha cartes al magatzem.

    cout << "Mag " << index << ": ";
    if (m.cartes.size() == 0)
    {
        cout << "-";
    }
    else
    {
        for (int i = 0; i < m.cartes.size(); i++)
        {
            imprimirCarta(m.cartes[i]);
            if (i != m.cartes.size() - 1)
                cout << " ";
        }
    }
}

void imprimirMagatzems(const Magatzems &magatzems){
//La funcio s'encarrega d'imprimir el contingut d'un conjunt de magatzems de cartes.
//Pre: magatzems es una referencia constante a un objeto de tipo Magatzems.
//Post: Imprime el contenido de un conjunto de almacenes de cartas. Llama a la función 'imprimirMagatzem' para imprimir cada almacén en el conjunto.
    for (int i = 0; i < 4; i++)
    {
        imprimirMagatzem(magatzems.m[i], i + 1);
        cout << endl;
    }
}

/*
    Columnes
*/

typedef vector<vector<Carta> > Columnes;

bool esPotColocarEnColumna(const Columnes &columnes, int columnaIndex, const Carta &carta){
// Verifica si una carta es pot col·locar en una columna específica del conjunt de columnes.
// Pre: columnes és una referència constant a un objecte de tipus Columnes, columnaIndex és un sencer que representa l'índex de la columna i carta és una referència constant a un objecte de tipus Carta.
// Post: Retorna 'true' si la carta es pot col·locar a la columna especificada , 'false' en cas contrari.
    if (columnaIndex < 0 or columnaIndex >= columnes.size())
    {
        return false;
    }

    vector<Carta> columna = columnes[columnaIndex];

    if (columna.size() == 0)
    {
        return carta.rang == 13;
    }

    Carta ultimaCarta = columna.back();
    return (esVermellCarta(ultimaCarta) != esVermellCarta(carta)) and ultimaCarta.rang == carta.rang + 1;
}

bool colocarCartaEnColumna(Columnes &columnes, int columnaIndex, const Carta &carta){
// Col·loca una carta en una columna específica del conjunt de columnes.
// Pre: columnes és una referència a un objecte de tipus Columnes, columnaIndex és un sencer que representa l'índex de la columna i carta és una referència constant a un objecte de tipus Carta.
// Post: Retorna true si la carta es col·loca amb èxit a la columna especificada, false en cas contrari.
    if (!esPotColocarEnColumna(columnes, columnaIndex, carta))
    {
        return false;
    }

    columnes[columnaIndex].push_back(carta);
    return true;
}

Columnes llegirColumnesDeEntrada(){
// Llegeix les columnes des de l'entrada estàndard i les emmagatzema en una estructura de dades adequada.
// Pre:-
// Post: Retorna un objecte de tipus Columnes que conté les columnes de cartes llegides.
    Columnes columnes;
    string line;
    for (int i = 0; i < 7; i++)
    {
        getline(cin, line);
        vector<Carta> columna;
        string cartaString;
        int start = 0, end = 0;

        // Ignorar el primer número
        end = line.find(' ');
        start = end + 1;

        while (end != string::npos)
        {
            end = line.find(' ', start);
            cartaString = line.substr(start, end - start);
            columna.push_back(analizarCarta(cartaString));
            start = end + 1;
        }

        columnes.push_back(columna);
    }

    return columnes;
}

void imprimirColumnes(const Columnes &columnes){
// Imprimeix les columnes de cartes en un format específic.
// Pre: columnes és una referència constant a un objecte de tipus Columnes que conté les columnes de cartes.
//post: S'imprimeix a la sortida estàndard el contingut de les columnes de cartes , si la columna és buida, s'imprimeix un guió ("-"). Al final de la impressió de les columnes, s'imprimeix una línia de separació "---".
    for (int i = 0; i < columnes.size(); i++)
    {
        cout << "Col " << i + 1 << ": ";
        for (int j = 0; j < columnes[i].size(); j++)
        {
            imprimirCarta(columnes[i][j]);
            if (j != columnes[i].size() - 1)
            {
                cout << " ";
            }
        }

        if (columnes[i].size() == 0)
            cout << "-";
        cout << endl;
    }
    cout << "---" << endl;
}

/*
   FUNCIONALITATS DEL JOC GENERALS
*/
bool moverCarta(const string &origenStr, const string &destStr, int num, Pila &pila, Columnes &cols, Magatzems &magatzems){
// Mou una carta d'una ubicació a una altra dins del joc.
// Pre: origenStr i destStr són cadenes que representen les ubicacions d'origen i de destinació respectivament.
// num és un enter que indica el nombre de cartes a moure.
// pila és una referència a un objecte de tipus Pila que representa la pila de cartes.
// cols és una referència a un objecte de tipus Columnes que representa les columnes de cartes.
// magatzems és una referència a un objecte de tipus Magatzems que representa els magatzems de cartes.
// Post: S'intenta moure la carta(es) de la ubicació d'origen a la ubicació de destinació.
// Si l'operació és exitosa, s'actualitza l'estructura de dades corresponent i es torna true.
// En cas d'error, s'imprimeix un missatge d'error específic i es torna false.

    int colIndex = origenStr[1] - '1';
    bool success = true;

    // Cas de Pila
    if (origenStr.size() == 1 and origenStr[0] == 'P')
    {

        if (pila.cartes.empty())
        {
            cout << "Origen del moviment no valid" << endl;
            return false;
        }
        if (destStr[0] == 'P')
        {
            cout << "No es poden moure cartes a la pila" << endl;
            return false;
        }

        if (pila.cartes.empty())
        {
            cout << "Error: Pila buida" << endl;
            return false;
        }
        // de pila a columna
        if (destStr[0] == 'C')
        {
            // ho intento moure a una columna, només 1 carta i es pot posar a la columna
            // si alguna d'aquestes condicions és falsa, falla
            if (num != 1)
            {
                cout << "Error: Nombre de cartes a moure incorrecte" << endl;
                success = false;
            }
            else if (!esPotColocarEnColumna(cols, destStr[1] - '1', pila.cartes.front()))
            {
                cout << "Error: No hi ha concordança de valor i/o pal" << endl;
                success = false;
            }
            else
            {
                colocarCartaEnColumna(cols, destStr[1] - '1', pila.cartes.front());
                // erase front
                pila.cartes.erase(pila.cartes.begin());
            }
        }
        // de pila a magatzem
        else if (destStr[0] == 'M')
        {
            // mover a un magatzem buit una carta que no es un as
            if (num != 1)
            {
                cout << "Error: Nombre de cartes a moure incorrecte" << endl;
                success = false;
            }
            else if (magatzems.m[destStr[1] - '1'].cartes.size() == 0 and pila.cartes.front().rang != 1)
            {
                cout << "Error: A un magatzem buit sols es pot moure un as" << endl;
                success = false;
            }
            else if (!potColocarCarta(magatzems.m[destStr[1] - '1'], pila.cartes.front()))
            {
                cout << "Error: No hi ha concordança de valor i/o pal" << endl;
                success = false;
            }
            else
            {
                llocDeCarta(magatzems.m[destStr[1] - '1'], pila.cartes.front());
                pila.cartes.erase(pila.cartes.begin());
            }
        }
        else
        {
            success = false;
        }
    }

    // Cas de Columna
    else if (origenStr[0] == 'C')
    {

        if (cols[colIndex].empty())
        {
            cout << "Origen del moviment no valid" << endl;
            return false;
        }
        if (destStr[0] == 'P')
        {
            cout << "No es poden moure cartes a la pila" << endl;
            return false;
        }

        // de columna a magatzem
        if (destStr[0] == 'M')
        {
            if (magatzems.m[destStr[1] - '1'].cartes.size() == 0 && cols[colIndex].back().rang != 1)
            {
                cout << "Error: A un magatzem buit sols es pot moure un as" << endl;
                success = false;
            }
            else if (num != 1 or !potColocarCarta(magatzems.m[destStr[1] - '1'], cols[colIndex].back()))
            {
                cout << "Error: No hi ha concordança de valor i/o pal" << endl;
                success = false;
            }
            else
            {
                llocDeCarta(magatzems.m[destStr[1] - '1'], cols[colIndex].back());
                cols[colIndex].pop_back();
            }
        }
        else if (destStr[0] == 'C')
        {
            int destIndex = destStr[1] - '1';
            if (num > cols[colIndex].size() || num < 1)
            {
                cout << "Error: Nombre de cartes a moure incorrecte" << endl;
                success = false;
            }
            else
            {
                vector<Carta> cardsToMove(cols[colIndex].end() - num, cols[colIndex].end());

                for (int i = 0; i < cardsToMove.size() - 1 && success; i++)
                {
                    if (cardsToMove[i].rang <= cardsToMove[i + 1].rang)
                    {
                        cout << "Error: El pilo indicat no es pot moure" << endl;
                        return false;
                    }
                }

                if (esPotColocarEnColumna(cols, destIndex, cardsToMove.front()))
                {
                    for (int i = 0; i < num; i++)
                    {
                        Carta carta = cardsToMove[i];
                        colocarCartaEnColumna(cols, destIndex, carta);
                    }
                    cols[colIndex].erase(cols[colIndex].end() - num, cols[colIndex].end());
                }

                else if (cols[destIndex].size() == 0 && cardsToMove.front().rang != 13)
                {
                    cout << "Error: A una columna buida sols es pot moure un rei" << endl;
                    success = false;
                }

                else
                {
                    cout << "Error: No hi ha concordança de valor i/o pal" << endl;
                    success = false;
                }
            }
        }
        else
        {
            success = false;
        }
    }
    
    //Cas de Magatzem a columna
    else if (origenStr[0] == 'M' and destStr[0] == 'C')
    {
        int magatzemIndex = origenStr[1] - '1';

        if (magatzems.m[magatzemIndex].cartes.empty())
        {
            cout << "Origen del moviment no valid" << endl;
            return false;
        }

        if (destStr[0] == 'P')
        {
            cout << "No es poden moure cartes a la pila" << endl;
            return false;
        }

        int columnaIndex = destStr[1] - '1';

        if (num != 1)
        {
            cout << "Error: Nombre de cartes a moure incorrecte" << endl;
            success = false;
        }
        else if (!esPotColocarEnColumna(cols, columnaIndex, magatzems.m[magatzemIndex].cartes.back()))
        {
            cout << "Error: No hi ha concordança de valor i/o pal" << endl;
            success = false;
        }
        else
        {
            colocarCartaEnColumna(cols, columnaIndex, magatzems.m[magatzemIndex].cartes.back());
            magatzems.m[magatzemIndex].cartes.pop_back();
        }
    }
    else
    {
        success = false;
    }

    return success;
}

void imprimirEstat(const Columnes &columnes, const Magatzems &magatzems, const Pila &pila){
// Imprimeix l'estat actual del joc, incloent-hi la pila de cartes, els magatzems de cartes i les columnes de cartes.
//pre: Rep com a paràmetres columnes, magatzems i pila.
//post: La funció s'encarrega d'imprimir a la sortida estàndard l'estat actual del joc, mostrant la pila de cartes, els magatzems de cartes i les columnes de cartes.

    imprimirPila(pila, true);
    imprimirMagatzems(magatzems);
    imprimirColumnes(columnes);
}

/*
    MAIN
*/
int main()
{
    // juego();

    Columnes cols = llegirColumnesDeEntrada();
    Magatzems magatzems = llegirMagatzemsDeEntrada();
    Pila pila = llegirPilaDeEntrada();
    int moviments = 0;
    char command;
    bool end = false;
    while (!end && cin >> command)
    {
        if (command == 'D')
        {
            moviments++;
            descartarIMostrarSeguent(pila);
        }
        if (command == 'S')
            imprimirEstat(cols, magatzems, pila);
        if (command == 'Z')
            end = true;
        if (command == 'M')
        {
            moviments++;
            string origenStr, destStr;
            int num;
            cin >> origenStr >> num >> destStr;
            moverCarta(origenStr, destStr, num, pila, cols, magatzems);
        }
    }

    // comprovar que hem guanyat
    // imprimirEstat(cols, magatzems, pila);

    bool win = true;
    for (int i = 0; i < 4; i++)
    {
        if (magatzems.m[i].cartes.size() != 13)
            win = false;
    }

    string movimentStr;
    if (moviments == 1)
        movimentStr = " moviment";
    else
        movimentStr = " moviments";

    if (win)
    {
        cout << "Felicitats has guanyat!! Ho has fet en " << moviments << movimentStr << ".";
    }
    else
    {
        cout << "No has guanyat i has fet " << moviments << movimentStr << ".";
    }
    cout << endl;
}

