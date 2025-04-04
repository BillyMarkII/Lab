#include "class_product.h"
using namespace std;

Product::Product() : name(""), price(0.0), quantity(0) {}
Product::Product(string n, double p, int q) : name(n), price(p), quantity(q) {}

void Product::setName(const string& n) { name = n; }
void Product::setPrice(double p) { price = p; }
void Product::setQuantity(int q) { quantity = q; }

string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }

ostream& operator<<(ostream& os, const Product& p) {
    os << p.name << "," << p.price << "," << p.quantity;
    return os;
}

istream& operator>>(istream& is, Product& p) {
    getline(is, p.name, ',');
    is >> p.price;
    is.ignore();
    is >> p.quantity;
    is.ignore();
    return is;
}