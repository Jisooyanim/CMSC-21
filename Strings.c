#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int size;
    int capacity;
    char *arr;
}vector;

void initList(vector* vector);
void initString(vector* vector, char* word);
void resize(vector* vector);
void insertItem(vector* vector, int index, char item);
void concatenate(vector* combined, vector* a, vector* b);
void slice(vector* sliced, vector* source, int start, int end);
void printVector(vector* vector);

int main(){
    vector a,b, pain;
    int choice, start, end;
    char *string1 = (char*)malloc(sizeof(char) * 15);
    char *string2 = (char*)malloc(sizeof(char) * 15);

    printf("Enter choice: ");
    scanf("%i", &choice);

    switch (choice)
    {
    case 1:
        printf("First word: ");
        scanf("%s", string1);
        printf("Second word: ");
        scanf("%s", string2);

        initString(&a, string1);
        initString(&b, string2);
        concatenate(&pain, &a, &b);
        printVector(&pain);
        break;
    
    case 2:
        printf("Word? ");
        scanf("%s", string1);
        printf("Enter 2 integers: ");
        scanf("%i %i", &start, &end);

        initString(&a, string1);
        slice(&pain, &a, start, end);
        printVector(&pain);
        break;

    default:
        printf("Nice choice:)");
        break;
    }
    return 0;
}

void initList(vector* vector){
    vector->size = 0;
    vector->capacity = 10;
    vector->arr = (char*)malloc(sizeof(char)* vector->capacity);
}

void initString(vector* vector, char* word){
    initList(vector);

    for(int i = 0; i < strlen(word); i++){
        vector->arr[i] = word[i];
        vector->size++;
    }
}

void resize(vector* vector){
    int newcap = 2 * vector->size;
    char* newarr = (char*)malloc(sizeof(char) * newcap);

    for(int i = 0; i < vector->size; i++){
        *(newarr + i) = *(vector->arr + i);
    }

    vector->capacity = newcap;
    free(vector->arr);
    vector->arr = newarr;
}

void insertItem(vector* vector, int index, char item){
    if(index >= 0 && index <= vector->size){
        if(vector->size == vector->capacity){
            resize(vector);
        }

        *(vector->arr + index) = item;
        vector->size++;
    }
    return;
}

void concatenate(vector* combined, vector* a, vector* b){
    initList(combined);
    int combined_letters = a->size + b->size;

    for(int i = 0; i < combined_letters; i++){
        if(a->size > i){
            insertItem(combined, i, *(a->arr + i));
        }else{
            insertItem(combined, i, *(b->arr + (i - a->size)));
        }
    }
}

void slice(vector* sliced, vector* source, int start, int end){
    initList(sliced);

    for(int i = start; i <= end - 1; i++){
        insertItem(sliced, i - start, *(source->arr + i));
    }
}

void printVector(vector* vector){
    for(int i = 0; i < vector->size; i++){
        printf("%c", vector->arr[i]);
    }
}