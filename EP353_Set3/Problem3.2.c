#include <stdio.h>

int main(){

    // Defining Array
    int numbers[7] = {5,9,1,2,4,8,3};

        // Defining Inital Values
        int top = 0;
        int bot = 6;
        int c;

    for(int i=0;i<4;i++){

        // Switching Variables
        c = numbers[top];
        numbers[top] = numbers[bot];
        numbers[bot] = c;

        // In/Decrementing array values for switch
        top++;
        bot--;
    }

    // Printing Values
    for(int i=0;i<7;i++){
        printf("The value of arr at index %i is %i\n", i, numbers[i]);
    }
}