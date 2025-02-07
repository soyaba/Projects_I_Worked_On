#include "LlibreE.hpp"

LlibreE::LlibreE() : titol(""), area("") {}

LlibreE::LlibreE(const LlibreE &le) : titol(le.titol), dataPub(le.dataPub), area(le.area), paraulesClau(le.paraulesClau) {}

LlibreE::LlibreE(const string &titol, const Data &dataPub, vector<string> paraulesClau)
    : titol(titol), dataPub(dataPub), area(""), paraulesClau(move(paraulesClau)) {}



LlibreE& LlibreE::operator=(const LlibreE &le) {
    if (this != &le) {
        titol = le.titol;
        dataPub = le.dataPub;
        area = le.area;
        paraulesClau = le.paraulesClau;
    }
    return *this;
}

LlibreE::~LlibreE() {}

void LlibreE::setArea(const string &area) {
    this->area = area;
}

string LlibreE::consultar_titol() const {
    return titol;
}

Data LlibreE::consultar_dataPub() const {
    return dataPub;
}

string LlibreE::consultar_area() const {
    return area;
}

bool LlibreE::compare(const LlibreE &le) const {
    return dataPub > le.dataPub;
}


vector<string> LlibreE::getParaulesClau() const {
    return paraulesClau;
}
std::vector<std::string>LlibreE::consultar_paraules_clau() const{
return paraulesClau;

}
