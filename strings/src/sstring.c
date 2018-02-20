#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/sstring.h"

bool string_valid(const char *str, const size_t length)
{
    //check for null string
    if(str == NULL){
        return false;
    }

    //check if length is zero
    if(length == 0){
        return false;
    }

    //check for empty string
    int ret; //return value for strcmp()
    ret = strcmp(str, " ");
    if(ret == 0){
       // printf("Empty String.\n");
        return true;
    }

   
    //check if last charcter is null terminator 
    if(str[length-1] == '\0'){
	return true;
    }
    return false;
}

char *string_duplicate(const char *str, const size_t length)
{
    //check for NULL string
    if(str == NULL){
        return NULL;
    }

    //check if length is zero
    if(length == 0){
        return NULL;
    }

    char *duplicate;

    duplicate = (char *)malloc((length * sizeof(char)));

    return strcpy(duplicate, str);

}

bool string_equal(const char *str_a, const char *str_b, const size_t length)
{
    //check to see if str_a or str_b is NULL
    if(str_a == NULL || str_b == NULL){
        return false;
    }

    //check to see if length is zero
    if(length == 0){
        return false;
    }

    int ret; //return value for string compare
    ret = strncmp(str_a, str_b, length);

    if(ret == 0){
        return true;
    }
    else{
        return false;
    }
}

int string_length(const char *str, const size_t length)
{
    //check to see if string is NULL
    if(str == NULL){
        return -1;
    }

    //check if length is zero
    if(length == 0){
        return -1;
    }

    //strlen() return the length of the string up to but not the null terminator
    return strlen(str);
}

int string_tokenize(const char *str, const char *delims, const size_t str_length, char **tokens, const size_t max_token_length, const size_t requested_tokens)
{
/*
    //check for NULL string
    if(str == NULL){
        return 0;
    }

    //check for NULL delims
    if(delims == NULL){
        return 0;
    }

    //check for zero str_length
    if(str_length == 0){
        return 0;
    }

    //check for NULL tokens
    if(tokens == NULL){
        return 0;
    }

    //check for zero token requests
    if(requested_tokens == 0){
        return 0;
    }

    //check for zero token length
    if(max_token_length == 0){
        return 0;
    }

   int i; //counter

    char *str1 = NULL;
    strcpy(str1, str);

    *tokens = strtok(str1, delims);

    while(tokens+i != NULL){
        i++;
        *tokens = strtok(NULL, delims);
    }

    int numTokens;

    while(tokens+i != NULL){
        i++;
        numTokens++;
    }

    if(numTokens == requested_tokens){
        return numTokens;
    }
    else{
        return -1;
    }
*/
return 0;
}

bool string_to_int(const char *str, int *converted_value)
{
    //check for NULL string
    if(str == NULL){
        return false;
    }

    //check for NULL value
    if(converted_value == NULL){
        return false;
    }

    *converted_value = atoi(str);
    if(*converted_value <= 0){
	*converted_value = 0;
	return false;
    }
    return true;
}

