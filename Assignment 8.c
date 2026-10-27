#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
#define MAX_LEN 20

struct Job{
    int id;
    char title[MAX_LEN];
};

struct Queue{
    struct Job Queue[MAX_SIZE];
    int f;
    int r;
};

int isempty(struct Queue Q){
    if (Q.f == Q.r) return 1;
    return 0;
}

int linisfull(struct Queue Q){
    if (Q.r == MAX_SIZE -1) return 1;
    return 0;
}

int linenqueue(struct Queue *Q, struct Job j){
    //if (linisfull(*Q)) return -1;
    Q->r++;
    Q->Queue[Q->r] = j;
    return 0;
}

struct Job lindequeue(struct Queue *Q){
    /* if (isempty(*Q)){
        struct Job j;
        j.id = -1;
        return j;
    } */
    Q->f++;
    return Q->Queue[Q->f];
}

int circisfull(struct Queue Q){
    if ((Q.r + 1)%MAX_SIZE == Q.f) return 1;
    return 0;
}

int circenqueue(struct Queue *Q, struct Job j){
    //if (circisfull(*Q)) return -1;
    Q->r = (Q->r+1) % MAX_SIZE;
    Q->Queue[Q->r] = j;
    return 0;
}

struct Job circdequeue(struct Queue *Q){
    /* if (isempty(*Q)){
        struct Job j;
        j.id = -1;
        return j;
    } */
    Q->f = (Q->f + 1) % MAX_SIZE;
    return Q->Queue[Q->f];
}


int main(){
    struct Queue Q1;
    Q1.f = -1;
    Q1.r = -1;

    struct Queue Q2;
    Q2.f = 0;
    Q2.r = 0;

    while (1+1==2){
        printf("\n\n0 - Exit\n1 - Linear Enqueue\n2 Linear Dequeue\n3 - Circular Enqueue\n 4 - Circular Dequeue\n\nEnter Choice : ");
        int c;
        scanf("%d", &c);

        struct Job j;

        switch (c)
        {
            case 0:
                return 0;
            case 1:
                printf("Enter Job ID and Title\n");
                scanf("%d",&j.id);
                char temp;
                scanf("%c",&temp);
                fgets(j.title,MAX_LEN,stdin);
                if (linisfull(Q1))
                    printf("\nQueue is full\n\n");
                else{
                    linenqueue(&Q1, j);
                    printf("\nDone.\n\n");
                }
                break;
            case 2:
                if (isempty(Q1))
                    printf("\nQueue is empty\n\n");
                else{
                    j = lindequeue(&Q1);
                    printf("\nID - %d, Title - %s\n\n",j.id, j.title);
                }
                break;
            case 3:
                printf("Enter Job ID and Title\n");
                scanf("%d",&j.id);
                char temp2;
                scanf("%c",&temp2);
                fgets(j.title,MAX_LEN,stdin);
                if (circisfull(Q2))
                    printf("\nQueue is full\n\n");
                else{
                    circenqueue(&Q2, j);
                    printf("\nDone.\n\n");
                }
                break;
            case 4:
                if (isempty(Q2))
                    printf("\nQueue is empty\n\n");
                else{
                    j = circdequeue(&Q2);
                    printf("\nID - %d, Title - %s\n\n",j.id, j.title);
                }
                break;
        }
    }

    return 0;
}
