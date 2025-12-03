#include <stdio.h>

// pointer - A variable that stores the memory address of another variable
// Benefit: save memory by passing the address of a large data structure instead of copying the entire structure

void birthday(int *age);

int main() {
    int age = 0;
    printf("Enter your age: ");
    scanf("%d", &age);

    int *pAge = &age;

    birthday(pAge);
    
    printf("Next year, you are %d years old", age);
}

void birthday(int *age){
    // pass by reference
    (*age)++;
}
