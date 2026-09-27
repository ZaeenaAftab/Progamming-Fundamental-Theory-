#include <stdio.h>
int main(){ 
    int quantity;
    float price, discount, tax;
    float s, a, total;

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter price per item: ");
    scanf("%f", &price);

    printf("Enter discount percentage: ");
    scanf("%f", &discount);

    printf("Enter tax percentage: ");
    scanf("%f", &tax);

    if (quantity <= 0) {
        printf("Error: Invalid quantity.\n");
        return 0;
    }
    if (price < 0) {
        printf("Error: Invalid price.\n");
        return 0;
    }
    if (discount < 0 || discount > 100) {
        printf("Error: Invalid discount.\n");
        return 0;
    }
    if (tax < 0) {
        printf("Error: Invalid tax.\n");
        return 0;
    }

    s = quantity*price;
    a = s - (s * discount / 100);
    total = a + (a * tax / 100);

    printf("BILL\n");
    printf("Quantity: %d\n", quantity);
    printf("Price per item: Rs. %.2f\n", price);
    printf("Subtotal: Rs. %.2f\n", s);
    printf("After discount: Rs. %.2f\n", a);
    printf("Tax: %.2f%%\n", tax);
    printf("Final Bill: Rs. %.2f\n", total);
}