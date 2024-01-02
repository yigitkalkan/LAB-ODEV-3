#include "Daire.h"
#include <cmath>
#include <iostream>
// Elle tan�mlanm�� pi say�s�
#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502884L
#endif

Daire::Daire(const Nokta& merkez, double yaricap) : merkez(merkez), yaricap(yaricap) {}

Daire::Daire(const Daire& other) : merkez(other.merkez), yaricap(other.yaricap) {}

Daire::Daire(const Daire& other, double scalar) : merkez(other.merkez), yaricap(other.yaricap* scalar) {}

double Daire::alan() const {
    return M_PI * yaricap * yaricap;
}

double Daire::cevre() const {
    return 2 * M_PI * yaricap;
}

int Daire::kesisim(const Daire& other) const {
    double mesafe = merkez.distanceTo(other.merkez);
    double toplamYaricap = yaricap + other.yaricap;

    if (mesafe == 0 && yaricap == other.yaricap) {
        // Daireler birbirine �rt���yor
        return 1;
    }
    else if (mesafe < toplamYaricap) {
        // Daireler i� i�e
        return 0;
    }
    else {
        // Daireler kesiliyor veya birbirinden uzak
        return 2;
    }
}

std::string Daire::toString() const {
    return "Merkez: " + merkez.toString() + ", Yar��ap: " + std::to_string(yaricap);
}

void Daire::yazdir() const {
    std::cout << toString() << std::endl;
}
