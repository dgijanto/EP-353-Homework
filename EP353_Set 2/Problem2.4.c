#include <stdio.h>

int main(){

    // Initialize variable 
    int number;
    
    // Request an integer 
    printf("Enter an integer:");
    scanf("%d", &number);

    // Print odd numbers using for loop
    for(int i = 1; i <= number; i+=2){

          printf("%d ", i);  

        }

    // Escape sequence after loop finishes
    printf("\n");    
}