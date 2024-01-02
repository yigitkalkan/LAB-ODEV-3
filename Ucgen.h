#ifndef UCGEN_H
#define UCGEN_H

#include "Nokta.h"

class Ucgen {
private:
    Nokta nokta1;
    Nokta nokta2;
    Nokta nokta3;

public:
    Ucgen(const Nokta& n1, const Nokta& n2, const Nokta& n3);
    Nokta getNokta1() const;
    Nokta getNokta2() const;
    Nokta getNokta3() const;
    void setNokta1(const Nokta& n1);
    void setNokta2(const Nokta& n2);
    void setNokta3(const Nokta& n3);
    std::string toString() const;
    double alan() const;
    double cevre() const;
    double* acilar() const;
};

#endif // UCGEN_H
