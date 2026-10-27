#include <stdio.h>
#define MAX_SIZE 20

void InputMatrix(int *m, int *n, int a[MAX_SIZE][MAX_SIZE]){
   
    printf("\nEnter size of matrix : ");
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

void ConvertToSparseMatrix(int m, int n, int a[MAX_SIZE][MAX_SIZE], int *o, int *p, int c[MAX_SIZE][MAX_SIZE]){
    int k = 0;
    c[0][0] = m;
    c[0][1] = n;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] != 0){
                k++;
                c[k][0] = i;
                c[k][1] = j;
                c[k][2] = a[i][j];
            }
        }
    }
    c[0][2] = k;
    *o = k+1;
    *p = 3;
}

void SlowTranspose(int a[MAX_SIZE][MAX_SIZE], int c[MAX_SIZE][MAX_SIZE]){
    c[0][0] = a[0][1];
    c[0][1] = a[0][0];
    c[0][2] = a[0][2];
    int k = 0;
    for (int i = 0; i < a[0][1]; i++){
        for (int j = 1; j <= a[0][2]; j++){
            if (a[j][1] == i){
                k++;
                c[k][0] = a[j][1];
                c[k][1] = a[j][0];
                c[k][2] = a[j][2];
            }
        }
    }
}

void FastTranspose(int a[MAX_SIZE][MAX_SIZE], int c[MAX_SIZE][MAX_SIZE]){
    c[0][0] = a[0][1];
    c[0][1] = a[0][0];
    c[0][2] = a[0][2];
    int count[a[0][1]];
    int index[a[0][1]];
    for (int i = 0; i < a[0][1]; i++){
        count[i] = 0;
        index[i] = 0;
    }
   
    for (int i = 1; i <= a[0][2]; i++){
        count[a[i][1]]++;
    }
   
    int k = 1;
    index[0] = 1;
    for (int i = 1; i < a[0][1]; i++){
        k += count[i-1];
        index[i] = k;
    }
   
    for (int i = 1; i <= a[0][2]; i++){
        c[index[a[i][1]]][0] = a[i][1];
        c[index[a[i][1]]][1] = a[i][0];
        c[index[a[i][1]]][2] = a[i][2];
        index[a[i][1]]++;
    }
}

void AddSparseMatrix(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int c[MAX_SIZE][MAX_SIZE]){
    int i = 1, j = 1, k = 0;
    while (1 + 1 == 2){
        if (i <= a[0][2] && j <= b[0][2]){
            if (a[i][0] * a[0][1] + a[i][1] == b[j][0] * b[0][1] + b[j][1]){
                k++;
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = a[i][2] + b[j][2];
                i++;
                j++;
            }
            else if (a[i][0] * a[0][1] + a[i][1] > b[j][0] * b[0][1] + b[j][1]){
                k++;
                c[k][0] = b[j][0];
                c[k][1] = b[j][1];
                c[k][2] = b[j][2];
                j++;
            }
            else if (a[i][0] * a[0][1] + a[i][1] < b[j][0] * b[0][1] + b[j][1]){
                k++;
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = a[i][2];
                i++;
            }
        }
        else if (i <= a[0][2]){
            k++;
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++;
        }
        else if (j <= b[0][2]){
            k++;
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++;
        }
        else break;
    }
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];
    c[0][2] = k;
}

void SubtractSparseMatrix(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int c[MAX_SIZE][MAX_SIZE]){
    int i = 1, j = 1, k = 0;
    while (1 + 1 == 2){
        if (i <= a[0][2] && j <= b[0][2]){
            if (a[i][0] * a[0][1] + a[i][1] == b[j][0] * b[0][1] + b[j][1]){
                k++;
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = a[i][2] - b[j][2];
                i++;
                j++;
            }
            else if (a[i][0] * a[0][1] + a[i][1] > b[j][0] * b[0][1] + b[j][1]){
                k++;
                c[k][0] = b[j][0];
                c[k][1] = b[j][1];
                c[k][2] = -b[j][2];
                j++;
            }
            else if (a[i][0] * a[0][1] + a[i][1] < b[j][0] * b[0][1] + b[j][1]){
                k++;
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = a[i][2];
                i++;
            }
        }
        else if (i <= a[0][2]){
            k++;
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++;
        }
        else if (j <= b[0][2]){
            k++;
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = -b[j][2];
            j++;
        }
        else break;
    }
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];
    c[0][2] = k;
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

int MultiplySparseMatrix(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int c[MAX_SIZE][MAX_SIZE]){
    if (a[0][1] != b[0][0]) return -1;
    int index[b[0][1]];
    for (int i = b[0][2]; i > 0; i--){
        index[b[i][0]] = i;
    }
   

    c[0][0] = a[0][0];
    c[0][1] = b[0][1];
    c[0][2] = 0;

    for (int i = 1; i <= a[0][2]; i++){
        int j = index[a[i][1]];
        while (b[j][0] == a[i][1]){
            int temp[6] = {a[i][0],0,b[j][1],0,a[i][2] * b[j][2],0};
            int filled = 0;
            for (int k = 1; k <= c[0][2] + 1;k++){
                if (!filled && k > c[0][2]) break;
                if ((c[k][0] * c[0][1] + c[k][1]) == (a[i][0] * c[0][1] + b[j][1]))
                {
                    c[k][2] += (a[i][2] * b[j][2]);
                    filled = 1;
                    break;
                }
                else if (filled == 0 && c[k][0] * c[0][1] + c[k][1] > a[i][0] * c[0][1] + b[j][1])
                {
                    filled = 1;
                    c[0][2]++;
                }
                if (filled){
                    temp[1] = temp[0];
                    temp[0] = c[k][0];
                    c[k][0] = temp[1];
                   
                    temp[3] = temp[2];
                    temp[2] = c[k][1];
                    c[k][1] = temp[3];
                   
                    temp[5] = temp[4];
                    temp[4] = c[k][2];
                    c[k][2] = temp[5];
                }
            }
            if (filled == 0){
                c[0][2]++;
                c[c[0][2]][0] = a[i][0];    
                c[c[0][2]][1] = b[j][1];    
                c[c[0][2]][2] = a[i][2] * b[j][2];    
            }
            j++;
        }
    }
    return 0;
}

int main()
{
    int m,n;
    int a[MAX_SIZE][MAX_SIZE];
    InputMatrix(&m, &n, a);
   
    printf("\nSparse Martix A:\n");
    int o,p;
    int b[MAX_SIZE][MAX_SIZE];
    ConvertToSparseMatrix(m,n,a,&o,&p,b);
    DisplayMatrix(o,p,b);
   
    while (1){
        printf("\n - - - - - - - - - - \nEnter Choice\n\n0 - Exit\n1 - Slow Transpose\n2 - Fast Transpose\n3 - Addition\n4 - Subtraction\n5 - Multiplication\n - - - - - - - - - - \n");
        int choice;
        scanf("%d",&choice);

        switch(choice){
            case 0: return 0;
            case 1:
                printf("\nTranspose Sparse Martix:\n");
                int c[MAX_SIZE][MAX_SIZE];
                SlowTranspose(b,c);
                DisplayMatrix(o,p,c);
                break;
               
            case 2:
                printf("\nTranspose of Transposed Sparse Martix:\n");
                int d[MAX_SIZE][MAX_SIZE];
                FastTranspose(b,d);
                DisplayMatrix(o,p,d);
                break;

            case 3:{
                int m1,n1;
                int a1[MAX_SIZE][MAX_SIZE];
                InputMatrix(&m1, &n1, a1);
               
                printf("\nSparse Martix B:\n");
                int o1,p1;
                int b1[MAX_SIZE][MAX_SIZE];
                ConvertToSparseMatrix(m1,n1,a1,&o1,&p1,b1);
                DisplayMatrix(o1,p1,b1);
               
                printf("\nAddition of A and B:\n");
                int q,r;
                int c[MAX_SIZE][MAX_SIZE];
                AddSparseMatrix(b,b1,c);
                q = c[0][2] + 1;
                r = 3;
                DisplayMatrix(q,r,c);
                break;
            }
            case 4:{
                int m1,n1;
                int a1[MAX_SIZE][MAX_SIZE];
                InputMatrix(&m1, &n1, a1);
               
                printf("\nSparse Martix B:\n");
                int o1,p1;
                int b1[MAX_SIZE][MAX_SIZE];
                ConvertToSparseMatrix(m1,n1,a1,&o1,&p1,b1);
                DisplayMatrix(o1,p1,b1);
               
                printf("\nAddition of A and B:\n");
                int q,r;
                int c[MAX_SIZE][MAX_SIZE];
                SubtractSparseMatrix(b,b1,c);
                q = c[0][2] + 1;
                r = 3;
                DisplayMatrix(q,r,c);
                break;
            }
            case 5:{
                 int m1,n1;
                 int a1[MAX_SIZE][MAX_SIZE];
                 InputMatrix(&m1, &n1, a1);
                 
                 printf("\nSparse Martix B:\n");
                 int o1,p1;
                 int b1[MAX_SIZE][MAX_SIZE];
                 ConvertToSparseMatrix(m1,n1,a1,&o1,&p1,b1);
                 DisplayMatrix(o1,p1,b1);
                 
                 printf("\nMultiplication of A and B:\n");
                 int q,r;
                 int c[MAX_SIZE][MAX_SIZE];
                 MultiplySparseMatrix(b,b1,c);
                 q = c[0][2] + 1;
                 r = 3;
                 DisplayMatrix(q,r,c);
            }
        }
    }
    return 0;
}
