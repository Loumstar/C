#include <stdio.h>

int main(){
    int a, b, c;
    char* var;
    printf("Type three numbers to be compared: ");
    scanf("%d %d %d", &a, &b, &c);
    //if b > a, ask b > c, else ask a > c. If not return c.
    if(b > a){
        if(b > c){
            var = "second";
        } else {
            var = "third";
        }
    } else {
        if(a > c){
            var = "first";
        } else {
            var = "third";
        }
    }

    printf("The %s is the greatest.\n", var);

    return 0;
}