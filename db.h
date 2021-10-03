#ifndef TS2_DB_H
#define TS2_DB_H

#define DAYS_PER_WEEK 6 // Кол. учебных дней в неделе
#define MAX_TIME_SLOTS 10 // Макс. количество уроков

#define MONDAY 0
#define TUESDAY 1
#define WEDNESDAY 2
#define THURSDAY 3
#define FRIDAY 4
#define SATURDAY 5

#define LESSON1 0
#define LESSON2 1
#define LESSON3 2
#define LESSON4 3
#define LESSON5 4
#define LESSON6 5
#define LESSON7 6

// *******************  Subjects
typedef struct Subject Subject;
struct Subject {
    char name[20];
    int mask;
    Subject *next;
};
extern Subject *subjects;

Subject *createSubject(char *name);

// *******************  Classes
typedef struct Class Class;
struct Class {
    char name[20];
    Subject *table[DAYS_PER_WEEK][MAX_TIME_SLOTS];
    Class *next;
};
extern Class *classes;

Class *createClass(char *name);

// *******************  Require
typedef struct Require Require;
struct Require {
    Class *class;
    Subject *subject;
    int number;

    Require *next;
};
extern struct Require *requires;

void require(Subject *math, Class *a, int number);

// ****************** Time Slots
extern int time_slots[DAYS_PER_WEEK][MAX_TIME_SLOTS];

void setAppointment(Subject *subject, int start_day, int end_day, int start_lesson, int end_lesson);

void print();

#endif //TS2_DB_H
