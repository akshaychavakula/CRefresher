#include "../include/bitmap.h"

// data is an array of uint8_t and needs to be allocated in bitmap_create
//      and used in the remaining bitmap functions. You will use data for any bit operations and bit logic
// bit_count the number of requested bits, set in bitmap_create from n_bits
// byte_count the total number of bytes the data contains, set in bitmap_create

#define SetBit(A, k)    (A[(k/8)] |= (1 << (k%8)))
#define ResetBit(A, k)  ( A[(k/8)] &= ~(1 << (k%8)))

bitmap_t *bitmap_create(size_t n_bits)
{

    //check for zero bit value
    if(n_bits == 0){
        return NULL;
    }

    size_t n_bytes = n_bits / 8;
    if(0 != n_bits % 8){
        n_bytes++;
    }

    bitmap_t *bmap = (bitmap_t *)malloc(sizeof(bitmap_t));
    bmap->data = (uint8_t*)malloc(n_bytes);

    int i = 0;
    for(i = 0; i < n_bytes; i++){
        bmap->data[i] = 0;
    }

    bmap->bit_count = n_bits;
    bmap->byte_count = n_bytes;

    return bmap;

}

bool bitmap_set(bitmap_t *const bitmap, const size_t bit)
{
    //check for null bitmap
    if(bitmap == NULL){
        return false;
    }

    //check for neg bits
    if(bit < 0){
        return false;
    }

    //check for bit > bit_count
    if(bit > bitmap->bit_count){
        return false;
    }

    SetBit(bitmap->data, bit);

    return true;

}

bool bitmap_reset(bitmap_t *const bitmap, const size_t bit)
{
    //check for negative bit value
    if(bit < 0){
        return false;
    }
    //check for bad bit object
    if(bitmap == NULL){
        return false;
    }
    //check for too large bit
    if(bit > bitmap->bit_count){
        return false;
    }

    ResetBit(bitmap->data, bit);
    return true;

}

bool bitmap_test(const bitmap_t *const bitmap, const size_t bit)
{
    //check for NULL bitmap
    if(bitmap == NULL){
        return false;
    }

    //check for neg bit
    if(bit < 0){
        return false;
    }

    //check for large bit count
    if(bit > bitmap->bit_count){
        return false;
    }

    int byte;
    int state;

    byte = bitmap->data[bit/8];
    state = 1 << bit % 8;
    return (byte & state);

}

size_t bitmap_ffs(const bitmap_t *const bitmap)
{
    return SIZE_MAX;

}

size_t bitmap_ffz(const bitmap_t *const bitmap)
{
    return SIZE_MAX;

}

bool bitmap_destroy(bitmap_t *bitmap)
{
    if(bitmap == NULL){
        return false;
    }
    else{
        free(bitmap);
        return true;
    }

}
