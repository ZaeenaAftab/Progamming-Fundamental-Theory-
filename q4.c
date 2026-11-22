
#include <stdio.h>

// Function 1: Get and validate festival days
int getValidDays()
{
    int days;

    do
    {
        printf("Enter number of festival days (1-7): ");
        scanf("%d", &days);

        if (days < 1 || days > 7)
        {
            printf("Invalid number of days! Try again.\n");
        }

    } while (days < 1 || days > 7);

    return days;
}


// Function 2: Calculate sales for one day
float calculateDailySales(int dayNumber)
{
    int orders;
    float amount;
    float total = 0;
    float highest = 0;

    printf("\n--- Day %d ---\n", dayNumber);

    printf("Enter number of orders: ");
    scanf("%d", &orders);

    for (int i = 1; i <= orders; i++)
    {
        printf("Enter amount for order %d: ", i);
        scanf("%f", &amount);

        // Validate order amount
        while (amount <= 0)
        {
            printf("Invalid amount! Enter again: ");
            scanf("%f", &amount);
        }

        total += amount;

        // Find highest order amount
        if (amount > highest)
        {
            highest = amount;
        }
    }

    float average = total / orders;

    printf("\nTotal Sales: Rs. %.2f\n", total);
    printf("Average Order Amount: Rs. %.2f\n", average);
    printf("Highest Order Amount: Rs. %.2f\n", highest);

    return total;
}


// Function 3: Find day with highest sales
int findHighestSalesDay(float dailySales[], int numberOfDays)
{
    int highestDay = 0;
    float highestSales = dailySales[0];

    for (int i = 1; i < numberOfDays; i++)
    {
        if (dailySales[i] > highestSales)
        {
            highestSales = dailySales[i];
            highestDay = i;
        }
    }

    return highestDay + 1;
}


// Function 4: Display daily sales bar chart
void displayBarChart(float dailySales[], int numberOfDays)
{
    printf("\n--- Daily Sales Bar Chart ---\n");

    for (int i = 0; i < numberOfDays; i++)
    {
        printf("Day %d: ", i + 1);

        int stars = dailySales[i] / 100;

        for (int j = 0; j < stars; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}


// Main function
int main()
{
    int days;
    float dailySales[7];
    float festivalTotal = 0;

    // Get valid festival duration
    days = getValidDays();

    // Process each festival day
    for (int i = 0; i < days; i++)
    {
        dailySales[i] = calculateDailySales(i + 1);

        festivalTotal += dailySales[i];
    }

    // Display festival summary
    printf("\n========== FESTIVAL SUMMARY ==========\n");

    printf("Total Festival Sales: Rs. %.2f\n", festivalTotal);

    int bestDay = findHighestSalesDay(dailySales, days);

    printf("Day with Highest Sales: Day %d\n", bestDay);

    // Display bar chart
    displayBarChart(dailySales, days);

    return 0;
}
