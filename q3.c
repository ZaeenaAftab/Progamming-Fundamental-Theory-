
#include <stdio.h>

// Function 1: Input temperature readings
void inputReadings(int sensors, int hours, float temp[sensors][hours])
{
    for (int i = 0; i < sensors; i++)
    {
        printf("\nEnter readings for Sensor %d:\n", i);

        for (int j = 0; j < hours; j++)
        {
            printf("Hour %d: ", j);
            scanf("%f", &temp[i][j]);
        }
    }
}


// Function 2: Analyze readings of one sensor
void analyzeSensor(int hours, float readings[])
{
    float total = 0;
    float highest = readings[0];
    float lowest = readings[0];

    int critical = 0;
    int warning = 0;

    int streak = 0;
    int longestStreak = 0;

    for (int i = 0; i < hours; i++)
    {
        total += readings[i];

        // Find highest temperature
        if (readings[i] > highest)
        {
            highest = readings[i];
        }

        // Find lowest temperature
        if (readings[i] < lowest)
        {
            lowest = readings[i];
        }

        // Count critical readings
        if (readings[i] >= 40)
        {
            critical++;
        }

        // Count warning readings
        if (readings[i] >= 35 && readings[i] <= 39)
        {
            warning++;
        }

        // Find consecutive streak
        if (readings[i] >= 35)
        {
            streak++;

            if (streak > longestStreak)
            {
                longestStreak = streak;
            }
        }
        else
        {
            streak = 0;
        }
    }

    float average = total / hours;

    // Display report
    printf("\nTotal Temperature: %.2f", total);
    printf("\nAverage Temperature: %.2f", average);
    printf("\nHighest Temperature: %.2f", highest);
    printf("\nLowest Temperature: %.2f", lowest);
    printf("\nCritical Readings: %d", critical);
    printf("\nWarning Readings: %d", warning);
    printf("\nLongest Streak: %d hours\n", longestStreak);
}


// Function 3: Find sensor with highest average
int highestAverage(int sensors, int hours, float temp[sensors][hours])
{
    int highestSensor = 0;
    float highestAvg = 0;

    for (int i = 0; i < sensors; i++)
    {
        float total = 0;

        for (int j = 0; j < hours; j++)
        {
            total += temp[i][j];
        }

        float avg = total / hours;

        if (avg > highestAvg)
        {
            highestAvg = avg;
            highestSensor = i;
        }
    }

    return highestSensor;
}


// Main function
int main()
{
    int sensors, hours;

    printf("Enter number of sensors: ");
    scanf("%d", &sensors);

    printf("Enter number of hourly readings: ");
    scanf("%d", &hours);

    float temp[sensors][hours];

    // Input readings
    inputReadings(sensors, hours, temp);

    // Individual sensor reports
    for (int i = 0; i < sensors; i++)
    {
        printf("\n========== SENSOR %d REPORT ==========\n", i);

        analyzeSensor(hours, temp[i]);
    }

    // Find sensor with highest average
    int bestSensor = highestAverage(sensors, hours, temp);

    // Calculate its average
    float total = 0;

    for (int j = 0; j < hours; j++)
    {
        total += temp[bestSensor][j];
    }

    float avg = total / hours;

    // Final report
    printf("\n========== FINAL REPORT ==========\n");
    printf("Sensor with highest average: %d\n", bestSensor);
    printf("Highest average temperature: %.2f\n", avg);

    return 0;
}
