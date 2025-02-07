#ifndef DATA_HPP
#define DATA_HPP

class Data {
public:
    Data();
    Data(int dia, int mes, int any);
    
    int getDia() const;
    int getMes() const;
    int getAny() const;
    
    void setDia(int dia);
    void setMes(int mes);
    void setAny(int any);

    bool operator<(const Data& d) const;
    bool operator>(const Data& d) const;
    bool operator==(const Data& d) const;

private:
    int dia;
    int mes;
    int any;
};

#endif

