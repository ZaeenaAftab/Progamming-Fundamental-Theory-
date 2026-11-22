
#include <stdio.h>

// Function to calculate sum of proper divisors
int sumDivisors(int num)
{
    int sum = 0;

    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }

    return sum;
}

int main()
{
    int n, count = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("\nAmicable pairs:\n");

    for (int a = 2; a <= n; a++)
    {
        int b = sumDivisors(a);

        // Check that the numbers are different
        // and the second number is within the limit
        if (b > a && b <= n)
        {
            if (sumDivisors(b) == a)
            {
                printf("(%d, %d)\n", a, b);
                count++;
            }
        }
    }

    if (count == 0)
    {
        printf("No amicable pairs found.\n");
    }
    else
    {
        printf("Total amicable pairs found: %d\n", count);
    }

    return 0;
}
