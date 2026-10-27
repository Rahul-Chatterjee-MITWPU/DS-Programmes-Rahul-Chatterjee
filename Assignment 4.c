#include <stdio.h>

#include <string.h>

#include <stdlib.h>



#define MAX_SIZE 50

#define MAX_LEN 50



struct List{

    char name[MAX_LEN];

    struct List *next;

};



int Add(struct List *head, char name[MAX_LEN], int index){

    struct List *ptr = head;

    for (int i = 0; i < index - 1; i++){

        if (ptr->next == NULL) return -1;

        ptr = ptr->next;

    }

    struct List *temp = ptr->next;

    ptr->next = malloc(sizeof(struct List));

    ptr->next->next = temp;

    strcpy(ptr->next->name,name);

    return 0;

}



void AddAtEnd(struct List *head, char name[MAX_LEN]){

    struct List *ptr = head;

    while (ptr->next != NULL)

        ptr = ptr -> next;

    ptr->next = malloc(sizeof(struct List));

    ptr->next->next = NULL;

    strcpy(ptr->next->name,name);

}



int Remove(struct List *head, int index){

    struct List *ptr = head;

    if (ptr->next == NULL) return -1;

    for (int i = 0; i < index - 1; i++){

        if (ptr->next->next == NULL) return -1;

        ptr = ptr->next;

    }

    ptr->next = ptr->next->next;

    return 0;

}



void Create(struct List *head){

    head->next = NULL;

    char c;

    char t;

    struct List *ptr = head;

    do{

        printf("Enter Student Name : ");

        char a[MAX_LEN];

        fgets(a,MAX_LEN, stdin);

        ptr->next = malloc(sizeof(struct List));

        ptr = ptr->next;

        ptr->next = NULL;

        strcpy(ptr->name,a);

        printf("Do you want to continue? (y/n) : ");

        scanf("%c",&c);

        scanf("%c",&t);

    }while (c=='y');

}



void Display(struct List *head){

    struct List *ptr = head->next;

    int i = 1;

    while (ptr != NULL){

        printf("%d. %s stored at %p and is pointing to %p\n",i++,ptr->name,ptr,ptr->next);

        ptr = ptr->next;

    }

}



int Count(struct List *head){

    struct List *ptr = head->next;

    int i = 0;

    while (ptr != NULL){

        i++;

        ptr = ptr->next;

    }

    return i;

}



void SortList(struct List *head){

    struct List *ptr1;

    struct List *ptr2;

    struct List *ptr3;

    int len = Count(head);

    for (int i = 0; i < len; i++){

        ptr1 = head;

        ptr2 = ptr1->next;

        ptr3 = ptr2->next;

        while(ptr3 != NULL){

            if (strcmp(ptr2->name,ptr3->name) > 0){

                ptr2->next = ptr3->next;

                ptr1->next = ptr3;

                ptr3->next = ptr2;

            }

            ptr1 = ptr2;

            ptr2 = ptr3;

            ptr3 = ptr3->next;

        }

    }

}



void ReverseList(struct List *head){

    struct List *ptr1 = head;

    struct List *ptr2 = ptr1->next;

    struct List *ptr3 = ptr2->next;

    

    while (ptr2 != NULL){

        

        if (ptr1 != head)

            ptr2->next = ptr1;

        else

            ptr2->next = NULL;

        

        ptr1 = ptr2;

        ptr2 = ptr3;

        if (ptr3 != NULL)

            ptr3 = ptr3->next;

    }

    head->next = ptr1;

    

}





int main(){

    struct List list;

    struct List *head = &list;

    head->next = NULL;

    Create(head);

    Display(head);

    printf("\nNumber of Students = %d\n",Count(head));

    char c;

    char t;

    do{

        if (c != '\n') printf("\n0.Exit\n1.Display\n2.Show Count\n3.Add Student\n4.Remove Student\n5.Sort List Alphabetically\n6.Reverse List\nEnter Operation : ");

        scanf("%c",&c);

        switch (c){

            case '1':

                Display(head);

                break;

            case '2':

                printf("\nNumber of Students is %d\n\n",Count(head));

                break;

            case '3':

                printf("Enter Student Name : ");

                char a[MAX_LEN];

                scanf("%c",&c);

                fgets(a,MAX_LEN, stdin);

                printf("Enter Registration Number : ");

                int b;

                scanf("%d",&b);

                if (Add(head,a,b) == -1) printf("Index Too Big\n");

                else printf("Success\n");

                break;

            case '4':

                printf("Enter Registration Number : ");

                int r;

                scanf("%d",&r);

                if (Remove(head, r) == -1) printf("Index Too Big\n");

                else printf("Success\n");

                break;

            case '5':

                SortList(head);

                printf("Success\n");

                break;

            case '6':

                ReverseList(head);

                printf("Success\n");

                break;

        }

    } while (c != '0');

}
