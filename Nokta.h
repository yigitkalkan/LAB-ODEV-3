#ifndef NOKTA_H
#define NOKTA_H

#include <string>

class Nokta {
private:
    double x;
    double y;

public:
    Nokta();
    Nokta(double x);
    Nokta(double x, double y);
    Nokta(const Nokta& other);
    Nokta(const Nokta& other, double ofset_x, double ofset_y);

    // Getter ve setter metotlarý
    double getX() const;
    void setX(double x);
    double getY() const;
    void setY(double y);
    void set(double x, double y);

    // Diðer metotlar
    std::string toString() const;
    void yazdir() const;
    double distanceTo(const Nokta& other) const;
};

#endif // NOKTA_H
