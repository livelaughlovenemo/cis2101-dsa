#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

// Deplane passengers: front row (0) -> back row (MAX_ROWS-1)
// Within each row: ABC group (left side) and DEF group (right side)
// Pops passengers until both stacks are empty
void deplanePassengers(BoardingList* list) {
    printf("\n=== Deplaning Passengers ===\n");

    for (int i = 0; i < MAX_ROWS; i++) {
        Row* row = &list->seatRows[i];

        // Deplane from ABC stack (Aisle → Middle → Window)
        while (!isEmpty_v1(&row->ABC)) {
            Passenger* p = &row->ABC.p[row->ABC.top];
            printf("Passenger %s from row %d (ABC) has deplaned.\n",
                   p->passengerName, i + 1);
            pop_v1(&row->ABC);
            list->passengerCount--;
        }

        // Deplane from DEF stack (Aisle → Middle → Window)
        while (!isEmpty_v2(&row->DEF)) {
            Passenger* p = &row->DEF.p[row->DEF.top - 1];
            printf("Passenger %s from row %d (DEF) has deplaned.\n",
                   p->passengerName, i + 1);
            pop_v2(&row->DEF);
            list->passengerCount--;
        }
    }

    printf("All passengers have deplaned. Remaining count: %d\n",
           list->passengerCount);
}
