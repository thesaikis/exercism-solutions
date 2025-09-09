#include "grade_school.h"

#include <stdlib.h>
#include <string.h>

void init_roster(roster_t *roster) {
    roster->count = 0;
}

bool add_student(roster_t* roster, const char name[], int grade) {
    if (roster->count >= MAX_STUDENTS) return false;
    if (strlen(name) > MAX_NAME_LENGTH) return false;

    // Check if student with the same name already exists
    for (size_t i = 0; i < roster->count; i++) {
        if (strncmp(name, roster->students[i].name, MAX_NAME_LENGTH) == 0) {
            return false;
        }
    }

    student_t new_student;
    new_student.grade = (uint8_t)grade;
    strncpy(new_student.name, name, MAX_NAME_LENGTH);

    // Increment insertion index until correct insertion point is found
    size_t insertion_point = 0;
    while (insertion_point < roster->count &&
           (new_student.grade > roster->students[insertion_point].grade ||
            (new_student.grade == roster->students[insertion_point].grade &&
             strncmp(new_student.name, roster->students[insertion_point].name, MAX_NAME_LENGTH) > 0))) {
        insertion_point++;
    }

    // Shift the students after the insertion point one space to the right
    for (size_t i = roster->count; i > insertion_point; i--) {
        roster->students[i] = roster->students[i - 1];
    }

    // Insert the new student at the insertion point
    roster->students[insertion_point] = new_student;
    roster->count++;

    return true;
}

roster_t get_grade(roster_t *roster, int grade) {
    roster_t grade_roster;
    init_roster(&grade_roster);

    // Check each student in the roster to check if they are in the grade
    for (size_t i = 0; i < roster->count; i++) {
        if (roster->students[i].grade == (uint8_t)grade) {
            grade_roster.students[grade_roster.count] = roster->students[i];
            grade_roster.count++;
        }
    }

    return grade_roster;
}