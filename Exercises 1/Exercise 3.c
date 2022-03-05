#include <stdio.h>
#include <stdlib.h>

typedef struct Complex_Number
{
    float real;
    float imaginary;
}Complex_Number;

Complex_Number ReadNumber()
{
    Complex_Number number;
    scanf("%f %f", &number.real, &number.imaginary);
    return number;
}

void PrintNumber(Complex_Number number)
{
    printf("%.2f%+.2fi",number.real, number.imaginary);
}

Complex_Number Sum(Complex_Number num_1, Complex_Number num_2)
{
    Complex_Number result;
    result.real = num_1.real + num_2.real;
    result.imaginary = num_1.real + num_2.imaginary;
    return result;
}

Complex_Number Difference(Complex_Number num_1, Complex_Number num_2)
{
    Complex_Number result;
    result.real = num_1.real - num_2.real;
    result.imaginary = num_1.real - num_2.imaginary;
    return result;
}

int main()
{
    printf("Enter complex number: ");
    Complex_Number number = ReadNumber();
    PrintNumber(number);

    return 0;
}
