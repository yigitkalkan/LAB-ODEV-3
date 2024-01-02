#ifndef DOGRUPARCASI_H
#define DOGRUPARCASI_H

#include "Nokta.h"

class DogruParcasi {
private:
    Nokta baslangicNoktasi;
    Nokta bitisNoktasi;

public:
    DogruParcasi();
    DogruParcasi(const Nokta& baslangic, const Nokta& bitis);
    DogruParcasi(const DogruParcasi& other);
    DogruParcasi(const Nokta& ortaNokta, double uzunluk, double egim);

    Nokta getBaslangicNoktasi() const;
    Nokta getBitisNoktasi() const;
    void setBaslangicNoktasi(const Nokta& baslangic);
    void setBitisNoktasi(const Nokta& bitis);
    double uzunluk() const;
    Nokta kesisimNoktasi(const DogruParcasi& digerParca) const;
    Nokta ortaNokta() const;
    std::string toString() const;
    void yazdir() const;
};

#endif // DOGRUPARCASI_H
