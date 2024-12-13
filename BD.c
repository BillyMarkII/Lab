#include "People.h"

void load_People(People **Peoples, int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return;
    }

    *count = 0;
    while (!feof(file)) {
        *Peoples = realloc(*Peoples, (*count + 1) * sizeof(People));
        fscanf(file, "%d;%c;%c;%i\n", &(*Peoples)[*count].id, (*Peoples)[*count].name, (*Peoples)[*count].pos, &(*Peoples)[*count].Zp);
        (*count)++;
    }
    fclose(file);
}

void save_People(People *Peoples, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d;%s;%s;%i\n", Peoples[i].id, Peoples[i].name, Peoples[i].pos, Peoples[i].Zp);
    }
    fclose(file);
}

void display_People(People *Peoples, int count) {
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Имя: %s, Должность: %s, Зп: %i\n", Peoples[i].id, Peoples[i].name, Peoples[i].pos, Peoples[i].Zp);
    }
}

void add_People(People **Peoples, int *count) {
    *Peoples = realloc(*Peoples, (*count + 1) * sizeof(People));
    printf("Введите ID: ");
    scanf("%d", &(*Peoples)[*count].id);
    printf("Введите Имя: ");
    scanf("%s", (*Peoples)[*count].name);
    printf("Введите должность: ");
    scanf("%s", (*Peoples)[*count].pos);
    printf("Введите Зп: ");
    scanf("%i", &(*Peoples)[*count].Zp);
    (*count)++;
}

void delete_People(People *Peoples, int *count, int id) {
    for (int i = 0; i < *count; i++) {
        if (Peoples[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                Peoples[j] = Peoples[j + 1];
            }
            (*count)--;
            return;
        }
    }
}

void edit_People(People *Peoples, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (Peoples[i].id == id) {
            printf("Введите новое имя: ");
            scanf("%s", Peoples[i].name);
            printf("Введите новую должность: ");
            scanf("%s", Peoples[i].pos);
            printf("Введите Зп: ");
            scanf("%i", &Peoples[i].Zp);
            return;
        }
    }
}

void search_People(People *Peoples, int count) {
    char name[50];
    printf("Введите имя для поиска: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(Peoples[i].name, name) == 0) {
            printf("Найдено: ID: %d, Имя: %s, Должность: %s, Зп: %i\n", Peoples[i].id, Peoples[i].name, Peoples[i].pos, Peoples[i].Zp);
        }
    }
    printf("Введите должность для поиска");
    char pos[50];
    scanf("%c", pos);
    for (int i = 0; i < count; i++) {
        if (strcmp(Peoples[i].pos, pos) == 0) {
            printf("Найдено: ID: %d, Имя: %s, Должность: %s, Зп: %i\n", Peoples[i].id, Peoples[i].name, Peoples[i].pos, Peoples[i].Zp);
        }
    }
}
