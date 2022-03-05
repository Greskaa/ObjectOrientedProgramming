#include <stdio.h>
#include <stdlib.h>

typedef struct Vector
{
    float x;
    float y;
    float z;
};

typedef struct Vector vector;

float scalar_product(vector *v1, vector *v2)
{
    return v1->x*v2->x + v1->y*v2->y + v1->z*v2->z;
}

void ReadVector(vector *v)
{
    scanf("%f %f %f", &v->x, &v->y, &v->z);
}

void PrintVector(vector v)
{
    printf("%.2f, %.2f, %.2f\n", v.x, v.y, v.z);
}


int main()
{
    vector v1;
    vector v2;
    printf ("Enter first vector: ");
    ReadVector(&v1);
    printf ("Enter second vector: ");
    ReadVector(&v2);

    PrintVector(v1);
    PrintVector(v2);

    int s = scalar_product(&v1, &v2);
    printf("\n");
    printf("Scalar Product of the vectors is: %.2f", scalar_product(&v1, &v2));


    return 0;
}
