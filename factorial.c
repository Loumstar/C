#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, fact = 1;
    printf("Type number to determine factorial: ");
    scanf("%d", &num);

    for(int i=1; i<=num; i++){
        if(2147483647 / fact <= i){
            printf("int byte-length not great enough to calculate factorial (fact > 2^31 - 1).\n");
            return 1;
        }
        fact *= i;
        //printf("%d, %d\n", i, fact);
    }

    printf("%d! = %d\n", num, fact);
    
    return 0;
}