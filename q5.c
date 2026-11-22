
#include <stdio.h>
#include <string.h>

// 1. Display menu
void displayMenu()
{
    printf("\n========== LIBRARY MENU ==========\n");
    printf("1. Register Member\n");
    printf("2. Display Available Books\n");
    printf("3. Borrow a Book\n");
    printf("4. Return a Book\n");
    printf("5. Display Member Record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}


// 2. Register member
void registerMember(char name[], int *studentID, int *memberType)
{
    printf("\nEnter member name: ");
    scanf(" %49[^\n]", name);

    printf("Enter student ID: ");
    scanf("%d", studentID);

    do
    {
        printf("Enter membership type (1 = Student, 2 = Faculty): ");
        scanf("%d", memberType);

        if (*memberType != 1 && *memberType != 2)
        {
            printf("Invalid membership type! Try again.\n");
        }

    } while (*memberType != 1 && *memberType != 2);

    printf("\nRegistration successful!\n");
}


// 3. Display available books
void displayBooks(int bookIDs[], char bookTitles[][50],
                  int availableCopies[], int totalBooks)
{
    printf("\n========== AVAILABLE BOOKS ==========\n");

    printf("%-10s %-25s %-10s\n", "Book ID", "Title", "Copies");

    for (int i = 0; i < totalBooks; i++)
    {
        printf("%-10d %-25s %-10d\n",
               bookIDs[i], bookTitles[i], availableCopies[i]);
    }
}


// 4. Borrow a book
void borrowBook(int bookIDs[], char bookTitles[][50],
                int availableCopies[], int totalBooks,
                int borrowedBookIDs[], int *borrowedCount,
                int memberType)
{
    int id, days;
    int found = -1;

    if (*borrowedCount >= 3)
    {
        printf("\nYou cannot borrow more than 3 books!\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &id);

    printf("Enter intended borrowing days: ");
    scanf("%d", &days);

    while (days <= 0)
    {
        printf("Days must be greater than zero. Enter again: ");
        scanf("%d", &days);
    }

    // Check borrowing period
    int allowedDays;

    if (memberType == 1)
        allowedDays = 14;
    else
        allowedDays = 30;

    if (days > allowedDays)
    {
        printf("You can only keep this book for %d days.\n", allowedDays);
        return;
    }

    // Search for book ID
    for (int i = 0; i < totalBooks; i++)
    {
        if (bookIDs[i] == id)
        {
            found = i;
            break;
        }
    }

    // Check whether book exists
    if (found == -1)
    {
        printf("Invalid Book ID!\n");
        return;
    }

    // Check book availability
    if (availableCopies[found] <= 0)
    {
        printf("This book is currently unavailable!\n");
        return;
    }

    // Check if member already borrowed this book
    for (int i = 0; i < *borrowedCount; i++)
    {
        if (borrowedBookIDs[i] == id)
        {
            printf("You have already borrowed this book!\n");
            return;
        }
    }

    // Record successful borrowing
    borrowedBookIDs[*borrowedCount] = id;
    (*borrowedCount)++;

    availableCopies[found]--;

    printf("\nBook borrowed successfully: %s\n", bookTitles[found]);
}


// 5. Return a book
float returnBook(int bookIDs[], int availableCopies[],
                 int totalBooks, int borrowedBookIDs[],
                 int *borrowedCount, int memberType,
                 float *totalFine)
{
    int id, actualDays;
    int bookIndex = -1;
    int borrowedIndex = -1;

    float fine = 0;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    printf("Enter actual number of days kept: ");
    scanf("%d", &actualDays);

    while (actualDays <= 0)
    {
        printf("Days must be greater than zero. Enter again: ");
        scanf("%d", &actualDays);
    }

    // Check whether member borrowed this book
    for (int i = 0; i < *borrowedCount; i++)
    {
        if (borrowedBookIDs[i] == id)
        {
            borrowedIndex = i;
            break;
        }
    }

    if (borrowedIndex == -1)
    {
        printf("You have not borrowed this book!\n");
        return 0;
    }

    // Find book in inventory
    for (int i = 0; i < totalBooks; i++)
    {
        if (bookIDs[i] == id)
        {
            bookIndex = i;
            break;
        }
    }

    // Calculate permitted days and fine rate
    int allowedDays;
    int rate;

    if (memberType == 1)
    {
        allowedDays = 14;
        rate = 20;
    }
    else
    {
        allowedDays = 30;
        rate = 10;
    }

    // Calculate late fine
    if (actualDays > allowedDays)
    {
        int extraDays = actualDays - allowedDays;

        fine = extraDays * rate;

        printf("Late fine before waiver: Rs. %.2f\n", fine);

        char code[20];

        printf("Enter membership code for 50%% waiver (or enter - to skip): ");
        scanf("%19s", code);

        if (strcmp(code, "LIB2026") == 0)
        {
            fine = fine * 0.5;

            printf("50%% waiver applied!\n");
        }
        else
        {
            printf("Incorrect code. No waiver applied.\n");
        }
    }

    // Update cumulative fine before waiver
    if (actualDays > allowedDays)
    {
        int extraDays = actualDays - allowedDays;
        *totalFine += extraDays * rate;
    }

    // Increase available copies
    availableCopies[bookIndex]++;

    // Remove book from borrowing array
    for (int i = borrowedIndex; i < *borrowedCount - 1; i++)
    {
        borrowedBookIDs[i] = borrowedBookIDs[i + 1];
    }

    (*borrowedCount)--;

    printf("\nBook returned successfully!\n");
    printf("Fine payable for this return: Rs. %.2f\n", fine);

    return fine;
}


// 6. Display member record
void displayMemberRecord(char name[], int studentID,
                         int memberType, int borrowedBookIDs[],
                         int borrowedCount, float totalFine,
                         float fineAfterWaiver)
{
    printf("\n========== MEMBER RECORD ==========\n");

    printf("Name: %s\n", name);
    printf("Student ID: %d\n", studentID);

    if (memberType == 1)
        printf("Membership Type: Student\n");
    else
        printf("Membership Type: Faculty\n");

    printf("Currently Borrowed Books: ");

    if (borrowedCount == 0)
    {
        printf("None");
    }
    else
    {
        for (int i = 0; i < borrowedCount; i++)
        {
            printf("%d ", borrowedBookIDs[i]);
        }
    }

    printf("\nTotal Fine Before Waiver: Rs. %.2f\n", totalFine);
    printf("Final Fine Payable: Rs. %.2f\n", fineAfterWaiver);
}


// MAIN FUNCTION
int main()
{
    int bookIDs[4] = {101, 102, 103, 104};

    char bookTitles[4][50] = {
        "Programming in C",
        "Data Structures",
        "Database Systems",
        "Computer Networks"
    };

    int availableCopies[4] = {5, 3, 0, 4};

    char name[50] = "";
    int studentID = 0;
    int memberType = 0;

    int borrowedBookIDs[3];
    int borrowedCount = 0;

    float totalFine = 0;
    float fineAfterWaiver = 0;

    int choice;
    int registered = 0;

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                if (registered == 0)
                {
                    registerMember(name, &studentID, &memberType);
                    registered = 1;
                }
                else
                {
                    printf("Member already registered!\n");
                }

                break;


            case 2:

                displayBooks(bookIDs, bookTitles,
                             availableCopies, 4);

                break;


            case 3:

                if (registered == 1)
                {
                    borrowBook(bookIDs, bookTitles,
                               availableCopies, 4,
                               borrowedBookIDs, &borrowedCount,
                               memberType);
                }
                else
                {
                    printf("Please register first!\n");
                }

                break;


            case 4:

                if (registered == 1)
                {
                    fineAfterWaiver += returnBook(
                        bookIDs, availableCopies, 4,
                        borrowedBookIDs, &borrowedCount,
                        memberType, &totalFine
                    );
                }
                else
                {
                    printf("Please register first!\n");
                }

                break;


            case 5:

                if (registered == 1)
                {
                    displayMemberRecord(
                        name, studentID, memberType,
                        borrowedBookIDs, borrowedCount,
                        totalFine, fineAfterWaiver
                    );
                }
                else
                {
                    printf("No member registered!\n");
                }

                break;


            case 6:

                printf("Exiting Library System...\n");
                break;


            default:

                printf("Invalid menu choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
