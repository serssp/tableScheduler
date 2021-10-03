#include "db.h"

void config() {
    Subject *math = createSubject("Math");
    Subject *eng = createSubject("English");

    setAppointment(math, MONDAY, FRIDAY, LESSON1, LESSON4);
    setAppointment(eng, MONDAY, FRIDAY, LESSON1, LESSON4);

    Class *c10a = createClass("10A");

    require(math, c10a, 3);
    require(eng, c10a, 6);
}

