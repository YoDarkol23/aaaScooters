#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Scooters.h"
void loadScooter(Scooter **scooter, int *count) {
	FILE *file = fopen("scooter.txt", "rb");
	if (!file) {
		*count = 3;
		*scooter = malloc(*count * sizeof(Scooter));
		strcpy((*scooter)[0].name, "Молния");
		(*scooter)[0].price = 3000;
		(*scooter)[0].maxspeed = 30;
		strcpy((*scooter)[1].name, "Nimbus 3000");
		(*scooter)[1].price = 2500;
		(*scooter)[1].maxspeed = 27;
		strcpy((*scooter)[2].name, "Nimbus 3001");
		(*scooter)[2].price = 2700;
		(*scooter)[2].maxspeed = 28;
		return;
	}
	fread(count, sizeof(int), 1, file);
	*scooter = malloc((*count) * sizeof(Scooter));
	fread(*scooter, sizeof(Scooter), *count, file);
	fclose(file);
}
void saveScooter(Scooter *scooter, int count) {
	FILE *file = fopen("scooter", "wb");
	fwrite(&count, sizeof(int), 1, file);
	fwrite(scooter, sizeof(Scooter), count, file);
	fclose(file);
}
void addScooter(Scooter **scooter, int *count) {
	*scooter = realloc(*scooter, (*count + 1) * sizeof(Scooter));
	Scooter *newScooter = &(*scooter)[*count];
	printf("Marka: ");
	scanf("%s", newScooter->name);
	printf("Price: ");
	scanf("%i", &newScooter->price);
	printf("maxspeed: ");
	scanf("%f", &newScooter->maxspeed);
	(*count)++;
}
void editScooter(Scooter *scooter, int count) {
	int id;
	displayScooter(scooter, count);
	printf("Nomer product: ");
	scanf("%i", &id);
	if (id < 0 || id >= count) {
		printf("Neverno\n");
		return;
	}

	Scooter *selectedScooter = &scooter[id];
	printf("Марка: ");
	char temp[100];
	scanf("%s", temp);

	printf("Новая стоимость: ");
	int price;
	scanf("%i", &price);

	printf("Введите новое значение скорости:");
	float speed;
	scanf("%f", &speed);

	strcpy(selectedScooter->name, temp);
	selectedScooter->price = price;
    	selectedScooter->maxspeed = speed;

    printf("Данные успешно обновлены!\n");
}

void deleteScooter(Scooter **scooter, int *count) {
	int id;
	printf("Номер самоката, который нужно удалить:");
	scanf("%i", &id);
	if (id < 0 || id >= *count) {
		printf("Nevernoe znachenie\n");
		return;
	}

	for (int i = id; i < *count - 1; i++) {
		scooter[i] = scooter[i + 1];
	}
	(*count)--;
	scooter = realloc(scooter, (*count) * sizeof(Scooter));
}
void searchScooter(Scooter *scooter, int count) {
    char name[100]; 
    printf("Марка самоката: ");
    scanf("%99s", name); 

    int found = 0; 
    for (int i = 0; i < count; i++) { 
        if (strcmp(scooter[i].name, name) == 0) {
            printf("Scooter: %s, Price: %i, Speed: %.2f\n", scooter[i].name, scooter[i].price, scooter[i].maxspeed);
            found = 1; 
        }   
    }

    if (!found) {
        printf("Самокат с маркой '%s' не найден.\n", name); 
    }
}

void displayScooter(Scooter *scooter, int count) {
	for (int i = 0; i < count; i++) {
		printf("%i. Scooter: %s,  %i, Speed %f\n", i, scooter[i].name, scooter[i].price, scooter[i].maxspeed);
	}
}
