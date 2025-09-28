#include <stdio.h>

#include "report_generation_module.c"
void loadCoursesFromFile() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp) {
        fscanf(fp, "%d\n", &courseCount);
        for (int i = 0; i < courseCount; i++) {
            fscanf(fp, "%9[^|]|%49[^|]|%49[^|]|%d|%d\n",
                   courses[i].courseID,
                   courses[i].name,
                   courses[i].instructor,
                   &courses[i].credits,
                   &courses[i].enrollmentCount);
        }
        fclose(fp);
    } else {
        perror("Error opening file for reading");
    }
}
void saveCoursesToFile() {
    FILE *fp = fopen(FILE_NAME, "w");
    if (fp) {
        fprintf(fp, "%d\n", courseCount);
        for (int i = 0; i < courseCount; i++) {
            fprintf(fp, "%s|%s|%s|%d|%d\n",
                    courses[i].courseID,
                    courses[i].name,
                    courses[i].instructor,
                    courses[i].credits,
                    courses[i].enrollmentCount);
        }
        fclose(fp);
    } else {
        perror("Error opening file for writing");
    }
}



void swap(struct Course *a, struct Course *b) {
    struct Course temp = *a;
    *a = *b;
    *b = temp;
}
