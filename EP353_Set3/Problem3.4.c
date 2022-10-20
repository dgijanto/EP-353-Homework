#include <stdio.h>

// initialize variables
int count;

// initialize and define functions
void numChars(char str[50], char input);

void numChars(char *s, char input){
    char *ptr = s;
    for(int i = 0; i < 50; i++){
        if(*ptr == input){
            count++;
        }
        ptr++;
    }
}

int main(){

    // initialize vars
    char user; 
    char str[50];

    // get user input
    printf("Enter a string: ");
    scanf("%[^\n]", str);

    printf("Enter a character included in your string: ");
    scanf(" %c", &user);

    // set end of string
    str[49] = '\0'; 

    //call function
    numChars(str, user);

    // print result
    printf("The string %s has %i %c's \n", str, count, user);
}