include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/arrays.h"

// LOOK INTO MEMCPY, MEMCMP, FREAD, and FWRITE




bool array_copy(const void *src, void *dst, const size_t elem_size, const size_t elem_count)
{
    //check to see if src or dst is  null
    if(src == NULL|| dst == NULL){
        return false;
    }

    //check if count or size is zero
    if(elem_count == 0 || elem_size == 0){
        return false;
    }


    size_t s = elem_count * elem_size; // total number of bytes to be copied
    memcpy(dst, src, s); //use memcpy() function to copy src array to dst array
    int ret; // return value for memcmp() function

    ret = memcmp(dst, src, s); //use memcmp() function to check if copy is successful

    //if ret < 0 then bytes dst must be less than src
    //if ret > 0 then bytes in dst must be more than src
    // if ret = 0 then dst is equal to source so return true
    if(ret > 0 || ret < 0){
        return false;
    }
    else{
        return true;
    }

}

bool array_is_equal(const void *data_one, void *data_two, const size_t elem_size, const size_t elem_count)
{
    //check to see data_one or data_two is null
    if(data_one == NULL || data_two == NULL){
        return false;
    }

    //check to see if count or size is zero
    if(elem_count == 0 || elem_size == 0){
        return false;
    }

    size_t s = elem_count * elem_size; // total number of bytes to be copied
    int ret; //return value for memcmp() function
    ret = memcmp(data_one, data_two, s); //use memcmp() function to compare data_one with data_two

    if(ret < 0){
        // printf("data_one is less than data_two.\n");
        return false;
    }else if (ret > 0){
        // printf("data_two is less than data_one.\n");
        return false;
    }
    else{
        //printf("data_one and data_two are equal.\n");
        return true;
    }

}

ssize_t array_locate(const void *data, const void *target, const size_t elem_size, const size_t elem_count)
{
    //check for NULL source
    if(data == NULL){
        return -1;
    }

    //check for NULL target
    if(target == NULL){
        return -1;
    }

    //check if count or size is zero
    if(elem_count == 0 || elem_size == 0){
        return -1;
    }

    int *data1 = (int*)data;
    size_t i = 0;
    while(i < elem_count){
        if(*(int*)target == data1[i]){
            return i;

        }	
        i++;
    }

    return -1;
}

bool array_serialize(const void *src_data, const char *dst_file, const size_t elem_size, const size_t elem_count)
{
    //check for NULL data
    if(src_data == NULL){
        return false;
    }

    //check for NULL file name
    if(dst_file == NULL){
        return false;
    }

    //check for bad filename
    int ret;
    ret = strcmp(dst_file, " ");
    if(ret == 0){
        return false;
    }

    //check for bad file name
    int ret1;
    ret1 = strcmp(dst_file, "\n");
    if(ret1 == 0){
        return false;
    }

    //check if count = 0
    if(elem_count == 0){
        return false;
    }

    //check if size = 0
    if(elem_size == 0){
        return false;
    }

    //file pointer
    FILE *fp;
    fp = fopen(dst_file, "wb"); //open file for writing
    if(fp == NULL){
        return false;
    }
    fwrite(src_data, elem_size, elem_count, fp);
    fclose(fp); //close file

    return true;

}

bool array_deserialize(const char *src_file, void *dst_data, const size_t elem_size, const size_t elem_count)
{
    //check for NULL data
    if(dst_data == NULL){
        return false;
    }

    //check for NULL filename
    if(src_file == NULL){
        return false;
    }

    //check if element size or element count is zero
    if(elem_count == 0 || elem_size == 0){
        return false;
    }

    //check for bad filename
    int ret;
    ret = strcmp(src_file, " ");
    if(ret == 0){
        return false;
    }

    //check for bad filename
    int ret1;
    ret1  = strcmp(src_file, "\n");
    if(ret1 == 0){
        return false;
    }

    FILE *fp; //file pointer
    fp  = fopen(src_file, "rb"); //open file for reading
    if(fp == NULL){
        //printf("File cannot be opened.\n");
        return false;
    }
    fread(dst_data, elem_size, elem_count, fp);
    fclose(fp); //close file for reading

    return true;
}

