#include<stdio.h>
#include<stdlib.h>
#include "dynarray.h"

int check_for_delimiter(FILE* fptr, struct Int_Dyn_Array *d1array, struct Int_Dyn_Array *d2array);
int check_for_delimiter_comma(FILE* fptr, struct Int_Dyn_Array *d1array, struct Int_Dyn_Array *d2array, struct Int_Dyn_Array *d3array, struct Int_Dyn_Array *d4array);
int solve_puzzle(FILE* fptr, struct Int_Dyn_Array *d1array, struct Int_Dyn_Array *d2array, struct Int_Dyn_Array *d3array, struct Int_Dyn_Array *d4array);

int main(){

    char c;
    char c_before='a';
    int counter=0;

    struct Int_Dyn_Array d1_array = init_Int_Dyn_array(10);
    struct Int_Dyn_Array d2_array = init_Int_Dyn_array(10);

    struct Int_Dyn_Array d3_array = init_Int_Dyn_array(10);
    struct Int_Dyn_Array d4_array = init_Int_Dyn_array(10);
    int cfd_flag=0;
    FILE *file = fopen("example1.txt", "r");
    printf("hello");
    if(file == NULL){
        printf("file doesnt exist");
    }

    while(1)
    {
        if (cfd_flag == 0) {
            cfd_flag = check_for_delimiter(file, &d1_array, &d2_array);
            cfd_flag=1;
        }
        
        if (cfd_flag == 1){
            
            check_for_delimiter_comma(file, &d1_array, &d2_array, &d3_array, &d4_array);
            printf("\n");
            break;
        } 

        solve_puzzle(file, &d1_array, &d2_array, &d3_array, &d4_array);


        
    }

    //debug

    for(int i = 0; i < d1_array.size; i++){
        printf("%d|",d1_array.ptr[i]);
        printf("%d\n",d2_array.ptr[i]);

    }

    for(int i = 0; i < d3_array.size; i++){
        printf("%d ",d3_array.ptr[i]);

    }

    for(int i = 0; i < d4_array.size; i++){
        printf("%d ",d4_array.ptr[i]);

    }

    printf("\n");
    

    return 0;
}

int solve_puzzle(FILE* fptr, struct Int_Dyn_Array *d1array, struct Int_Dyn_Array *d2array, struct Int_Dyn_Array *d3array, struct Int_Dyn_Array *d4array){
    int counter=0;
    int incr = 0;
    int numb_upd=0;
    int numb_d1array_index=0;
    int numb_d2array_index=0;
    int numb_d3array_index=0;
    int numb_d4array_index=0;

    int numb_d1array=0;
    int numb_d2array=0;
    int numb_d3array=0;
    int numb_d4array=0;
    while(1){
        // d1array->ptr[numb_d1array_index];
        // d2array->ptr[numb_d2array_index];
        // d3array->ptr[numb_d3array_index];
        // d4array->ptr[numb_d4array_index];

        



    }


    return 1;
}


int check_for_delimiter_comma(FILE* fptr, struct Int_Dyn_Array *d1array, struct Int_Dyn_Array *d2array, struct Int_Dyn_Array *d3array, struct Int_Dyn_Array *d4array){
    char c, c_before='a';
    char integer[10]; 
    int size = 0;
    int number;
    int counter=0;
    printf("hello\n");
    printf("inhere\n");
    while(c != EOF){
        c_before = c;
        c = fgetc(fptr);
        integer[size]=c;
        
        if(c == EOF){
            number = atoi(integer);
            counter++;
            printf("%d ",number);
            int_Append_Element(d3array,number);
            int_Append_Element(d4array,counter);
            break;
        }
        size++;
        if (c == ','){
            counter++;
            integer[size-1]='\0';

            number = atoi(integer);
            printf("%d ",number);
            int_Append_Element(d3array,number);
            //printf("%d|",number);
            size=0;
        } else if (c == '\n'){
            counter++;
            number = atoi(integer);
            printf("%d ",number);
            int_Append_Element(d3array,number);
            int_Append_Element(d4array,counter);
            //printf("%d|",number);
            size=0;
            counter=0;
            printf("\n");



        }

    }
    return 0;
}

int check_for_delimiter(FILE* fptr, struct Int_Dyn_Array *d1array, struct Int_Dyn_Array *d2array){
    char c, c_before='a';
    char integer[10];
    int size = 0;
    int number;
    
    printf("hello\n");
    while(c != EOF){
        c_before = c;
        c = fgetc(fptr);
        integer[size]=c;
        size++;
        
        //printf("current c: %c end\n current int: %s end\n",c,integer);
        
        if(c == c_before && c == '\n'){
            return 1;
        }
        else if (c == '|'){
            integer[size-1]='\0';
            number = atoi(integer);
            int_Append_Element(d1array,number);
            //printf("%d|",number);
            size=0;
        } else if (c == '\n'){
            integer[size-1]='\0';
            number = atoi(integer);
            int_Append_Element(d2array,number);
            //printf("%d\n",number);
            size=0;
        }
        
        
    }
    return 0;
}