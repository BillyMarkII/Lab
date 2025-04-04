#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    double price;
    int quantity;

public:
    Product();
    Product(string n, double p, int q);

    void setName(const string& n);
    void setPrice(double p);
    void setQuantity(int q);

    string getName() const;
    double getPrice() const;
    int getQuantity() const;

    friend ostream& operator<<(ostream& os, const Product& p);
    friend istream& operator>>(istream& is, Product& p);
};
