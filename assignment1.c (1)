#include <stdio.h>
#define MAX_SIZE 20

void InputMatrix(int *m, int *n, int a[MAX_SIZE][MAX_SIZE]){
    
    printf("Enter size of matrix : ");
    scanf("%d",m);
    scanf("%d",n);
    
    printf("Enter elements of matrix :\n");
    for (int i = 0; i < *m; i++){
        for (int j = 0; j < *n; j++){
            scanf("%d",&a[i][j]);
        }
    }
}

void DisplayMatrix(int m, int n, int a[MAX_SIZE][MAX_SIZE]){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int AddMatrix(int m, int n, int a[MAX_SIZE][MAX_SIZE], int o, int p, int b[MAX_SIZE][MAX_SIZE], int c[MAX_SIZE][MAX_SIZE]){
    if (m != o || n != p) return -1;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return 0;
}

int SubtractMatrix(int m, int n, int a[MAX_SIZE][MAX_SIZE], int o, int p, int b[MAX_SIZE][MAX_SIZE], int c[MAX_SIZE][MAX_SIZE]){
    if (m != o || n != p) return -1;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    return 0;
}

void TransposeMatrix(int m, int n, int a[MAX_SIZE][MAX_SIZE], int c[MAX_SIZE][MAX_SIZE]){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            c[j][i] = a[i][j];
        }
    }
}


int MultiplyMatrix(int m, int n, int a[MAX_SIZE][MAX_SIZE], int o, int p, int b[MAX_SIZE][MAX_SIZE], int c[MAX_SIZE][MAX_SIZE]){
    if (n != o) return -1;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){
            c[i][j] = 0;
            for (int k = 0; k < n; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return 0;
}

int main()
{
    //Matrix A
    int m,n;
    int a[MAX_SIZE][MAX_SIZE];
    InputMatrix(&m, &n, a);
    
    //Matrix B
    int o,p;
    int b[MAX_SIZE][MAX_SIZE];
    InputMatrix(&o, &p, b);
    
    //Menu
    printf("Specify Operation\n1 - Addition\n2 - Subtraction\n3 - Transpose of A\n4 - Multiplication\n");
    int choice;
    scanf("%d",&choice);
    
    //Matrix C
    int c[MAX_SIZE][MAX_SIZE];
    
    //Operations
    switch(choice){
        case 1:
            if (AddMatrix(m,n,a,o,p,b,c) == -1) {
                printf("Matrices not addable.");
            }
            else {
                DisplayMatrix(m,p,c);
            }
            break;
        case 2:
            if (SubtractMatrix(m,n,a,o,p,b,c) == -1) {
                printf("Matrices not subtractable.");
            }
            else {
                DisplayMatrix(m,p,c);
            }
            break;
        case 3:
            TransposeMatrix(m,n,a,c);
            DisplayMatrix(n,m,c);
            break;
        case 4:
            if (MultiplyMatrix(m,n,a,o,p,b,c) == -1) {
                printf("Matrices not multiplyable.");
            }
            else {
                DisplayMatrix(m,p,c);
            }
            break;
        deafult:
            printf("Invalid Choice.");
    }
    
    return 0;
}
