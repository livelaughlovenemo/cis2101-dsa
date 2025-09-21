#include <stdio.h>
#include <stdbool.h>
#include "dragonHoard.h"

// TREASURE RETRIEVAL ENCHANTMENT (Pop Function)
void retrieveTreasure(Stack *s) {
    // [Task 1] To do code logic...



}


// Main adventure function
int main() {
    printf("The Dragon's Hoard Adventure\n");
    printf("Testing treasure pickup and retrieval\n\n");

    // Show menu and get single choice
    int choice;
    Stack kiraSatchel;
    VSpace mysticalStorage;

    // Initialize
    initVSpace(&mysticalStorage);
    initStack(&kiraSatchel, &mysticalStorage, 25.0);

    showAdventureMenu();
    scanf("%d", &choice);

    switch(choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            runCaveScenario(choice, &kiraSatchel, &mysticalStorage);
            break;

        case 7:
        case 8:
        case 9:
        case 10:
            runGuildScenario(choice, &kiraSatchel, &mysticalStorage);
            break;

        case 11:
            runAllScenarios();
            break;

        case 12:
            runInteractiveMode();
            break;

        case 0:
            printf("Program ended.\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}