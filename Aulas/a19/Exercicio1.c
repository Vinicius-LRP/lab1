#include <stdio.h>
#include <string.h>


struct Product{
    char name[50];
    float price;
    int quantity;
};

int main(){
    struct Product product1;
    
    strcpy(product1.name, "Ball");
    product1.price = 8.99;
    product1.quantity = 999;

    printf("Name: %s\n", product1.name);
    printf("Value total in stock: %.2f$\n", product1.quantity * product1.price);
    
} 