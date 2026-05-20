#include <stdio.h>
#define SIZE 5

typedef struct {
    char name[50];
    float grade1;
    float grade2;
}Students;
float student_average(Students student){
    return (student.grade1 + student.grade2) / 2;
}

void student_information(Students student){
    printf("Name: %s\n",student.name);
    printf("Average grade: %.2f\n", student_average(student));    
}

void class_information(Students class1[SIZE]){
    for(int a = 0; a < SIZE; a++){
        printf("Student number %d\n", a + 1);
        student_information(class1[a]);
    }
}
void student_best_average(Students class1[SIZE]){
    int student_number = 0;
    float best_average = student_average(class1[0]);

    for(int a = 1; a < SIZE; a++){
        float average = student_average(class1[a]);
        if( average > best_average ){
            student_number = a;
            best_average = average;
        }  
    }
    printf("The best student is number %d\n", student_number + 1);
    printf("Student Name: %s\n", class1[student_number].name);
    printf("Average: %.2f\n", best_average);
}

int main(){
    Students student1 = {"John", 9.0, 9.5};
    Students student2 = {"Carl", 7, 7.5};
    Students student3 = {"James", 5.5, 4.0};
    Students student4 = {"Lingard", 6.0, 5.5};
    Students student5 = {"Max", 2.0, 9.0};

    Students class1[5] = {student1, student2, student3, student4, student5};

    class_information(class1);
    
    student_best_average(class1);

}