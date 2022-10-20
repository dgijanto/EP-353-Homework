#include <stdio.h>

// initialize function
void setArray(int *numbers, int value, int size);

// define function 
void setArray(int *numbers, int value, int size){
    for(int i = 0; i < size; i++){
        numbers[i] = value;
    }
}

int main(){

    // initialize variables
    int numbers[8];
    int input;

    // getting user input
    printf("Input an integer number: ");
    scanf("%d", &input);

    // call function
    setArray(numbers, input, 8);


    // print results
    printf("The 'numbers' array is now initialized to %d:\n", input);
    printf("\n");
    for(int i = 0; i < 8; i++){
        printf("%i ", numbers[i]);
        if(i == 7){
            printf("\n");
        }
    }
}