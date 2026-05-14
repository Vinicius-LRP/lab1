#include <stdio.h>

typedef struct{
    char name[50];
    char number[50];


}Contacts;

void register_numbers(int max_numbers , Contacts c[max_numbers]){
    for(int a = 0; a < max_numbers; a++){
        printf("Add the contacts number %d\n", a + 1 );
        printf("Enter name: ");
        scanf("%s", c[a].name);

        printf("Enter number: ");
        scanf("%s", c[a].number);
    }
}

void show_numbers(int max_numbers, Contacts c[]){
    for(int a = 0 ; a < max_numbers ; a++){
        printf("Number %d\n", a + 1);
        printf("Name: %s\n", c[a].name);
        printf("Number of phone: %s\n", c[a].number);
    }
}


int main(){
    Contacts numbers[10];

    
    register_numbers(10,numbers);
    show_numbers(10,numbers);

}