#include <stdio.h>
int main(){
    int number, digit, sum;
    sum = 10;
    digit = 1;

    printf("Enter a number: ");
    scanf("%d", &number);

    while ((sum / 10) != 0){
        sum = 0;
        while (digit != 0){
            digit = number % 10;
            number = number / 10;
            sum = sum + digit;
        }
        number = sum;
        digit = 1;
        printf("Sum of digits is: %d\n", sum);
    }
}