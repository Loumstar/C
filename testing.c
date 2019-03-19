#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

typedef int bool;
#define true 1;
#define false 0;

bool isinarray(int arr[], int pointer){
    for(int i=0; i<pointer; i++){
        if(arr[i] == arr[pointer]){
            printf("Found equal: %d, %d = %d\n", i, pointer, arr[i]);
            return true;
        }
    }
    return false;
}


int main(){
    FILE *fpntr;
    char x;
    fpntr = fopen("textfile.txt", "w");
    if(!fpntr) return 1;
    while(!(x = getc(fpntr))){
        
    }
    fclose(fpntr);

    return 0;
}  
