#include <iostream>
#include "database.h"

using namespace std;
using namespace database;

int main() {
    Database db;
    db.load("data.txt");

    while (true) {
        cout << "\nМеню:\n"
             << "1. Вывести товары\n"
             << "2. Добавить товар\n"
             << "3. Удалить товар\n"
             << "4. Редактировать товар\n"
             << "5. Поиск\n"
             << "6. Выход\n"
             << "Введите номер: ";

        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            db.printAll();
        } else if (choice == 2) {
            string name;
            double price;
            int quantity;
            cout << "Название: ";
            getline(cin, name);
            cout << "Цена: ";
            cin >> price;
            cout << "Количество: ";
            cin >> quantity;
            db.addProduct(Product(name, price, quantity));
        } else if (choice == 3) {
            int index;
            cout << "Товар для удаления: ";
            cin >> index;
            db.deleteProduct(index);
        } else if (choice == 4) {
            int index;
            cout << "Товар для редактирования: ";
            cin >> index;
            cin.ignore();
            string name;
            double price;
            int quantity;
            cout << "Новое название: ";
            getline(cin, name);
            cout << "Новая цена: ";
            cin >> price;
            cout << "Новое количество: ";
            cin >> quantity;
            db.editProduct(index, Product(name, price, quantity));
        } else if (choice == 5) {
            string name;
            double maxPrice;
            cout << "Название содержит: ";
            cin.ignore();
            getline(cin, name);
            cout << "Максимальная цена: ";
            cin >> maxPrice;
            db.search(name, maxPrice);
        } else if (choice == 6) {
            break;
        }
    }

    db.save("data.txt");
    return 0;
}