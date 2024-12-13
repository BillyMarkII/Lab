#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char pos[50];
    int Zp;
} People;

void load_People(People **Peoples, int *count, const char *filename);
void save_People(People *Peoples, int count, const char *filename);
void display_People(People *Peoples, int count);
void add_People(People **Peoples, int *count);
void delete_People(People *Peoples, int *count, int id);
void edit_People(People *Peoples, int count, int id);
void search_People(People *Peoples, int count);
