#include <stdio.h>
int main(){ 
    int currentfloor, requests, finalfloor,i;
    currentfloor = 0;
    i = 0;

    printf("Enter number of requests: ");
    scanf("%d", &requests);
    
    while (i < requests){
        i++;

        printf("Enter your required Floor: ");
        scanf("%d", &finalfloor);

        if (currentfloor < finalfloor)
        printf("Moving Up\n");
        else if (currentfloor > finalfloor)
        printf("Moving down\n");
        else
        printf("Doors Opening\n");

        currentfloor = finalfloor;

    }

}