// DogruParcasi.cpp
#include <iostream>
#include "DogruParcasi.h"
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

DogruParcasi::DogruParcasi() : baslangicNoktasi(), bitisNoktasi() {}

DogruParcasi::DogruParcasi(const Nokta& baslangic, const Nokta& bitis) : baslangicNoktasi(baslangic), bitisNoktasi(bitis) {}

DogruParcasi::DogruParcasi(const DogruParcasi& other) : baslangicNoktasi(other.baslangicNoktasi), bitisNoktasi(other.bitisNoktasi) {}

DogruParcasi::DogruParcasi(const Nokta& ortaNokta, double uzunluk, double egim) {
    // Bu yapýcýyý doldurun
    double yaricap = uzunluk / 2.0;
    double aci = egim * M_PI / 180.0;  // Dereceyi radiana çevirin

    double dx = yaricap * cos(aci);
    double dy = yaricap * sin(aci);

    baslangicNoktasi = Nokta(ortaNokta.getX() - dx, ortaNokta.getY() - dy);
    bitisNoktasi = Nokta(ortaNokta.getX() + dx, ortaNokta.getY() + dy);
}

Nokta DogruParcasi::getBaslangicNoktasi() const {
    return baslangicNoktasi;
}

Nokta DogruParcasi::getBitisNoktasi() const {
    return bitisNoktasi;
}

void DogruParcasi::setBaslangicNoktasi(const Nokta& baslangic) {
    baslangicNoktasi = baslangic;
}

void DogruParcasi::setBitisNoktasi(const Nokta& bitis) {
    bitisNoktasi = bitis;
}

double DogruParcasi::uzunluk() const {
    // Ýki nokta arasýndaki uzaklýðý hesaplayýn
    double dx = bitisNoktasi.getX() - baslangicNoktasi.getX();
    double dy = bitisNoktasi.getY() - baslangicNoktasi.getY();
    return sqrt(dx * dx + dy * dy);
}

Nokta DogruParcasi::kesisimNoktasi(const DogruParcasi& digerParca) const {
    // Ýki doðru parçasý arasýndaki kesiþim noktasýný bulun ve bu noktayý döndürün.
    double x1 = baslangicNoktasi.getX();
    double y1 = baslangicNoktasi.getY();
    double x2 = bitisNoktasi.getX();
    double y2 = bitisNoktasi.getY();

    double x3 = digerParca.getBaslangicNoktasi().getX();
    double y3 = digerParca.getBaslangicNoktasi().getY();
    double x4 = digerParca.getBitisNoktasi().getX();
    double y4 = digerParca.getBitisNoktasi().getY();

    double det = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

    if (det == 0) {
        // Doðru parçalarý paralel, kesiþim noktasý yok.
        return Nokta();
    }

    double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / det;
    double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / det;

    if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
        // Ýki doðru parçasý kesiþiyor.
        double x = x1 + t * (x2 - x1);
        double y = y1 + t * (y2 - y1);
        return Nokta(x, y);
    }
    else {
        // Doðru parçalarý kesiþmiyor.
        return Nokta();
    }
}

Nokta DogruParcasi::ortaNokta() const {
    // Doðru parçasýnýn orta noktasýný hesaplayan kodu
    double x = (baslangicNoktasi.getX() + bitisNoktasi.getX()) / 2.0;
    double y = (baslangicNoktasi.getY() + bitisNoktasi.getY()) / 2.0;
    return Nokta(x, y);
}

std::string DogruParcasi::toString() const {
    return "Baþlangýç: " + baslangicNoktasi.toString() + ", Bitiþ: " + bitisNoktasi.toString();
}

void DogruParcasi::yazdir() const {
    std::cout << toString() << std::endl;
}
