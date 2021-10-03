#include <stdlib.h>
#include <time.h>
#include "db.h"

void config();

void resolve();

int calcFit();

int main() {
    time_t t;
    srand((unsigned) time(&t));

    config();

    do {
        resolve();
    } while (calcFit() > 1000);

    print();

    return 0;
}
