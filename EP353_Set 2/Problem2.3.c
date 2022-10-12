#include <stdio.h>

int main(){
    // For loop, printing out notes based on i 
    for(int i=0; i<12; i++){
        switch(i){
            case 0:
            printf("C ");
            break;

            case 1:
            printf("Db ");
            break;

            case 2:
            printf("D ");
            break;

            case 3:
            printf("Eb ");
            break;

            case 4:
            printf("E ");
            break;

            case 5:
            printf("F ");
            break;

            case 6:
            printf("Gb ");
            break;

            case 7:
            printf("G ");
            break;

            case 8:
            printf("Ab ");
            break;

            case 9:
            printf("A ");
            break;

            case 10:
            printf("Bb ");
            break;

            case 11:
            printf("B\n");
            break;
        }
    }
}