// Ucgen.cpp
#include "Ucgen.h"
#include <cmath>

Ucgen::Ucgen(const Nokta& n1, const Nokta& n2, const Nokta& n3) : nokta1(n1), nokta2(n2), nokta3(n3) {}

Nokta Ucgen::getNokta1() const {
    return nokta1;
}

Nokta Ucgen::getNokta2() const {
    return nokta2;
}

Nokta Ucgen::getNokta3() const {
    return nokta3;
}

void Ucgen::setNokta1(const Nokta& n1) {
    nokta1 = n1;
}

void Ucgen::setNokta2(const Nokta& n2) {
    nokta2 = n2;
}

void Ucgen::setNokta3(const Nokta& n3) {
    nokta3 = n3;
}

std::string Ucgen::toString() const {
    return "Üçgen; " + nokta1.toString() + ", " + nokta2.toString() + ", " + nokta3.toString();
}
#include "Ucgen.h"
#include <cmath>

// ...

double Ucgen::alan() const {
    // Üçgenin alanýný hesaplayan kodu
    double a = nokta1.distanceTo(nokta2);
    double b = nokta1.distanceTo(nokta3);
    double c = nokta2.distanceTo(nokta3);

    // Heron'un formülü kullanýlarak üçgenin alaný hesaplanýr
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Ucgen::cevre() const {
    // Üçgenin çevresini hesaplayan kodu
    double a = nokta1.distanceTo(nokta2);
    double b = nokta1.distanceTo(nokta3);
    double c = nokta2.distanceTo(nokta3);
    return a + b + c;
}

double* Ucgen::acilar() const {
    // Üçgenin açýlarýný hesaplayan kodu
    double* acilar = new double[3];

    double a = nokta1.distanceTo(nokta2);
    double b = nokta1.distanceTo(nokta3);
    double c = nokta2.distanceTo(nokta3);

    acilar[0] = acos((b * b + c * c - a * a) / (2 * b * c)) * (180.0 / std::acos(-1.0));
    acilar[1] = acos((a * a + c * c - b * b) / (2 * a * c)) * (180.0 / std::acos(-1.0));
    acilar[2] = acos((a * a + b * b - c * c) / (2 * a * b)) * (180.0 / std::acos(-1.0));

    return acilar;
}

