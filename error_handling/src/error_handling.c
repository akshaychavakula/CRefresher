#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


#include "../include/error_handling.h"

int create_blank_records(Record_t **records, const size_t num_records)
{
    //check to see if records is initialized to NULL
    if(*records != NULL){
        return -1;
    }
    //check for zero num_records
    if(num_records == 0){
        return -1;
    }
    *records = (Record_t*) malloc(sizeof(Record_t) * num_records);
    //check for unsuccessful allocation 
    if(*records == NULL){
        return -2;
    }
    memset(*records,0,sizeof(Record_t) * num_records);
    return 0;	
}

int read_records(const char *input_filename, Record_t *records, const size_t num_records) {

    //check for NULL input_filename
    if(input_filename == NULL){
        return -1;
    }
    //check for NULL records 
    if(records == NULL){
        return -1;
    }
    //check for zero num_records 
    if(num_records == 0){
        return -1;
    }

    int fd = open(input_filename, O_RDONLY);
    if(fd == -1){
        return -2; //file could not be opened
    }

    ssize_t data_read = 0;
    for (size_t i = 0; i < num_records; ++i) {
        data_read = read(fd,&records[i], sizeof(Record_t));
        //check for too large num_records 
        if(num_records >= 200){
            data_read = -1;
        }
        if(data_read == -1){
            return -3; //read unsuccessful
        }
    }
    return 0;
}

int create_record(Record_t **new_record, const char* name, int age)
{
    //check to see if new_record is initialized to NULL
    if(*new_record != NULL){
        return -1;
    }
    //check for NULL name 
    if(name == NULL){
        return -1;
    }
    //check for name restriction 
    if(strlen(name) > 49){
        return -1;
    }
    //check for bad name 
    if(strcmp(name, "\n") == 0){
        return -1;
    }
    //check for age restriction
    if(age < 1 || age > 200){
        return -1;
    }
    *new_record = (Record_t*) malloc(sizeof(Record_t));
    //check for unsuccessful allocation 
    if(*new_record == NULL){
        return -2;
    }

    memcpy((*new_record)->name,name,sizeof(char) * strlen(name));
    (*new_record)->name[MAX_NAME_LEN - 1] = 0;	
    (*new_record)->age = age;
    return 0;

}
