#include <stdio.h>
int main(){ 
    char vehicle, membership, disabled, station;
    int battery, requiredLevel, parkingHours, time;
    int requiredCharging;

    float chargingCost = 0;
    float parkingCost = 0;
    float chargingDiscount = 0;
    float parkingDiscount = 0;
    float totalDiscount = 0;
    float finalAmount = 0;

    printf("Enter vehicle type (E = Electric, H = Hybrid): ");
    scanf(" %c", &vehicle);

    printf("Enter current battery level (%%): ");
    scanf("%d", &battery);

    printf("Enter required charging level (%%): ");
    scanf("%d", &requiredLevel);

    printf("Enter parking duration (hours): ");
    scanf("%d", &parkingHours);

    printf("Enter current time (0-23): ");
    scanf("%d", &time);

    printf("Parking membership? (Y/N): ");
    scanf(" %c", &membership);

    printf("Disabled-person priority? (Y/N): ");
    scanf(" %c", &disabled);

    printf("Charging station available? (Y/N): ");
    scanf(" %c", &station);

    if (station == 'N' || station == 'n') {

        if (vehicle == 'H' || vehicle == 'h') {
            printf("\nCharging unavailable - Parking only.\n");
        }
        else {
            printf("\nNo charging slot available.\n");
        }

        return 0;
    }

    if (vehicle == 'H' || vehicle == 'h') {

        if (battery >= 40) {
            printf("\nVehicle does not qualify for EV charging.\n");
            return 0;
        }
    }

    if (requiredLevel <= battery) {

        printf("\nNo charging required.\n");
        return 0;
    }

    requiredCharging = requiredLevel - battery;


    printf("\nCharging Priority: ");

    if (battery <= 15 && requiredLevel >= 80) {

        printf("Emergency Charging Priority\n");
    }
    else if (disabled == 'Y' ||
             (membership == 'Y' && battery <= 30)) {

        printf("Priority Charging\n");
    }
    else {

        printf("Normal Charging\n");
    }

    if (time < 17 || time > 22) {

        printf("Time Status: Off-Peak\n");

        chargingCost = requiredCharging * 35;

        if (membership == 'Y' &&
            !(battery <= 15 && requiredLevel >= 80)) {

            chargingDiscount = chargingCost * 0.20;
            chargingCost = chargingCost - chargingDiscount;
        }
    }
    else {

        printf("Time Status: Peak\n");

        chargingCost = requiredCharging * 50;

        chargingDiscount = chargingCost * 0.10;
        chargingCost = chargingCost - chargingDiscount;
    }

    if (parkingHours <= 2) {

        parkingCost = 200;
    }
    else if (parkingHours <= 5) {

        parkingCost = 400;
    }
    else {

        parkingCost = 700;
    }

    if (disabled == 'Y') {

        parkingDiscount = parkingCost;
        parkingCost = 0;
    }
    else if (membership == 'Y') {

        parkingDiscount = parkingCost * 0.20;
        parkingCost = parkingCost - parkingDiscount;
    }

    totalDiscount = chargingDiscount + parkingDiscount;

    finalAmount = chargingCost + parkingCost;

    printf("Vehicle Type: ");

    if (vehicle == 'E' || vehicle == 'e')
        printf("Electric Vehicle\n");
    else
        printf("Hybrid Vehicle\n");

    printf("Current Battery: %d%%\n", battery);
    printf("Required Charging Level: %d%%\n", requiredLevel);
    printf("Charging Required: %d%%\n", requiredCharging);

    printf("Charging Cost: Rs. %.2f\n", chargingCost);
    printf("Parking Cost: Rs. %.2f\n", parkingCost);

    printf("Total Discount: Rs. %.2f\n", totalDiscount);

    printf("Final Payable Amount: Rs. %.2f\n", finalAmount);

    if (parkingHours > 8) {

        printf("Warning: Long-stay warning: Please relocate your vehicle after charging.\n");
    }
    else {

        printf("Standard parking duration.\n");
    }
}