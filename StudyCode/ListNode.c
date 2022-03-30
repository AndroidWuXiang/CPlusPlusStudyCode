/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct ListNode 
{
    int data;
    struct ListNode* next; 
};

struct ListNode * initListNode() 
{

    struct ListNode *header = (ListNode*)malloc(sizeof(struct ListNode));
    header->data = -1;
    header->next = NULL;
    return header;
}

void add(struct ListNode *header, int data) {
    if(header == NULL || data == -1 || header->data != -1) {
        printf("add failed \n");
        return;
    }

    struct ListNode *newNode = (ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    struct ListNode *temp = header;
    int count = 0;
    while(temp != NULL) {
        if(temp->data == data) {
            printf("add failed, the same data is forbided\n");
            break;
        }
        if(temp->next == NULL) {
            temp->next = newNode;
            newNode->next = NULL;
            break;
                
        }
        temp = temp->next ;
    }

}

void printAll(struct ListNode *header){
    if(header == NULL) {
        printf("printAll failed \n");
        return;
    }
    struct ListNode *temp = header->next;
    if(temp == NULL) {
        printf("no data header:%d\n",  header->data);
        return;
    }
    
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next ;
    }
    printf("\n-----------------\n");
}

void deleteNode(struct ListNode *header, int data){
    if(header == NULL) {
        printf("deleteNode failed \n");
        return;
    }

    struct ListNode *prev = header;
    struct ListNode *temp = prev->next;
    //struct ListNode *temp = header->next;
    while(temp != NULL) {
        if(temp->data == data) {
            prev->next = temp->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
        
    }
}

void clear(struct ListNode **header) {
    if(header == NULL) {
        printf("clear failed \n");
        return;
    }
    struct ListNode *prev = *header;
    struct ListNode *temp = prev->next;
    while(temp != NULL) {
        prev = temp->next;
        free(temp);
        temp = prev;
    }
    (*header)->next = NULL;
}

void destoryListNode(struct ListNode **header) {
    if(header == NULL) {
        printf("clear failed \n");
        return;
    }
    struct ListNode *prev = *header;
    struct ListNode *temp = prev->next;
    while(temp != NULL) {
        prev = temp->next;
        free(temp);
        temp = prev;
    }
    free(*header);
    *header = NULL;
}

void reverseListNode(struct ListNode **header) {
    if(header == NULL || (*header)->next == NULL) {
        printf("reverseListNode failed \n");
        return;
    }
    //method1
    // struct ListNode *next = (*header)->next;
    // struct ListNode *prev = (*header)->next;
    // struct ListNode *first = (*header)->next;
    // struct ListNode *current = (*header)->next;
    // struct ListNode *insert = (*header);

    // while(first->next != NULL) {
    //     current = first;
    //     next = current->next;
    //     while (next != NULL)
    //     {
    //         prev = current;
    //         current = current->next;
    //         next = current->next;
    //     }

    //     insert->next = current;
    //     insert = insert->next;
    //     prev->next = NULL;
    // }
    // insert->next = first;

    //method2
    struct ListNode *next = NULL;
    struct ListNode *prev = NULL;
    struct ListNode *current = (*header)->next;

    while(current!= NULL) {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
        
    }

    (*header)->next = prev;

}

void swap(struct ListNode** x, struct ListNode** y)
{
    int temp;
    temp=(*x)->data;
    (*x)->data=(*y)->data;
    (*y)->data = temp;
    printf("swap----%d,%d\n", (*x)->data, (*y)->data);
}

typedef int (*compare)(int d1, int d2);

void selectSort(struct ListNode **header, compare myCompare) {
    struct ListNode *current = (*header)->next;
    struct ListNode *changeNode = NULL;
    struct ListNode *start = NULL;
    while(current != NULL) {
        changeNode = current;
        start = current->next;
        while(start != NULL) {
            if(myCompare(changeNode->data, start->data)) {
                changeNode = start;
            }
            start = start->next;
        }
        if(current != changeNode) {
            swap(&current, &changeNode);
        }
        
        current = current->next;
    }

}



int myCompare(int a, int b) {
    return a <= b;

}


int main()
{

    struct ListNode *header = initListNode();
    struct ListNode node = {1001, NULL};
    add(header, 1);
    add(header, 222);
    add(header, 31);
    add(header, 4);
    add(header, 15);
    //add(header, -1);
    //deleteNode(header, 3);
    add(header, 1000);
    printAll(header);
    //clear(&header);
    //printAll(header);
    //destoryListNode(&header);
    //header = NULL;
    //printAll(header);
    //add(header, 56);
    // reverseListNode(&header);
    // printAll(header);

    selectSort(&header, myCompare);
    printAll(header);
    return 0;
}