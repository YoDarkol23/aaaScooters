#include <stdio.h>

typedef struct {
    char name[50];
    int price;
    float maxspeed;
} Scooter;

void displayScooter(Scooter *scooter, int count);
void searchScooter(Scooter *scooter, int count);
void addScooter(Scooter **scooter, int* count);
void deleteScooter(Scooter **scooter, int* count);
void editScooter(Scooter *scooter, int conut);
void loadScooter(Scooter **scooter, int* count);
void saveScooter(Scooter *scooter, int count);

