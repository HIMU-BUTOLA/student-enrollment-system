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


