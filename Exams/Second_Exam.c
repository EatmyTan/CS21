#include<stdio.h>
#include<stdlib.h>
struct Node{
    int value;
    struct Node* next;
};
typedef struct Node Node;

struct SLList{
    struct Node* head;
    struct Node* tail;
    int size;
};
typedef struct SLList SLList;

char* freadline(FILE* fp){
    int count = 0;
    char ch;
    while(ch!=EOF){
        ch = fgetc(fp);
        count++;
        if(ch == EOF)
            break;
        if(ch == '\n') // breaks the loop if there are multiple lines achieved
            break;
    }
    fseek(fp,0,SEEK_SET);
    char* line = malloc(count*sizeof(char));
    line = fgets(line, sizeof(char)*count, fp);
    return line;
}
void empty(SLList* list){
    struct Node* toDelete = malloc(sizeof(struct Node));
    toDelete = list->head;
    while(toDelete != NULL){
        toDelete = list->head;
        free(toDelete);
        list->head = toDelete->next;
    }
}
