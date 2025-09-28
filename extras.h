#define MAX_COURSES 100
#define FILE_NAME "courses.txt"
struct Course {
    char courseID[10];
    char name[50];
    char instructor[50];
    int credits;
    int enrollmentCount;
};

struct Course courses[MAX_COURSES];
int courseCount = 0;
