
#include "class_product.h"
#include <string>
namespace database {
using namespace std;
class Database {
private:
    Product* products;
    int size;
    void nwsize(int newSize);

public:
    Database();
    ~Database();

    void load(const string& filename);
    void save(const string& filename);

    void addProduct(const Product& p);
    void deleteProduct(int index);
    void editProduct(int index, const Product& newProduct);
    void printAll() const;
    void search(const string& name, double maxPrice) const;
};

}

