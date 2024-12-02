
#ifndef LIST_H
#define LIST_H

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// Definitions
#define INIT_CAPACITY 10
#define BUFFER_SIZE 255
#define DAYSINWEEK 7
#define BUSY 1
#define FREE 0

//  TYPEDEFS
typedef enum DayOfWeek {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
} DayOfWeek;

typedef struct {
    char name[BUFFER_SIZE];
    unsigned int schedule;
} Person;

typedef struct {
    Person* list;
    unsigned int length;
    unsigned int capacity;
} People;

// Function Prootypes
// PROBLEM 3
People list_init();
void list_destroy(People* people);
void list_read(const char* file, People* people);
void list_add(People* people, char* name, char* schedule);
void list_print_machine(People* people);


// PROBLEM 4
// Pretty Prints
void list_print_tabular(People* people);
void list_print_human(People* people);

// Queries
void whosFreeOn(DayOfWeek day, People* people);
void mutuallyFree(People* people);

// Modifying the list
void clearDay(const char* name, DayOfWeek day, People* people);
void fillDay(const char* name, DayOfWeek day, People* people);


// Static Data
extern const char* dayNames[];
extern const char* dayAbbvs[];


#endif /* LIST_H */

