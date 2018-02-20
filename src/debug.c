#include "../include/debug.h"

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// protected function, that only this .c can use
int comparator_func(const void *a, const void *b) {
    return (*(uint8_t *)a - *(uint8_t *)b);
}

bool terrible_sort(uint16_t *data_array, const size_t value_count) {
    //check for null data array
    if(data_array == NULL){
        return false;
    }
    else if(value_count <= 0){ //check for 0 or less value count
        return false;
    }
    uint16_t *sorting_array = (uint16_t *)malloc(value_count * sizeof(uint16_t));
    for (size_t i = 0; i < value_count; ++i) {
        sorting_array[i] = data_array[i];
    }

    qsort(sorting_array, value_count, sizeof(uint16_t), comparator_func);

    bool sorted = true;
    for (size_t i = 0; i < value_count - 1; ++i) {
        // sorted &= sorting_array[i] < sorting_array[i + 1];
        if(sorting_array[i+1] < sorting_array[i]){
            sorted = false;
        }
    }

    if (sorted) {
        memcpy(data_array, sorting_array, sizeof(uint16_t) * value_count);
        free(sorting_array);
    }
    return true;
}

