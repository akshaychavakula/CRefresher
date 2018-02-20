#include "../include/structures.h"
#include <stdio.h>

int compare_structs(sample_t* a, sample_t* b)
{
    if(a->a != b->a){
        return 0;
    }
    else if(a->b != b->b){
        return 0;
    }
    else if(a->c != b->c){
        return 0;
    }
    return 1;
}

void print_alignments()
{
    printf("Alignment of int is %zu bytes\n",__alignof__(int));
    printf("Alignment of double is %zu bytes\n",__alignof__(double));
    printf("Alignment of float is %zu bytes\n",__alignof__(float));
    printf("Alignment of char is %zu bytes\n",__alignof__(char));
    printf("Alignment of long long is %zu bytes\n",__alignof__(long long));
    printf("Alignment of short is %zu bytes\n",__alignof__(short));
    printf("Alignment of structs are %zu bytes\n",__alignof__(fruit_t));
}

int sort_fruit(const fruit_t* a,int* apples,int* oranges, const size_t size)
{
    //parameter check
    if(a == NULL){
        return -1;
    }
    else if(apples == NULL){
        return -1;
    }
    else if(oranges == NULL){
        return -1;
    }
    else if(size == 0){
        return -1;
    }

    size_t i = 0;
    for(i=0;i<size;i++){
        if(a[i].type == 0){
            (*oranges)++;
        }
        else if(a[i].type == 1){
            (*apples)++;
        }
        else{
            return -1;
        }
    }
    int total = *apples + *oranges;
    if((size_t)total != size){
        return -1;
    }
    return size;
}

int initialize_array(fruit_t* a, int apples, int oranges)
{
    //check for NULL a
    if(a == NULL){
        return -1;
    }
    int i = 0;
    for(i = 0;i < apples; i++){
        a[i].type = 1;
    }
    for(i = apples; i < apples+oranges; i++){
        a[i].type = 0;
    }
    return 0;
}

int initialize_orange(orange_t* a)
{
    if(a == NULL){
        return -1;
    }
    a->type = 0;
    a->weight = 1;
    a->peeled = 2;

    return 0;

}

int initialize_apple(apple_t* a)
{
    if(a == NULL){
        return -1;
    }
    a->type = 1;
    a->weight = 2;
    a->worms = 3;
    return 0;
}
