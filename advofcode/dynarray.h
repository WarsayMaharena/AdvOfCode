#ifndef __INT_DYN_ARRAY__
#define __INT_DYN_ARRAY__

struct Int_Dyn_Array{
    int *ptr;
    int size;
    int capacity;
};

struct Int_Dyn_Array init_Int_Dyn_array(int capacity);

void int_Append_Element(struct Int_Dyn_Array *d_array, int element);

#endif