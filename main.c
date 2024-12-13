#include "People.h"

int main() {
    People *Peoples = NULL;
    int count = 0;
    load_People(&Peoples, &count, "People_data.txt");

    int choice;
    do {
        printf("Menu:\n");
        printf("1. Отобразить Сотрудников\n");
        printf("2. Добавить Сотрудников\n");
        printf("3. Удалить Сотрудников\n");
        printf("4. Редактировать список Сотрудников\n");
        printf("5. Поиск Сотрудников\n");
        printf("6. Выйти\n");
        printf("Введите номер команды: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_People(Peoples, count);
                break;
            case 2:
                add_People(&Peoples, &count);
                break;
            case 3: {
                int id;
                printf("Введите ID сотрудника для удаления: ");
                scanf("%d", &id);
                delete_People(Peoples, &count, id);
                break;
            }
            case 4: {
                int id;
                printf("Введите ID сотрудника для редактирования: ");
                scanf("%d", &id);
                edit_People(Peoples, count, id);
                break;
            }
            case 5:
                search_People(Peoples, count);
                break;
            case 6:
                save_People(Peoples, count, "People_data.txt");
                break;
            default:
                printf("Неверный номер команды\n");
        }
    } while (choice != 6);

    free(Peoples);
    return 0;
}



