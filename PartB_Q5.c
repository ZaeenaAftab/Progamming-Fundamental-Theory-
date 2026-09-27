#include <stdio.h>
int main(){ 
    char vehicle, category, permit, emergency, assignedZone;
    int N,spacesNeeded;
    int i = 0;
    int parked = 0;


    int zoneA = 0;
    int zoneB = 0;
    int zoneC = 0;

    int accepted = 0;
    int rejected = 0;

    int cars = 0;
    int bikes = 0;
    int vans = 0;


    printf("Enter number of vehicles: ");
    scanf("%d", &N);

    while (i < N){
        i++;

        printf("Vehicle type (C/B/V): ");
        scanf(" %c", &vehicle);
        while ((vehicle != 'C') && (vehicle != 'B') &&(vehicle != 'V')){
            printf("Invalid Vehicle type Enter from one of the following options (C/B/V): ");
            scanf(" %c", &vehicle);
        } 

        printf("Category (F/S/G): ");
        scanf(" %c", &category);
        while ((category != 'F') && (category != 'S') && (category != 'G')){
            printf("Invalid Category Enter from one of the following options (F/S/G): ");
            scanf(" %c", &category);
        } 

        printf("Valid permit? (Y/N): ");
        scanf(" %c", &permit);
        while ((permit != 'Y') && (permit != 'N'))
        {
            printf("Invalid Answer either answer Y for Yes or N for No: ");
            scanf("%c", &permit);
        }
        

        if (permit == 'N') {
            printf("Emergency vehicle? (Y/N): ");
            scanf(" %c", &emergency);
        }
        else {
            emergency = 'N';
        }

         if (vehicle == 'V') {
            spacesNeeded = 2;
        }
        else {
            spacesNeeded = 1;
        }

         if (emergency == 'Y') {

            if (category == 'F') {

                if (zoneA + spacesNeeded <= 20) {
                    zoneA += spacesNeeded;
                    assignedZone = 'A';
                    parked = 1;
                }
                else {
                    printf("Rejected: Zone A has no available space.\n");
                }

            }
            else if (category == 'S') {

                if (zoneB + spacesNeeded <= 40) {
                    zoneB += spacesNeeded;
                    assignedZone = 'B';
                    parked = 1;
                }
                else {
                    printf("Rejected: Zone B has no available space.\n");
                }

            }
            else if (category == 'G') {

                if (zoneC + spacesNeeded <= 15) {
                    zoneC += spacesNeeded;
                    assignedZone = 'C';
                    parked = 1;
                }
                else {
                    printf("Rejected: Zone C has no available space.\n");
                }
            }
        }


        

        else {

            if (permit == 'N') {

                printf("Rejected: Invalid permit.\n");

            }

            

            else if (category == 'F') {

                if (zoneA + spacesNeeded <= 20) {

                    zoneA += spacesNeeded;
                    assignedZone = 'A';
                    parked = 1;

                }
                else {

                    printf("Rejected: No space available in Zone A.\n");

                }
            }

            else if (category == 'S') {

                if (vehicle == 'V') {

                    if (zoneC + 2 <= 15) {

                        zoneC += 2;
                        assignedZone = 'C';
                        parked = 1;

                    }
                    else {

                        printf("Rejected: No space available in Zone C for student van.\n");

                    }
                }

                else {

                    if (zoneB + 1 <= 40) {

                        zoneB += 1;
                        assignedZone = 'B';
                        parked = 1;

                    }
                    else {

                        printf("Rejected: No space available in Zone B.\n");

                    }
                }
            }

            else if (category == 'G') {

                if (vehicle == 'V') {

                    if (zoneC + 2 <= 15) {

                        zoneC += 2;
                        assignedZone = 'C';
                        parked = 1;

                    }
                    else {

                        printf("Rejected: Visitor Zone C does not have two spaces available.\n");

                    }
                }

                else {

                    if (zoneC + 1 <= 15) {

                        zoneC += 1;
                        assignedZone = 'C';
                        parked = 1;

                    }
                    else {

                        printf("Rejected: No space available in Zone C.\n");

                    }
                }
            }
        }

        if (parked == 1) {

            accepted++;

            if (vehicle == 'C') {
                cars++;
            }
            else if (vehicle == 'B') {
                bikes++;
            }
            else {
                vans++;
            }

            printf("Vehicle accepted.\n");
            printf("Assigned Zone: %c\n", assignedZone);

            if (assignedZone == 'A') {
                printf("Remaining capacity in Zone A: %d\n", 20 - zoneA);
            }
            else if (assignedZone == 'B') {
                printf("Remaining capacity in Zone B: %d\n", 40 - zoneB);
            }
            else {
                printf("Remaining capacity in Zone C: %d\n", 15 - zoneC);
            }
        }
        else {
            rejected++;
        }
    }

    printf("PARKING SUMMARY");
    printf("Total vehicles processed: %d\n", N);
    printf("Accepted: %d\n", accepted);
    printf("Rejected: %d\n", rejected);
    printf("Cars parked: %d\n", cars);
    printf("Bikes parked: %d\n", bikes);
    printf("Vans parked: %d\n", vans);

    printf("Zone A occupied: %d / 20\n", zoneA);
    printf("Zone B occupied: %d / 40\n", zoneB);
    printf("Zone C occupied: %d / 15\n", zoneC);

}