#include <stdio.h>
#include <string.h>

struct Students{
    char name[50];
    float grade1;
    float grade2;
};

int main(){
    struct Students student1;

    strcpy(student1.name, "John");
    student1.grade1 = 9;
    student1.grade2 = 9.5;

    printf("Average grade : %.2f\n", (student1.grade1 + student1.grade2) / 2);
}