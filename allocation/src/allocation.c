#include "../include/allocation.h"
#include <stdlib.h>
#include <stdio.h>


void* allocate_array(size_t member_size, size_t nmember,bool clear)
{
    //check to see if the clear flag is set
    if(clear){
        if(nmember == 0){ //check to see if num of elements in array = 0
            return NULL;  
        }
        return calloc(nmember, member_size);
    }
    else{
        if(nmember == 0){
            return NULL;
        }
        return malloc(member_size*nmember);
    }
}

void* reallocate_array(void* ptr, size_t size)
{
    return realloc(ptr, size);
}

void deallocate_array(void** ptr)
{
    //check for null ptr
    if(*ptr != NULL){
        free(*ptr);
        *ptr = NULL;
    }
}

char* read_line_to_buffer(char* filename)
{
    //declare file pointer
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        return NULL;
    }
    char *heap = malloc(sizeof(char)*100);
    heap = fgets(heap, 100, fp);
    fclose(fp);
    return heap;
}
