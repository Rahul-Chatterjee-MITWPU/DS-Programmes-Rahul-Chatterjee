
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>



#define MAX_SIZE 50

#define MAX_LEN 50



struct Stack{

    int s[MAX_SIZE];

    int top;

};



int isempty(struct Stack S){

    if (S.top == -1) return 1;

    return 0;

}



int isfull(struct Stack S){

    if (S.top == MAX_SIZE - 1) return 1;

    return 0;

}



int push(struct Stack *S, char c){

    S->top++;

    S->s[S->top] = c;

    return 0;

}



char pop(struct Stack *S){

    char c = S->s[S->top];

    S->top--;

    return c;

}



char peek(struct Stack S){

    char c = S.s[S.top];

    return c;

}



int isOperator(char c){

    switch (c){

        case '+':

        case '-':

        case '*':

        case '/':

        case '%':

        case '^':

        case '(':

        case ')': return 1;

    }

    return 0;

}



int isOperand(char c){

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c  >= '0' && c <= '9'))

        return 1;

    return 0;

}



int ValueOfVariable(char names[MAX_SIZE], int values[MAX_SIZE], int *n, char op){

    for (int i = 0; i < *n; i++){

        if (names[i] == op){

            return values[i];

        }

    }

    printf("Enter Value of variable '%c' : ", op);

    int value;

    scanf("%d",&value);

    names[*n] = op;

    values[*n] = value;

    *n = *n+1;

    return value;

}



int Calculate(int a, int b, char op){

    switch (op) {

        case '+':

            return a+b;

        case '-':

            return a-b;

        case '*':

            return a*b;

        case '/':

            return a/b;

        case '%':

            return a%b;

        case '^':

            return pow(a,b);

    }

    return -1;

}


int EvaluatePostfix(char a[MAX_LEN]){

    int i = 0;

    int j = 0;

    struct Stack s;

    s.top = -1;

    char variablenames[MAX_SIZE];

    int variablevalues[MAX_SIZE];

    int varcount = 0;;

    while (a[i] != 0){

        if (isOperand(a[i])){

            push(&s,ValueOfVariable(variablenames, variablevalues, &varcount, a[i]));

        }

        else if (isOperator(a[i])){

            int op2 = pop(&s);

            int op1 = pop(&s);

            push(&s,Calculate(op1,op2,a[i]));

        }

        i++;

    }

    return pop(&s);

}



int main(){

    char a[MAX_LEN] = "";

    char c;

    printf("\nEnter Expression : ");

    scanf("%s", a);

    printf("%d\n",EvaluatePostfix(a));

}
