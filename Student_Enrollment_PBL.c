/*Problem Statement 53: Course Enrollment System  
Develop a C program for a Course Enrollment System to manage student enrollments and 
course records efficiently. The system should include admin authentication to ensure secure 
access for managing courses and enrollments. Key functionalities include adding course details 
(course ID, name, instructor, credits), searching for courses by name or instructor, and sorting 
courses by credits or alphabetical order. Additionally, it should allow removal of discontinued 
courses and provide report generation on total courses offered and student enrollments. File 
handling should be used to store and retrieve course records for data persistence. */
#include <stdio.h>
#include <string.h>
#include "user_authentication_module.c"
#include <stdlib.h>

struct Course courses[MAX_COURSES];

int main() {
    int choice;

    if (!auth(1)) {
        printf("Authentication Failed. Exiting...\n");
        return 1;
    }

    loadCoursesFromFile();

    do {
        printf("\n--- Course Enrollment System ---\n");
        printf("1. Add Course\n");
        printf("2. Search Course\n");
        printf("3. Sort Courses\n");
        printf("4. Remove Course\n");
        printf("5. Generate Report\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1: addCourse(); break;
            case 2: searchCourse(); break;
            case 3: sortCourses(); break;
            case 4: removeCourse(); break;
            case 5: generateReport(); break;
            case 6: saveCoursesToFile(); printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

