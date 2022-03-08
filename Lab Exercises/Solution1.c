#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//Create structure that accepts 3 points in 3D coordinate
struct point3D
{
    float x, y, z;
};
typedef struct point3D point3D;

//Create structure that accepts 2 points in 2D coordinate
struct point2D
{
    float x, y;
};
typedef struct point2D point2D;


float distance(point2D coordinate_1, point2D coordinate_2)
{
    //formula for 2D Distance = sqrt((y2-y1)^2 + (x2-x1)^2)
    return sqrt(pow(coordinate_1.x-coordinate_2.x, 2) + pow(coordinate_1.y-coordinate_2.y, 2));
}

float distance3D(point3D coordinate_1, point3D coordinate_2)
{
    //formula for 2D Distance = sqrt((z2-z1)^2 + (y2-y1)^2 + (x2-x1)^2))
    return sqrt(pow(coordinate_1.x-coordinate_2.x, 2) + pow(coordinate_1.y-coordinate_2.y, 2) + pow(coordinate_1.z-coordinate_2.z, 2));
}

//Check if points are collinear (lay on the same line)
bool collinear(point2D coordinate_1, point2D coordinate_2, point2D coordinate_3)
{
    float slope_1and2 = (coordinate_1.y - coordinate_2.y)/(coordinate_1.x - coordinate_2.x);
    float slope_1and3 = (coordinate_1.y - coordinate_3.y)/(coordinate_1.x - coordinate_3.x);

    if(slope_1and2 == slope_1and3)
        return 1;
        
    return 0;
}

int main() {
    float x1, y1, x2, y2;
    scanf("%f %f", &x1, &y1);
	scanf("%f %f", &x2, &y2);
	point2D t1 = { x1, y1 };
	point2D t2 = { x2, y2 };
	printf("%.2f\n", distance(t1, t2));
    float z1, z2;
    scanf("%f %f", &z1, &z2);
    point3D t3 = {x1, y1, z1};
    point3D t4 = {x2, y2, z2};
    printf("%.2f\n", distance3D(t3, t4));
    point2D t5 = {z1, z2};
    printf("%d\n", collinear(t1, t2, t5));
	return 0;
}
