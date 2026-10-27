#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 20
#define MAX_LEN 20

struct Order{
    char item[MAX_LEN];
    int housenumber;
};

int Accept(struct Order s[MAX_SIZE], int n){
    char c;
    scanf("%c",&c);
    fgets(s[n].item,MAX_LEN,stdin);
    scanf("%d",&s[n].housenumber);
    return n+1;
}

void Display(struct Order s[MAX_SIZE], int n){
    printf("\n\n");
    for (int i = 0; i < n; i++){
        printf("%d.\tOrder for - %s\tAt House - %d\n\n",i+1, s[i].item, s[i].housenumber);
    }
}

void swap(struct Order *s1, struct Order *s2){
    struct Order stemp;
    stemp = *s2;
    *s2 = *s1;
    *s1 = stemp;
}

int LinearSearch(struct Order s[MAX_SIZE], int n, char e[MAX_LEN]){
    for (int i = 0; i < n; i++){
        if (strcmp(s[i].item,e) == 0){
            return i;
        }
    }
    return -1;
}

/*int SentinelSearch(struct Order s[MAX_SIZE], int n, char e1[MAX_LEN], int e2){
    for (int i = 0; i < n; i++){
        if (strcmp(s[i].item,e) == 0){
            return i;
        }
    }
    return -1;
}*/

int BinarySearch(struct Order s[MAX_SIZE], int n, int e){
    int l = 0, h = n;
    int mid;
    while (l <= h){
        mid = (l+h)/2;
        if (e < s[mid].housenumber)
            h = mid - 1;
        else if (e > s[mid].housenumber)
            l = mid + 1;
        else
            return mid;
    }
    return -1;
}

void BubbleSort(struct Order s[MAX_SIZE], int n){
    for (int i = n; i > 0; i--){
        for (int j = 1; j < i; j++){
            if (s[j-1].housenumber > s[j].housenumber)
                swap(&s[j-1],&s[j]);
        }
    }
}

void SelectionSort(struct Order s[MAX_SIZE], int n){
    for (int i = 0; i < n; i++){
        int min = s[i].housenumber;
        int mindex = i;
        for (int j = i+1; j < n; j++){
            if (s[j].housenumber < min){
                min = s[j].housenumber;
                mindex = j;
            }
        }
        swap(&s[mindex], &s[i]);
    }
}

void InsertionSort(struct Order s[MAX_SIZE], int n){
    for (int i = 1; i < n; i++){
        struct Order selected = s[i];
        struct Order temp;
        for (int j = i; j >= 0; j--){
            s[j] = s[j-1];
            if (s[j-1].housenumber <= selected.housenumber){
                s[j] = selected;
                break;
            }
        }
    }
}

void ShellSort(struct Order s[MAX_SIZE], int n, int gap){
    if (gap == 0) return;
    int swapflag = 0;
    do{
        swapflag = 0;
        for (int i = 0; i < n - gap; i++){
            if (s[i].housenumber > s[i + gap].housenumber){           swap(&s[i],&s[i+gap]);
                swapflag++;
            }
        }
    }
    while (swapflag != 0);
    ShellSort(s,n,gap/2);
}

void MergeSort(struct Order a[MAX_SIZE], int l, int h){
    int m = h-((h-l)/2);
    printf("loop l:%d h:%d m:%d\n",l,h,m);
    if (m == h || m == l) return;
    MergeSort(a,l,m);
    MergeSort(a,m,h);
    struct Order b[MAX_SIZE];
    int i = l;
    int j = m;
    for (int k = l; k < h; k++){
        if (i < m && j < h){
            if (a[j].housenumber > a[i].housenumber)
               b[k] = a[i++];
            else
                b[k] = a[j++];
        }
        else if (j < h)
            b[k] = a[j++];
        else if (i < m)
            b[k] = a[i++];
    }
    for (int k = l; k < h; k++){
        a[k] = b[k];
    }
}



int main(){
    int n = 0;
    struct Order o[MAX_SIZE];
    int c = 0;
    do {
        printf("\n- - - - - - -\n0 - Exit\n1 - Accept\n2 - Display\n3 - Linear Search\n5 - Binary Search\n6 - Bubble Sort\n7 - Selection Sort\n8 - Insertion Sort\n9 - Shell Sort\n10 - Merge Sort\n\nYour Choice - ");
        scanf("%d",&c);
        switch (c) {
            case 1:
                n = Accept(o,n);
                break;
            case 2:
                if (n == 0) printf("No Elements in Array\n");
                else Display(o,n);
                break;
            case 3:
                char itemtosearch[MAX_LEN];
                scanf("%c",&itemtosearch[0]);
                fgets(itemtosearch,MAX_LEN,stdin);
                int r = LinearSearch(o,n,itemtosearch);
                if (r == -1)
                    printf("No Orders for this item.\n");
                else
                {
                    printf("\nOrdered by - House %d\nPriority - %d.\n\n",o[r].housenumber, r+1);
                }
            /*case 4:
                char itemtosentinel[MAX_LEN];
                scanf("%c",&itemtosentinel[0]);
                fgets(itemtosentinel,MAX_LEN,stdin);
                int housenumbertosentinel;
                scanf("%d", &housenumbertosentinel);
                int x = LinearSearch(o,n,itemtosentinel,housenumbertosentinel);
                if (x == -1)
                    printf("No Orders for this item.\n");
                else
                {
                    printf("Ordered by - House %d\nPriority - %d.\n\n",o[x].housenumber, r+1);
                }*/
            case 5:
                int housenumbertosearch;
                scanf("%d", &housenumbertosearch);
                int y = BinarySearch(o,n,housenumbertosearch);
                if (y == -1)
                    printf("No Orders for this item.\n");
                else
                {
                    printf("\nItem Ordered - %sPriority - %d.\n\n",o[y].item, r+1);
                }
            case 6:
                BubbleSort(o,n);
                printf("Performed\n");
                break;
            case 7:
                SelectionSort(o,n);
                printf("Performed\n");
                break;
            case 8:
                InsertionSort(o,n);
                printf("Performed\n");
                break;
            case 9:
                ShellSort(o,n,n/2);
                printf("Performed\n");
                break;
            case 10:
                MergeSort(o,0,n);
                printf("Performed\n");
                break;
        }
    } while (c != 0);
    return 0;
}
