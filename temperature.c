#include <stdio.h>

float convert_temp(float t, char u){
    if(u == 'F'){
        printf("Converting Fahrenheit to Celsuis\n");
        return (t - 32) * 5 / 9;
    } else if(u == 'C'){
        printf("Converting Celsuis to Fahrenheit\n");
        return (t * 9 / 5) + 32;
    } else {
        printf("Unit not identified\n");
        return t;
    }
}

int main(){
    float temp, newtemp;
    char unit, newunit;

    printf("Input the temperature for conversion: ");
    scanf("%f %c", &temp, &unit);
    
    printf("Your input: %f %c\n", temp, unit);
    newtemp = convert_temp(temp, unit);
    
    if(unit == 'F'){
        newunit = 'C';
    } else if(unit == 'C'){
        newunit = 'F';
    } else {
        newunit = unit;
    }
    
    printf("Temperature = %.1f%c\n", newtemp, newunit);
    
    return 0;
}