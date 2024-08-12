#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int reverseString(char * input);

int main(){
    printf("\nInserisci Stringa: ");
    char input[30];
    //input[strcspn(fgets(input, 30, stdin), "\r\n")] == '\0';
    scanf("%[^\n]", input);

    printf("\nLa stringa originale: %s", input);
    printf("\nLa stringa invertita: ");
    int car = reverseString(input);
    printf(" %d", car);
    // printf("\n Lung %d", strlen(input));

    return 0;
}

int reverseString(char * input){
    if(strcmp(input, "\0") == 0) return 0;
    int i = reverseString(input + 1);
    printf("%c", *input);
    return 1 + i;
}


