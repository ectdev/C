#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

    char input[600], holder[40];

    fgets(input, 600, stdin);
    
    char *token = strtok(input, ", ");
    while (token != NULL){
        strcpy(holder, token);
        printf("%s \n", holder);
        token = strtok(NULL, ", ");
    }






    return 0;
}