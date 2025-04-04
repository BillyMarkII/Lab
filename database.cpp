#include "database.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
using namespace database;

Database::Database() : products(nullptr), size(0) {}

Database::~Database() {
    delete[] products;
}

void Database::nwsize(int newSize) {
    Product* newArr = new Product[newSize];
    for (int i = 0; i < size && i < newSize; ++i) {
        newArr[i] = products[i];
    }
    delete[] products;
    products = newArr;
    size = newSize;
}

void Database::load(const string& filename) {
     ifstream file(filename);
    if (!file) return;

    size = 0;
    delete[] products;
    products = nullptr;

    string line;
    while (getline(file, line)) size++;

    file.clear();
    file.seekg(0);

    products = new Product[size];
    for (int i = 0; i < size; ++i) {
         getline(file, line);
         istringstream ss(line);
        ss >> products[i];
    }
}

void Database::save(const  string& filename) {
    ofstream file(filename);
    for (int i = 0; i < size; ++i) {
        file << products[i] << "\n";
    }
}

void Database::addProduct(const Product& p) {
    resize(size + 1);
    products[size - 1] = p;
}

void Database::deleteProduct(int index) {
    if (index < 0 || index >= size) return;
    for (int i = index; i < size - 1; ++i) {
        products[i] = products[i + 1];
    }
    resize(size - 1);
}

void Database::editProduct(int index, const Product& newProduct) {
    if (index >= 0 && index < size) {
        products[index] = newProduct;
    }
}

void Database::printAll() const {
    for (int i = 0; i < size; ++i) {
         cout << i << ": " << products[i] <<  endl;
    }
}

void Database::search(const  string& name, double maxPrice) const {
    for (int i = 0; i < size; ++i) {
        if (products[i].getName().find(name) !=  string::npos &&
            products[i].getPrice() <= maxPrice) {
             cout << products[i] <<  endl;
        }
    }
}