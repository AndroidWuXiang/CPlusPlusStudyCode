#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t count_lock = PTHREAD_MUTEX_INITIALIZER;

struct DynamicArray {
    void **headerAddress;
    int capacity;
    int size;

};

struct Person
{
	char name[64];
	int age;
};

int  initDynamicArray(struct DynamicArray** dynamicArray , int capacity) {

    if(capacity < 1) {
        return -1;
    }

    *dynamicArray = (struct DynamicArray*)malloc(sizeof(struct DynamicArray));
    (*dynamicArray)->capacity = capacity;    
    (*dynamicArray)->size = 0;
    (*dynamicArray)->headerAddress = (void**)malloc(sizeof(void*)*((*dynamicArray)->capacity));
    return 0;
}

void insert(struct DynamicArray** arr, void *data, int position){
    pthread_mutex_lock (&count_lock);
    if(*arr == NULL || data == NULL  || position < 0) {
        printf("insert failed\n");
        return;
    }
    

    if((*arr)->size >= (*arr)->capacity) {
        int newcapacity = (*arr)->capacity * 2;
        void** newSpace = (void**)malloc(sizeof(void*)*newcapacity);
        memcpy(newSpace, (*arr)->headerAddress, sizeof(void*)*((*arr)->capacity+1));
        free((*arr)->headerAddress);
        (*arr)->headerAddress = newSpace;
        (*arr)->capacity = newcapacity;

    }

    if(position >= (*arr)->size) 
    {
        ((*arr)->headerAddress[(*arr)->size]) = data;
    }
    else
    {
        for(int i = (*arr)->size -1; i >= position; --i){
            //memcpy((*arr)->headerAddress [i+1] , (*arr)->headerAddress [i], sizeof(void*));
            (*arr)->headerAddress [i+1] = (*arr)->headerAddress [i];
        }
        (*arr)->headerAddress[position]  = data;
        //printf("===%d\n", *(int*)data);
    }
    ++(*arr)->size;
    
    pthread_mutex_unlock (&count_lock);

}

int compare(void* a, void* b) {
    if(*(int*)a == *(int*)b)
    {
        return 1;
    } else {
        return 0;
    }

}

void remove(struct DynamicArray** arr, int position) {
    if(arr == NULL ) {
        return;
    }

    if((*arr)->size <= position) {
        return;
    }

    for(int i = position; i <  (*arr)->size; ++i){
        //memcpy((*arr)->headerAddress [i+1] , (*arr)->headerAddress [i], sizeof(void*));
        (*arr)->headerAddress [i] = (*arr)->headerAddress [i+1];
    }
    (*arr)->headerAddress [(*arr)->size - 1] = NULL; 
    (*arr)->size--;
}


void removeValue(struct DynamicArray** arr, void* data, int(*compare)(void*, void*)) {
    if(arr == NULL ) {
        return;
    }

    if(data == NULL ) {
        return;
    }

    for(int i = 0; i <  (*arr)->size; ++i){
        //memcpy((*arr)->headerAddress [i+1] , (*arr)->headerAddress [i], sizeof(void*));
        if(compare((*arr)->headerAddress [i] ,data)) {
            remove(arr, i);
            break;
        }
    }

}



void forEach(struct DynamicArray* arr, void(*callback)(void*)) {
    for(int i = 0; i < arr->size; i++){
        callback(arr->headerAddress[i]);
    }
}

void myCallback (void* data) {
     printf("%d\n", *(int*)(data));

}

int main() {
    struct DynamicArray* dynamicArray;
    initDynamicArray(&dynamicArray , 15);
    // for(int  i = 0; i < 4; i++) {
        //struct Person p1 = { "aaa", i };
    // int value = (1+10);
    // insert(&dynamicArray, &value, 100);
    // int value2 = (2+10);
    // insert(&dynamicArray, &value2, 100);

    // int value3 = (3+10);
    // insert(&dynamicArray, &value3, 100);
    
    // int value4 = (4+10);
    // insert(&dynamicArray, &value4, 1);
    // sleep(1);

    // forEach(dynamicArray, myCallback);

    // for(int  i = 0; i < dynamicArray->size; i++) {
        
    //     printf("%d\n", *((int*)dynamicArray->headerAddress[i]));
    // }
    
    for(int  i = 0; i < 4; i++) {
        // count++;
        int *count = (int *)malloc(sizeof(int));
        *count = i*100;
        insert(&dynamicArray, count, 100);

    }

    // int *b;
    // int c = 10;
    // b = &c; 
    // *b = 20;
    printf("-----------------\n");
    forEach(dynamicArray, myCallback);
    int a = 100;
    //remove(dynamicArray, a, compare);
    removeValue(&dynamicArray, &a, compare);
    printf("-----------------\n");
    forEach(dynamicArray, myCallback);
    remove(&dynamicArray, 2);
    printf("-----------------\n");
    forEach(dynamicArray, myCallback);
    for(int  i = 0; i < dynamicArray->size; i++) {
        free(((int*)dynamicArray->headerAddress[i]));
    }
    free(dynamicArray->headerAddress);
    free(dynamicArray);
    
}