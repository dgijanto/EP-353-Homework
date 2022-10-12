#include <stdio.h>

int static bar = 0;

void beatbox();

void beatbox(){
    if (bar % 4 == 0){
        printf("Potato Cats!");
        printf("");
    }
    else{
        printf("Boots N Cats N");
    }
}

int main(){

    printf("Input a number of bars: ");
    scanf("%d", bar);

    printf("%d", bar);

}