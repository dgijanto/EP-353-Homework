#include <stdio.h>

// Declare Function
void beatbox();

// Define Function
void beatbox(bar){
    // Setting Loop Length
    for(int i=0;i<bar;i++){

        // Printing "Potato Cats!" evert 4th loop
        if ((i+1) % 4 == 0){
            printf("Potato Cats!\n");
            printf("\n");
        }
        
        // Printing Boots N Cats N 
        else{
            printf("Boots N Cats N\n");
        }
    }
}

int main(){
    // Declare variable
    int input;

    // Getting User Input
    printf("Input a number of bars: ");
    scanf("%d", &input);
    printf("\n");

    // Call Functions
    beatbox(input);

}