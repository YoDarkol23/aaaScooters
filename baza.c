#include <stdio.h>
#include <stdlib.h>
#include "Scooters.h"

int main() {
    Scooter* scooter = NULL;
    int count = 0;
    loadScooter(&scooter, &count);
    int choice;
    do {
        printf("Menu:\n");
        printf("1. Display scooter\n");
        printf("2. Add scooter\n");
        printf("3. Edit scooter\n");
        printf("4. Delete scooter\n");
        printf("5. Search scoooter\n");
        printf("6. Save\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

		switch (choice) {
			case 1:
				displayScooter(scooter, count);
				break;
			case 2:
				addScooter(&scooter, &count);
				break;
			case 3:
				editScooter(scooter, count);
				break;
			case 4:
				deleteScooter(&scooter, &count);
				break;
			case 5:
				searchScooter(scooter, count);
				break;
			case 6:
				saveScooter(scooter, count);
				break;
			default:
				printf("Nevernoe znachenie, poprobuyte snova\n");
		}
	}
	while (choice != 6);
	free(scooter);
	return 0;
}
