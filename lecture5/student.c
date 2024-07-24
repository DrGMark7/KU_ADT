#include <stdio.h>
#include <math.h>
typedef struct student {
    char name[20];
    int score;
} student_t;

void inputStudent(student_t students[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s %d", students[i].name, &students[i].score);
    }
}


void showStudentGrade(student_t students[], int n) {

    //. Calculate By mean and standard deviation
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].score;
    }
    double mean = (double)sum / n;
    double sum_of_square = 0;
    for (int i = 0; i < n; i++) {
        sum_of_square += pow(students[i].score - mean, 2);
    }
    double standard_deviation = sqrt(sum_of_square / n);
    
    for (int i = 0; i < n; i++) {
        if (students[i].score >= mean + 1.5*standard_deviation) {
            printf("%s A\n", students[i].name);
        } else if (mean + 1.5* standard_deviation > students[i].score && students[i].score  >= mean + standard_deviation) {
            printf("%s B\n", students[i].name);
        } else if (mean + standard_deviation > students[i].score && students[i].score  >= mean - standard_deviation) {
            printf("%s C\n", students[i].name);
        } else if (mean - standard_deviation > students[i].score && students[i].score  >= mean - 1.5*standard_deviation) {
            printf("%s D\n", students[i].name);
        } else {
            printf("%s F\n", students[i].name);
        }
    }
}

int main(void) {
    student_t students[1000];
    int n;
    scanf("%d", &n);
    inputStudent(students, n);
    showStudentGrade(students, n);
    return 0;
}