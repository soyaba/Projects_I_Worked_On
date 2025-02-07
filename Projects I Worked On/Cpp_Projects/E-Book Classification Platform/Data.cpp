#include "Data.hpp"

Data::Data() : dia(0), mes(0), any(0) {}

Data::Data(int dia, int mes, int any) : dia(dia), mes(mes), any(any) {}



int Data::getDia() const {
    return dia;
}

int Data::getMes() const {
    return mes;
}

int Data::getAny() const {
    return any;
}

bool Data::operator>(const Data &d) const {
    if (any > d.any) return true;
    if (any < d.any) return false;
    if (mes > d.mes) return true;
    if (mes < d.mes) return false;
    return dia > d.dia;
}


