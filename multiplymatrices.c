#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#if !defined(ARRAY_SIZE)
    #define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

struct Matrix {
    int** mp; //pointer to pointer-arrays of values
    int d[2]; //dimensions of matrix (row x col)
};

static char* lower(char* string){
    int i = 0;
    char c;
    while(*(string + i) != '\0'){ //ends at null terminator
        *(string + i) = tolower(*(string + i));
        /*
        string is lowered and replaces the 
        original at its location.
        */
        i++;
    }
    return string; //can also return if wanted
}

void print_matrix(struct Matrix m){
    for(int r=0; r<m.d[0]; r++){
        for(int c=0; c<m.d[1]; c++){
            printf("%d", *(*(m.mp + r) + c));
            if(c+1 != m.d[1]) printf(", ");
        }
        printf("\n");
    }
}

void print_array(int* ap){
    int sizearray = ARRAY_SIZE(ap);
    printf("[");
    for(int e=0; e<sizearray; e++){
        printf("%d", *(ap + e));
        if(e+1 != sizearray) printf(", ");
    }
    printf("]\n");
}

int** input_matrix(int* sizearray, int mnumber){
    printf("Enter the values for matrix %d\n", mnumber);
    static int **m;
    m = (int**)malloc(sizearray[0]*sizeof(int*));
    for(int r=0; r<sizearray[0]; r++){
        printf("Row %d: ", r+1);
        m[r] = malloc(sizearray[1]*sizeof(int));
        for(int c=0; c<sizearray[1]; c++){
            scanf("%d", &m[r][c]);
        }
    }
    return m;
}
struct Matrix mmultiply(struct Matrix m1, struct Matrix m2){
    printf("Calculating...\n");
    struct Matrix p;
    p.d[0] = m1.d[0];
    p.d[1] = m2.d[1];
    int sum;

    p.mp = (int**)malloc(p.d[0]*sizeof(int*));
    for(int r=0; r<p.d[0]; r++){
        p.mp[r] = malloc(p.d[1]*sizeof(int));
        for(int c=0; c<p.d[1]; c++){
            sum = 0;
            for(int x=0; x<m1.d[1]; x++){
                sum += *(*(m1.mp+r)+x) * *(*(m2.mp+x)+c);
            }
            p.mp[r][c] = sum;
        }
    }
    return p;
}

void free_matrix(struct Matrix m);

int main(){
    //Select size of matrices
    struct Matrix m1, m2, m3;

    printf("Please enter the dimensions of the matrices to be multiplied.\n");
    printf("Note that the column length of the first matrix must equal the row length of the second.\n");

    printf("Enter the dimensions (r * c) for matrix 1: ");
    scanf("%d %d", &m1.d[0], &m1.d[1]);

    printf("Enter the dimensions (r * c) for matrix 2: ");
    scanf("%d %d", &m2.d[0], &m2.d[1]);
    
    if(m1.d[1] != m2.d[0]){
        printf("Matrices cannot be multiplied (c1 != r2).\n");
        return 0;
    }

    //Select values for each matrix
    m1.mp = input_matrix(m1.d, 1);
    m2.mp = input_matrix(m2.d, 2);
    char c[4];

    printf("\nMatrix 1:\n");
    print_matrix(m1);
    printf("\nMatrix 2:\n");
    print_matrix(m2);

    printf("\nIs this correct? ");
    scanf("%s", &c[0]);
    lower(c);
    
    if(strcmp(c, "yes") != 0){
        printf("Exiting...\n");
        return 0;
    }

    //Multiply
    m3 = mmultiply(m1, m2);
    print_matrix(m3);

    return 0;
}