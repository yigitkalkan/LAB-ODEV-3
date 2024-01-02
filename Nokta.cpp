#include "Nokta.h"
#include <iostream>
#include <cmath>

Nokta::Nokta() : x(0), y(0) {}

Nokta::Nokta(double x) : x(x), y(x) {}

Nokta::Nokta(double x, double y) : x(x), y(y) {}

Nokta::Nokta(const Nokta& other) : x(other.x), y(other.y) {}

Nokta::Nokta(const Nokta& other, double ofset_x, double ofset_y) : x(other.x + ofset_x), y(other.y + ofset_y) {}

double Nokta::getX() const {
    return x;
}

void Nokta::setX(double x) {
    this->x = x;
}

double Nokta::getY() const {
    return y;
}

void Nokta::setY(double y) {
    this->y = y;
}

void Nokta::set(double x, double y) {
    setX(x);
    setY(y);
}

std::string Nokta::toString() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

void Nokta::yazdir() const {
    std::cout << toString() << std::endl;
}

double Nokta::distanceTo(const Nokta& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return sqrt(dx * dx + dy * dy);
}
