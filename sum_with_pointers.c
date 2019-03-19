#include <stdio.h>
#include <stdlib.h>

int main(){
    int* p1 = malloc(sizeof(int));
    int* p2 = malloc(sizeof(int));
    int sum;
    
    printf("Type two numbers to sum: ");
    scanf("%d %d", p1, p2);

    sum = *p1 + *p2;
    printf("The sum is %d.\n", sum);

    return 0;
}