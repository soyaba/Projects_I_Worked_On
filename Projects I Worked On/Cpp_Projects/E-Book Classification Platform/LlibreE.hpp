#ifndef LLIBREE_HPP
#define LLIBREE_HPP
#include "Data.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define nat unsigned int

class LlibreE {
public:
    //*********************************************************
    // Constructors i assignació
    //*********************************************************
    
    /* Pre: cert */ 
    /* Post: crea un llibre amb el títol, data de publicació i 
       àrea buits, i sense paraules clau */
    LlibreE();
    
    /* Pre: cert */ 
    /* Post: crea un llibre amb el títol, data de publicació, 
       àrea i paraules clau del llibre 'le' */
    LlibreE(const LlibreE &le);
    
    /* Pre: cert */
    /* Post: crea un llibre amb el títol, data de publicació, 
       àrea i paraules clau */
    LlibreE(const string &titol, const Data &dataPub, vector<string> paraulesClau);
    
    /* Pre: cert */
    /* Post: el resultat és un llibre amb el títol, data de 
       publicació, àrea i paraules clau del llibre 'le' */     
    LlibreE& operator=(const LlibreE &le);
      
    //*********************************************************
    // Destructor
    //*********************************************************
    
    /* Destructor per defecte */ 
    ~LlibreE();
  
    //*********************************************************
    // Modificadors
    //*********************************************************

    void setArea(const string &area);
  
    //*********************************************************
    // Consultors
    //*********************************************************
    
    /* Pre: cert */ 
    /* Post: el resultat és el títol del llibre p.i. */
    string consultar_titol() const;
  
    /* Pre: cert */ 
    /* Post: el resultat és la data de publicació del llibre p.i. */
    Data consultar_dataPub() const;
  
    /* Pre: cert */ 
    /* Post: el resultat és l'àrea temàtica del llibre p.i. */
    string consultar_area() const;
  
    /* Pre: cert */
    /* Post: retorna un booleà que indica si la data de publicació del 
       llibre p.i. és posterior a la del llibre 'le' (true) o no ho és (false) */
    bool compare(const LlibreE &le) const;
    vector <string> getParaulesClau() const;
    //*********************************************************
    // Lectura i escriptura
    //*********************************************************

    /* Pre: cert */
    /* Post: s'han escrit els atributs del llibre al canal estàndard de sortida */
   std::vector<std::string>consultar_paraules_clau() const;

private:
    string titol;
    Data dataPub;
    string area;
    vector<string> paraulesClau;
};
#endif

