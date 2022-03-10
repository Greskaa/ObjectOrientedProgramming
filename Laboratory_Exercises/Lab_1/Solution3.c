#include <stdio.h>
#include <stdlib.h>

struct Products
{
    char name[100];
    float price;
    int quantity;
};

typedef struct Products products;

int main()
{
    //number of products
    int n;
    scanf("%d", &n);
    products p[n];
    float total = 0;
    for (int i=0; i<n; i++)
    {
        scanf("%s %f %d", p[i].name, &p[i].price, &p[i].quantity);
        float result = p[i].price * p[i].quantity;
        total = total + result;
        printf("%d. %s\t%.2f x %d = %.2f\n", i+1, p[i].name, p[i].price, p[i].quantity, result);
    }
    
    printf("Total: %.2f", total);

    return 0;
}
