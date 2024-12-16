#include "dynarray.h"
#include<stdio.h>
#include<stdlib.h>

struct Int_Dyn_Array init_Int_Dyn_array(int capacity){
    struct Int_Dyn_Array array;
    int *ptr_array = malloc((capacity)*sizeof(int));
    array.ptr=ptr_array;
    array.size=0;
    array.capacity=capacity;
    
    return array;
}

void int_Append_Element(struct Int_Dyn_Array *d_array, int element){
    if((d_array->size+1)<d_array->capacity){
        d_array->ptr[d_array->size]=element;
        d_array->size++;
        
    } else {
        d_array->capacity+=10;
        d_array->ptr = realloc(d_array->ptr, d_array->capacity * sizeof(int)); 
        d_array->ptr[d_array->size]=element;
        d_array->size++;
    }
}