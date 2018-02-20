#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../include/sys_prog.h"

// LOOK INTO OPEN, READ, WRITE, CLOSE, FSTAT/STAT, LSEEK
// GOOGLE FOR ENDIANESS HELP

bool bulk_read(const char *input_filename, void *dst, const size_t offset, const size_t dst_size)
{
    //check for NULL filename
    if(input_filename == NULL){
        return false;
    }

    //check for NULL filename
    int ret0;
    ret0 = strcmp(input_filename, "NULL");
    if(ret0 == 0){
        return false;
    }

    //check for bad input filename
    int ret;
    ret = strcmp(input_filename, " ");
    if(ret == 0){
        return false;
    }

    //check for bad filename
    int ret1;
    ret1 = strcmp(input_filename, "\n");
    if(ret1 == 0){
        return false;
    }

    //check for bad filename
    int ret2;
    ret2 = strcmp(input_filename, "\0");
    if(ret2 == 0){
        return false;
    }

    //check for NULL dst
    if(dst == NULL){
        return false;
    }

    //check for bad offset
    if(offset > dst_size){
        return false;
    }

    //check for 0 dst_size
    if(dst_size == 0){
        return false;
    }

    int fd = open(input_filename, O_RDONLY); //open file through file path to read
    if(fd == -1){
        return false; //file does not exist
    }
    int readret; //read return variable
    lseek(fd, offset, SEEK_SET); //set the offset (where to start reading from file)
    readret = read(fd, dst, dst_size);
    if(readret == -1){
        return false; //read was unsuccessful
    }
    else{
        return true; //read was successful
    }
    close(fd); //close file descriptor
}

bool bulk_write(const void *src, const char *output_filename, const size_t offset, const size_t src_size)
{
    //check for NULL filename
    if(output_filename == NULL){
        return false;
    }
    int ret;
    ret = strcmp(output_filename, "NULL");
    if(ret == 0){
        return false;
    }

    //check for bad filename
    int ret1;
    ret1 = strcmp(output_filename, "\n");
    if(ret1 == 0){
        return false;
    }

    //check for bad filename
    int ret2;
    ret2 = strcmp(output_filename, "\0");
    if(ret2 == 0){
        return false;
    }

    //check for bad filename
    int ret3;
    ret3 = strcmp(output_filename, "");
    if(ret3 == 0){
        return false;
    }

    //check for null src
    if(src == NULL){
        return false;
    }
    int ret4;
    ret4 = strcmp(src, "NULL");
    if(ret4 == 0){
        return false;
    }

    //check for 0 src size
    if(src_size == 0){
        return false;
    }

    int fd = open(output_filename, O_WRONLY); //open file through file path to write
    if(fd == -1){
        return false; //file could not be opened
    }
    lseek(fd, offset, SEEK_SET);
    int writeret; //return variable for write()
    writeret = write(fd, src, src_size);
    if(writeret == -1){
        return false; //write was unsuccessful
    }
    else{
        return true; //write was successful
    }
    close(fd);
}

bool file_stat(const char *query_filename, struct stat *metadata)
{
    //check for NULL query_filename
    if(query_filename == NULL){
        return false;
    }
    int ret;
    ret = strcmp(query_filename, "NULL");
    if(ret == 0){
        return false;
    }

    int status; // status of stat
    status = stat(query_filename, metadata);
    if(status == -1){
        return false; //stat unsuccessful
    }
    else{
        return true;
    }
}

bool endianess_converter(uint32_t *src_data, uint32_t *dst_data, const size_t src_count)
{
    //check for NULL src_data
    if(src_data == NULL){
        return false;
    }

    //check for NULL dst_data
    if(dst_data == NULL){
        return false;
    }

    //check for zero src_count
    if(src_count == 0){
        return false;
    }

    uint32_t byte0, byte1, byte2, byte3;

    byte0 = (*src_data & 0x000000FF) >> 0 ;
    byte1 = (*src_data & 0x0000FF00) >> 8 ;
    byte2 = (*src_data & 0x00FF0000) >> 16 ;
    byte3 = (*src_data & 0xFF000000) >> 24 ;

    *dst_data = ((byte0 << 24) | (byte1 << 16) | (byte2 << 8) | (byte3 << 0));

    return true;


}

