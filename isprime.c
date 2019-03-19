#include <stdio.h>

typedef int bool;
#define true 1;
#define false 0;

int main(){
    int num, range, p_count = 1;
    int primes[1000] = { 2 };
    bool is_i_prime;

    printf("Type number you want check is prime: ");
    scanf("%d", &num);

    if(num % 2 == 0){
        printf("False: Divisible by 2 you idiot!\n");
        return 0;
    }

    range = num;
    for(int i=3; i<=range; i++){
        is_i_prime = true;
        for(int p=0; p<p_count; p++){
            if(i % primes[p] == 0){
                is_i_prime = false;
                break;
            }
        }
        if(is_i_prime){
            primes[p_count] = i;
            p_count++;
            printf("New prime: %d @ %d\n", i, p_count);
            
            if(num % i == 0){
                printf("False: Divisible by %d.\n", i);
                return 0;
            }
        }
        range = num / i;
    }
    printf("True\n");
    return 0;
}