#include <stdio.h>
int main(){ 
    int students, subjects, inc1, marks, total;
    float avg;
    inc1 = marks = total = subjects = 0;

    printf("Enter total number of students: ");
    scanf("%d", &students);

    while (inc1 < students){
        inc1++;
        while (subjects < 5){
            subjects++;

            printf("Enter marks for Subject %d: ", subjects);
            scanf("%d", &marks);

            total += marks;
            if (marks < 33)
            break;
            
        }
        subjects = 0;
        if (marks < 33)
        printf("Fail - Subject Deficiency\n");
        else{
            avg = (total/5.0);
            printf("Your Average: %.2f\n", avg);

            if (avg >= 80)
            printf("Distinction\n");
            else if (avg >= 60)
            printf("Pass\n");
            else
            printf("Fail\n");
        }
        total = 0;
    }
}