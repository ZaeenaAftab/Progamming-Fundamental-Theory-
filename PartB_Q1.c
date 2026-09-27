#include <stdio.h>
int main(){ 
    int i, guests, season, type, B_rate, days;
    float Total, Revenue;
    i = 1;
    Total = 0;
    Revenue = 0;
    

    printf("Enter total number of guests:  ");
    scanf("%d", &guests);

    while (i <= guests){

        i++;

        printf(" Enter 1 for Peak season else enter 0: ");
        scanf("%d", &season);
        printf("Enter 1 for Standard Room, else enter 2 for Deluxe room, else enter 3 for Suite: ");
        scanf("%d", &type);
        printf("Total days of stay? ");
        scanf("%d", &days );

        if (season == 1){
            if (type == 1){
                B_rate = 5000;
            }
            else if (type == 2){
                B_rate = 8000;
            }
            else{
                B_rate = 12000;
            }
        }
        else{
            if (type == 1){
                B_rate = 3000;
            }
            else if (type == 2){
                B_rate = 5000;
            }
            else{
                B_rate = 8000;
            }
        }

        Total = (B_rate * days);

        if (days >= 7){
            Total = Total - (Total * 15 / 100);
            printf("Your total is: %.2f Long Stay discount applied.\n", Total);
        }

        else{
            printf("Your total is: %.2f\n", Total);
        }

        Revenue = Revenue + Total;

    }
    printf("Hotel Revenue is: %.2f", Revenue);

}