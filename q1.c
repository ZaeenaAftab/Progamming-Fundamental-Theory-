
#include <stdio.h>

int main()
{
    int rows, seats;

    // 1. Input seating plan
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of seats per row: ");
    scanf("%d", &seats);

    int cinema[rows][seats];

    printf("\nEnter seating status (0 = Available, 1 = Booked):\n");

    for (int i = 0; i < rows; i++)
    {
        printf("Row %d:\n", i);

        for (int j = 0; j < seats; j++)
        {
            scanf("%d", &cinema[i][j]);
        }
    }

    // 2. Display seating arrangement
    printf("\n--- Seating Arrangement ---\n");

    printf("     ");
    for (int j = 0; j < seats; j++)
    {
        printf("%d ", j);
    }

    printf("\n");

    for (int i = 0; i < rows; i++)
    {
        printf("Row %d ", i);

        for (int j = 0; j < seats; j++)
        {
            if (cinema[i][j] == 0)
                printf("_ ");
            else
                printf("X ");
        }

        printf("\n");
    }

    // 3. Seat availability report
    int totalAvailable = 0;

    printf("\n--- Seat Availability Report ---\n");

    for (int i = 0; i < rows; i++)
    {
        int rowAvailable = 0;

        for (int j = 0; j < seats; j++)
        {
            if (cinema[i][j] == 0)
            {
                rowAvailable++;
            }
        }

        printf("Available seats in Row %d: %d\n", i, rowAvailable);

        totalAvailable += rowAvailable;
    }

    printf("Total available seats: %d\n", totalAvailable);

    // 4. Group booking
    int k;

    printf("\nEnter number of customers: ");
    scanf("%d", &k);

    if (k <= 0 || k > seats)
    {
        printf("Invalid group size!\n");
        return 0;
    }

    // 5. Search for consecutive seats
    int middle = rows / 2;
    int allocatedRow = -1;
    int startingSeat = -1;

    for (int distance = 0; distance < rows; distance++)
    {
        // Check lower row number first
        int row1 = middle - distance;

        if (row1 >= 0)
        {
            for (int j = 0; j <= seats - k; j++)
            {
                int count = 0;

                for (int x = j; x < j + k; x++)
                {
                    if (cinema[row1][x] == 0)
                    {
                        count++;
                    }
                }

                if (count == k)
                {
                    allocatedRow = row1;
                    startingSeat = j;
                    break;
                }
            }
        }

        if (allocatedRow != -1)
            break;

        // Check higher row number
        int row2 = middle + distance;

        if (distance != 0 && row2 < rows)
        {
            for (int j = 0; j <= seats - k; j++)
            {
                int count = 0;

                for (int x = j; x < j + k; x++)
                {
                    if (cinema[row2][x] == 0)
                    {
                        count++;
                    }
                }

                if (count == k)
                {
                    allocatedRow = row2;
                    startingSeat = j;
                    break;
                }
            }
        }

        if (allocatedRow != -1)
            break;
    }

    // 6. Confirm booking
    if (allocatedRow != -1)
    {
        printf("\nBooking Successful!\n");
        printf("Allocated Row: %d\n", allocatedRow);

        printf("Allocated Seats: ");

        for (int j = startingSeat; j < startingSeat + k; j++)
        {
            cinema[allocatedRow][j] = 1;
            printf("%d ", j);
        }

        printf("\n");

        // Display updated seating arrangement
        printf("\n--- Updated Seating Arrangement ---\n");

        printf("     ");
        for (int j = 0; j < seats; j++)
        {
            printf("%d ", j);
        }

        printf("\n");

        for (int i = 0; i < rows; i++)
        {
            printf("Row %d ", i);

            for (int j = 0; j < seats; j++)
            {
                if (cinema[i][j] == 0)
                    printf("_ ");
                else
                    printf("X ");
            }

            printf("\n");
        }

        // Calculate remaining available seats
        totalAvailable -= k;

        printf("\nRemaining available seats: %d\n", totalAvailable);
    }
    else
    {
        // 7. Unsuccessful booking
        printf("\nBooking Unsuccessful! No consecutive seats available.\n");
    }

    return 0;
}
