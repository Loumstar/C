#include <stdio.h>

int main(){
    int sum = 0, avrg, elem[10];
    
    //Collect data
    printf("Type ten numbers for array manipulation: ");
    for(int i=0; i<10; i++){
        scanf("%d", &elem[i]);
    }
    //Calculate once data is collected
    for(int x=0; x<10; x++){
        sum += elem[x];
    }
    avrg = sum / 10;
    printf("The sum is %d with a mean of %d\n", sum, avrg);

    return 0;
}