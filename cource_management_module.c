#include <stdio.h>
#include "file_handling_module.c"
void addCourse() {
    if (courseCount >= MAX_COURSES) {
        printf("Course limit reached.\n");
        return;
    }

    struct Course c;
    printf("Enter Course ID: ");
    scanf("%s", c.courseID);
    getchar(); 
    
    int found1 = 0;
    for (int i = 0; i < courseCount; i++) {
        if (strstr(courses[i].courseID, c.courseID) || strstr(courses[i].instructor, c.courseID)) {
            displayCourse(courses[i]);
            found1 = 1;
        }
    }

    if (found1)
        {printf("\nWarning! course already exists '%s'\n", c.courseID);
        char ss[5] = {"(i)"};
        strcat(c.courseID,ss);}
    printf("Enter Course Name: ");
    fgets(c.name, 50, stdin);
    c.name[strcspn(c.name, "\n")] = '\0';
    int found = 0;
    for (int i = 0; i < courseCount; i++) {
        if (strstr(courses[i].name, c.name) || strstr(courses[i].instructor, c.name)) {
            displayCourse(courses[i]);
            found = 1;
        }
    }

    if (found)
        {printf("\nWarning! course already exists '%s'\n", c.name);
        char ss[5] = {"(i)"};
        strcat(c.name,ss);}    

    printf("Enter Instructor Name: ");
    fgets(c.instructor, 50, stdin);
    c.instructor[strcspn(c.instructor, "\n")] = '\0';
    printf("Enter Credits: ");
    scanf("%d", &c.credits);
    printf("Enter Enrollment Count: ");
    scanf("%d", &c.enrollmentCount);

    courses[courseCount++] = c;
    printf("Course added successfully!\n");
}

void searchCourse() {
    char keyword[50];
    int found = 0;
    printf("Enter Course Name or Instructor to search: ");
    getchar(); 
    fgets(keyword, 50, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    for (int i = 0; i < courseCount; i++) {
        if (strstr(courses[i].name, keyword) || strstr(courses[i].instructor, keyword)) {
            displayCourse(courses[i]);
            found = 1;
        }
    }

    if (!found)
        printf("No course found matching '%s'\n", keyword);
}

void sortCourses() {
    int option;
    printf("Sort by:\n1. Credits\n2. Alphabetical (Course Name)\nChoice: ");
    scanf("%d", &option);

    for (int i = 0; i < courseCount - 1; i++) {
        for (int j = 0; j < courseCount - i - 1; j++) {
            int cmp = 0;
            if (option == 1)
                cmp = courses[j].credits > courses[j + 1].credits;
            else
                cmp = strcmp(courses[j].name, courses[j + 1].name) > 0;

            if (cmp)
                swap(&courses[j], &courses[j + 1]);
        }
    }

    printf("Courses sorted successfully.\n");
    for (int i = 0; i < courseCount; i++) {
        displayCourse(courses[i]);
    }
}

void removeCourse() {
    char id[10];
    printf("Enter Course ID to remove: ");
    scanf("%s", id);

    int index = -1;
    for (int i = 0; i < courseCount; i++) {
        if (strcmp(courses[i].courseID, id) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Course not found.\n");
        return;
    }

    for (int i = index; i < courseCount - 1; i++) {
        courses[i] = courses[i + 1];
    }
    courseCount--;
    printf("Course removed successfully.\n");
}

