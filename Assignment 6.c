#include <stdio.h>

#include <stdlib.h>

#include <string.h>



#define MAX_SIZE 50

#define MAX_LEN 50



struct Stack{

    char s[MAX_SIZE];

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



struct StackArr{

    char s[MAX_SIZE][MAX_LEN];

    int top;

};



int isemptyarr(struct StackArr S){

    if (S.top == -1) return 1;

    return 0;

}



int isfullarr(struct StackArr S){

    if (S.top == MAX_SIZE - 1) return 1;

    return 0;

}



int pusharr(struct StackArr *S, char c[MAX_LEN]){

    S->top++;

    strcpy(S->s[S->top],c);

    return 0;

}



void poparr(struct StackArr *S, char c[MAX_LEN]){

    strcpy(c,S->s[S->top]);

    S->top--;

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



int prior1(char c){ //ICP for infix -> postfix

    switch (c){

        case '+': return 1;

        case '-': return 1;

        case '*': return 2;

        case '/': return 2;

        case '%': return 2;

        case '^': return 4;

        case '(': return 5;

        case ')': return 0;

    }

    return 0;

}



int prior2(char c){ //ISP for infix -> postfix

    switch (c){

        case '+': return 1;

        case '-': return 1;

        case '*': return 2;

        case '/': return 2;

        case '%': return 2;

        case '^': return 3;

        case '(': return 0;

        case ')': return 5;

    }

    return 0;

}



void InfixToPostfix(char a[MAX_LEN], char b[MAX_LEN]){

    int i = 0;

    int j = 0;

    char c;

    struct Stack s;

    s.top = -1;

    while (a[i] != '\0'){

        if (a[i] == ')'){

            i++;

            while ((c = pop(&s)) != '('){

                b[j++] = c;

            }

        }

        else if (isOperator(a[i])){

            while (!isempty(s) && prior2(peek(s)) >= prior1(a[i])){

                b[j++] = pop(&s);

            }

            push(&s, a[i++]);

        }

        else{

            b[j++] = a[i++];

        }

    }

    while (!isempty(s)){

        b[j++] = pop(&s);

    }

    b[j] = 0;

}



void InfixToPrefix(char a[MAX_LEN], char b[MAX_LEN]){

    int i = strlen(a) - 1;

    int j = 0;

    char c;

    struct Stack s;

    s.top = -1;

    struct Stack r;

    r.top = -1;

    while (i >= 0){

        if (a[i] == '('){

            i--;

            while ((c = pop(&s)) != ')'){

                push(&r,c);

            }

        }

        else if (isOperator(a[i])){

            while (!isempty(s) && prior1(peek(s)) > prior2(a[i])){

                push(&r,pop(&s));

            }

            push(&s, a[i--]);

        }

        else{

            push(&r, a[i--]);

        }

    }

    while (!isempty(s)){

        push(&r,pop(&s));

    }

    while (!isempty(r)){

        b[j++] = pop(&r);

    }

    b[j] = 0;

}



void PostfixToInfix(char a[MAX_LEN], char b[MAX_LEN]){

    int i = 0;

    int j = 0;

    struct StackArr s;

    s.top = -1;

    char temp[MAX_LEN];

    strcpy(temp,"a");

    temp[1] = '\0';

    while (a[i] != 0){

        if (isOperand(a[i])){

            temp[0] = a[i++];

            pusharr(&s,temp);

        }

        else if (isOperator(a[i])){

            char op1[MAX_LEN];

            char op2[MAX_LEN];

            poparr(&s,op2);

            poparr(&s,op1);

            temp[0] = a[i];

            strcat(op1,temp);

            strcat(op1,op2);

            temp[0] = ')';

            strcat(op1,temp);

            temp[0] = '(';

            strcpy(op2,temp);

            strcat(op2,op1);

            pusharr(&s,op2);

            i++;

        }

    }

    poparr(&s,temp);

    strcpy(b,temp);

}





void PostfixToPrefix(char a[MAX_LEN], char b[MAX_LEN]){

    int i = 0;

    int j = 0;

    struct StackArr s;

    s.top = -1;

    char temp[MAX_LEN];

    strcpy(temp,"a");

    temp[1] = '\0';

    while (a[i] != 0){

        if (isOperand(a[i])){

            temp[0] = a[i++];

            pusharr(&s,temp);

        }

        else if (isOperator(a[i])){

            char op1[MAX_LEN];

            char op2[MAX_LEN];

            poparr(&s,op2);

            poparr(&s,op1);

            temp[0] = a[i];

            strcat(temp,op1);

            strcat(temp,op2);

            pusharr(&s,temp);

            temp[1] = 0;

            i++;

        }

    }

    poparr(&s,temp);

    strcpy(b,temp);

}





void PrefixToInfix(char a[MAX_LEN], char b[MAX_LEN]){

    int i = strlen(a) - 1;

    int j = 0;

    struct StackArr s;

    s.top = -1;

    char temp[MAX_LEN];

    strcpy(temp,"a");

    temp[1] = '\0';

    while (i >= 0){

        if (isOperand(a[i])){

            temp[0] = a[i--];

            pusharr(&s,temp);

        }

        else if (isOperator(a[i])){

            char op1[MAX_LEN];

            char op2[MAX_LEN];

            poparr(&s,op1);

            poparr(&s,op2);

            temp[0] = a[i];

            strcat(op1,temp);

            strcat(op1,op2);

            temp[0] = ')';

            strcat(op1,temp);

            temp[0] = '(';

            strcpy(op2,temp);

            strcat(op2,op1);

            pusharr(&s,op2);

            i--;

        }

    }

    poparr(&s,temp);

    strcpy(b,temp);

}



void PrefixToPostfix(char a[MAX_LEN], char b[MAX_LEN]){

    int i = strlen(a) - 1;

    int j = 0;

    struct StackArr s;

    s.top = -1;

    char temp[MAX_LEN];

    strcpy(temp,"a");

    temp[1] = '\0';

    while (i >= 0){

        if (isOperand(a[i])){

            temp[0] = a[i--];

            pusharr(&s,temp);

        }

        else if (isOperator(a[i])){

            char op1[MAX_LEN];

            char op2[MAX_LEN];

            poparr(&s,op1);

            poparr(&s,op2);

            temp[0] = a[i];

            strcat(op1,op2);

            strcat(op1,temp);

            pusharr(&s,op1);

            i--;

        }

    }

    poparr(&s,temp);

    strcpy(b,temp);

}



int main(){

    char a[MAX_LEN] = "";

    char b[MAX_LEN] = "";

    char c;

    do{

        printf("\nEnter Expression : ");

        scanf("%s", a);

        printf("\n0 - Exit\n1 - Infix to Postfix\n2 - Infix to Prefix\n3 - Postfix to Infix\n4 - Postfix to Prefix\n5 - Prefix to Infix\n6 - Prefix to Postfix\n\nEnter Choice : ");

        scanf("%c",&c);

        scanf("%c",&c);

        switch(c){

            case '1':

                InfixToPostfix(a,b);

                printf("%s\n\n",b);

                break;

            case '2':

                InfixToPrefix(a,b);

                printf("%s\n\n",b);

                break;

            case '3':

                PostfixToInfix(a,b);

                printf("%s\n\n",b);

                break;

            case '4':

                PostfixToPrefix(a,b);

                printf("%s\n\n",b);

                break;

            case '5':

                PrefixToInfix(a,b);

                printf("%s\n\n",b);

                break;

            case '6':

                PrefixToPostfix(a,b);

                printf("%s\n\n",b);

                break;

        }

    }while (c != 0);

}
