#include <stdio.h>

struct Point{
    float x, y;
};


int main(){

    struct Point coordinates;

    printf("Enter Point X: ");
    scanf("%f", &coordinates.x);
    printf("Enter Point Y: ");
    scanf("%f", &coordinates.y);

    printf("Point X: %.2f\n", coordinates.x);
    printf("Point Y: %.2f\n", coordinates.y);


}