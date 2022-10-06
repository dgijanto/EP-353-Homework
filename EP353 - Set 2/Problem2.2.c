#include <stdio.h>

int main(){

    // Assigning variables
    char note = 'F';
    int pitchClass;

    // Assigning Pitch Class Per Note
    switch (note){
      
        case 'C':
        case 'c':
            pitchClass = 0;
            break;
        
        case 'D':
        case 'd':
            pitchClass = 2;
            break;   

        case 'E':
        case 'e':
            pitchClass = 4;
            break;

        case 'F':
        case 'f':
            pitchClass = 5;
            break;

        case 'G':
        case 'g':
            pitchClass = 7;
            break;
        
        case 'A':
        case 'a':
            pitchClass = 9;
            break;
        
        case 'B':
        case 'b':
            pitchClass = 11;
            break;
    }

    // Printing pitch class 
    printf("The note %c translates to %i in pitch class.\n", note, pitchClass);
}