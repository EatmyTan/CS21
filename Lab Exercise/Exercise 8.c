#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    int size;
    int capacity;
    char *arr;
}vector;

void initstring(vector* vec, char* str){
    vec->size = 0;
    vec->capacity = 15;
    vec->arr = malloc(sizeof(char)*vec->capacity + 1);
    int len = strlen(str);
    for(int i=0; i<len; i++){
        vec->arr[i] = str[i];
        vec->size += 1;
    }
    //printf("%s", vec->arr);
}
void concantenate(vector* combined, vector* a, vector* b){
    //printf("%s", b->arr);
    combined->size = 0;
    combined->capacity = a->size+b->size;
    combined->arr = malloc(sizeof(char)+combined->capacity);
    for(int i=0; i<a->size; i++){
        combined->arr[i] = a->arr[i];
        combined->size++;
    }
    for(int x=a->size, j=0; j<b->size; x++,j++){
        combined->arr[x] = b->arr[j];
        combined->size++;
    }
    for(int i=0; i<combined->capacity; i++)
        printf("%c", combined->arr[i]);
}
void slice(vector* sliced, vector* source, int start, int end){
    sliced->size = 0;
    sliced->capacity = strlen(source->arr);
    sliced->arr = malloc(sizeof(char)+sliced->capacity);
    for(int i=0; i<(end - start); i++){
        sliced->arr[i] = source->arr[start+i];
    }
    printf("%s", sliced->arr);
}
int main(){
    int choice;
    printf("Enter input: ");
    scanf("%i", &choice);
    char str1[15];
    if(choice==1){
        char str2[15];
        vector a, b, combined;
        scanf("%s %s", &str1, &str2);
        initstring(&a, str1);
        initstring(&b, str2);
        concantenate(&combined, &a, &b);
    } 
    else if(choice==2){
        int start, end;
        scanf("%s %i %i", &str1, &start, &end);
        vector source, sliced;
        initstring(&source, str1);
        slice(&sliced, &source, start, end);
    }
}