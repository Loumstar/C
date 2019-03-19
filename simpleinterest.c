#include <stdio.h>
#include <math.h>
//Code to determine inputted simple interest from a user.
//Variables are: initial_value, rate_of_intr and time

int main(){
    float initial_value, rate_of_intr, time, final_value;
    printf("Input the the values: INITIAL_VALUE RATE_OF_INTEREST TIME\n");
    scanf("%f%f%f", &initial_value, &rate_of_intr, &time);
    
    printf("Your inputs are:\nInitial Value: %f\nRate of Interest: %f\nTime: %f\n", initial_value, rate_of_intr, time);
    
    final_value = rate_of_intr * pow(rate_of_intr, time);
    printf("Final Value after Interest: %f\n", final_value);

    return 0;
};