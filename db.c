#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "db.h"

// *******************  Subjects
Subject *subjects;

int countSubject();

void printHeader();

Subject *createSubject(char *name) {
    Subject *s = calloc(1, sizeof *s);
    strcpy(s->name, name);
    s->mask = 1 << countSubject();

    if (subjects == NULL) {
        subjects = s;
    } else {
        subjects->next = s;
    }

    return s;
}

int countSubject() {
    int c = 0;
    Subject *s = subjects;
    while (s != NULL) {
        s = s->next;
        c++;
    }
    return c;
}

// *******************  Classes
Class *classes;

Class *createClass(char *name) {
    Class *c = calloc(1, sizeof *c);
    strcpy(c->name, name);
    if (classes == NULL) {
        classes = c;
    } else {
        classes->next = c;
    }

    return c;
}


// ******************* Time Slots
int time_slots[DAYS_PER_WEEK][MAX_TIME_SLOTS];

void setAppointment(Subject *subject, int start_day, int end_day, int start_lesson, int end_lesson) {
    if (start_day > end_day || end_day >= DAYS_PER_WEEK || start_lesson > end_lesson || end_lesson >= MAX_TIME_SLOTS) {
        exit(1);
    }

    for (int day = start_day; day <= end_day; ++day) {
        for (int l = start_lesson; l <= end_lesson; ++l) {
            time_slots[day][l] |= subject->mask;
        }
    }
}

struct Require *requires;

void require(Subject *subject, Class *class, int number) {
    Require *r = malloc(sizeof *r);
    r->subject = subject;
    r->class = class;
    r->number = number;
    r->next = NULL;
    if (requires == NULL) {
        requires = r;
    } else {
        requires->next = r;
    }
}

// ******************* Table
void print() {
    Class *class = classes;
    while (class != NULL) {
        printf("Table schedule for: %s\n", class->name);
        printHeader();
        for (int lesson = 0; lesson < MAX_TIME_SLOTS; ++lesson) {
            printf("|");
            for (int day = 0; day < DAYS_PER_WEEK; ++day) {
                Subject *s = class->table[day][lesson];
                char *c = s == NULL ? " " : s->name;
                printf(" %-9s|", c);
            }
            printf("\n");
        }

        class = class->next;
    }
}

void printHeader() {
    char days[][20] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for (int i = 0; i < DAYS_PER_WEEK * 11 + 1; ++i) {
        printf("-");
    }
    printf("\n|");
    for (int i = 0; i < DAYS_PER_WEEK; i++) {
        printf(" %-9s|", days[i]);
    }
    printf("\n");
    for (int i = 0; i < DAYS_PER_WEEK * 11 + 1; ++i) {
        printf("-");
    }
    printf("\n");
}
