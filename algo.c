#include <stddef.h>
#include <stdlib.h>
#include "db.h"

void fill(Require *require);

void resolve() {
    Require *r = requires;
    while (r != NULL) {
        fill(r);
        r = r->next;
    }
}

void fill(Require *require) {
    int subjectsNumber = require->number;
    int iter = 0;
    while (subjectsNumber > 0 || iter < 10) {
        int day = rand() % DAYS_PER_WEEK;
        int lesson = rand() % MAX_TIME_SLOTS;
        if (time_slots[day][lesson] & require->subject->mask) {
            time_slots[day][lesson] &= !require->subject->mask;
            require->class->table[day][lesson] = require->subject;
            subjectsNumber--;
        }
        iter++;
    }
}

int calcFit() {
   return 1;
}
