#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int main(){
    int num, revnum;
    printf("Input number to be reversed: ");
    scanf("%d", &num);
    
    //Converts num to string as numstr
    int length = snprintf(NULL, 0, "%d", num);
    char* numstr = malloc(length + 1);
    char* revnumstr = malloc(length + 1);
    snprintf(numstr, length+1, "%d", num);
    
    //make string other way round 
    for(int i = 0; i < length; i++){
        revnumstr[i] = numstr[length - 1 - i];
    }
    printf("%s, %s, %d\n", numstr, revnumstr, length);
    
    //Converts string to num as revnum
    revnum = atoi(revnumstr);
    printf("%d\n", revnum);

    //free up space made to perform string operation
    free(numstr);
    free(revnumstr);

    return 0;

}
*/

//Much better
int main(){
    int num, revnum = 0;
    printf("Input number to be reversed: ");
    scanf("%d", &num);

    while(num >= 1){
        revnum *= 10;
        revnum += num % 10;
        num /= 10;
        //printf("%d, %d\n", num, revnum);
    }

    printf("%d\n", revnum);
    return 0;
}