#include <stdio.h>
int main(){
    int num1, num2, answer;

    num1 = num2 = 1;
    while (num1 <= 10){
        if ((num1 % 3) != 0){
            while (num2 <= 10){
                answer = num1 * num2;
                printf("%d * %d = %d\n", num1, num2, answer);
                num2++;
            }
        }
        num1++;
        num2 = 1;
    }
}