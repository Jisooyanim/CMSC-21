//DMA and File Reading
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* freadline(FILE* fp){
    int i;
    for(i = 0; !feof(fp); i++){
        getc(fp);
    }

    fseek(fp, 0, SEEK_SET);
    char* buffer = (char*)malloc(sizeof(buffer) * i);
    buffer = fgets(buffer, i, fp);
    return buffer;
}

int main(){
    FILE* fp = fopen("story.txt", "r");
    if(!fp){
        printf("Error!");
        return -1;
    }

    printf("%s", freadline(fp));
    fclose(fp);
    return 0;
}

//Linked List
#include <stdio.h>
#include <stdlib.h>

struct SLList {
    struct Node* head;
    struct Node* tail;
    int size;
};
typedef struct SLList SLList;

struct Node {
    int value;
    struct Node* next;
};
typedef struct Node Node;

void empty(SLList* list){
    Node* temp;
    Node* pain;
    pain = list->head;

    while (pain)
    {
        temp = pain->next;
        free(pain);
        pain = temp;
        list->size--;
    }
}

int main(){
    SLList* list;
    empty(list);
    return 0;
}