
#include "extras.h"
#include <stdio.h>
void displayCourse(struct Course c) {
    printf("\n-----------------------------\n");
    printf("Course ID       : %s\n", c.courseID);
    printf("Course Name     : %s\n", c.name);
    printf("Instructor      : %s\n", c.instructor);
    printf("Credits         : %d\n", c.credits);
    printf("Enrollments     : %d\n", c.enrollmentCount);
}

void generateReport() {
    if (courseCount == 0) {
        printf("No courses available to display.\n");
        return;
    }

    int totalEnrollments = 0;

    printf("\n======= Course Report =======\n");
    for (int i = 0; i < courseCount; i++) {
        displayCourse(courses[i]);
        totalEnrollments += courses[i].enrollmentCount;
    }

    printf("\n========== Summary ==========\n");
    printf("Total Courses Offered   : %d\n", courseCount);
    printf("Total Student Enrollments: %d\n", totalEnrollments);
    printf("==============================\n");
}

