#include <stdio.h>

struct Pokemon {
    int Id;
    char Name[10];
    char KnownAs[30];
    char Type1[10];
    char Type2[10];
    char Description[100];

} typedef pokemon;

int main(void) {
    pokemon pkmStorage[1002];
    int pkmCounter = 0;
    int option = 0;

    printf("------------------- My Pokedex -------------------\n");
    printf("   1. Insert a new Pokémon.\n");
    printf("   2. Edit a Pokemon.\n");
    printf("   3. Delete a Pokemon.\n");
    printf("   4. Exit\n\n.");

    scanf("%d", &option);

    switch(option){
        case 1:
            printf("Digit his name: ");
            fgets(pkmStorage[pkmCounter].Name, 10, stdin);
            printf("Digit how he is known as: ");
            fgets(pkmStorage[pkmCounter].KnownAs, 30, stdin);
            printf("Digit his type 1: ");
            fgets(pkmStorage[pkmCounter].Type1, 10, stdin);
            printf("Digit his type 2: ");
            fgets(pkmStorage[pkmCounter].Type2, 10, stdin);
            printf("Digit his description: ");
            fgets(pkmStorage[pkmCounter].Description, 100, stdin);
            pkmCounter++;

            break;
        case 2:
            break;
        case 3:
            break;
        default:

    }

    return 0;
}