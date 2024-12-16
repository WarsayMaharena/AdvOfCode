#include <string.h>
#include <stdio.h>
#include <ctype.h>
//191137211 too high
//173250883 too low
//187608603 too low

int check_for_mul(FILE *fptr, char c);
int check_for_args(FILE* fptr);


int main(){
    FILE *fptr = fopen("file.txt", "r");
    char c;
    int res = 0;
    // check the result of opening the file for errors
    if (fptr == NULL)
    {
        // perror displays the system error message after whatever text is in the parentheses
        perror("Error: ");
        return (-1);
    }
    int mulp_counter = 0;
    int mulp_helper = 0;
    int arg1=0, arg2=0;
    long result=0;
    while ((c = fgetc(fptr)) != EOF) {
        printf("%c",c);
        if(1==check_for_mul(fptr, c)){
            mulp_counter++;
            mulp_helper=1;
       }
       //printf("6%c",c);
       if(mulp_helper==1){
            mulp_helper=0;
            result= result+check_for_args(fptr);
       }
    }
    printf("mullcounter: %d\n", mulp_counter);
    printf("res: %ld\n",result);
    return 0;
}

int check_for_mul(FILE *fptr, char c){
    char u , l, p;
    //printf("2%c",c);
    if ('m' == c){
        u=fgetc(fptr);
        if(u!='u'){
            printf("%c",u);
        }
        if ('u' == u){
            l = fgetc(fptr);
            if(l!='l'){
                printf("%c",l);
            }
            if('l' == l){
                p = fgetc(fptr);
                if(p!='('){
                    printf("%c",p);
                }
 
                if('(' == p){
                    //printf("5%c",p);
                    return 1;

                } 
            }
            
        }
    }
    return -1;

}

int check_for_args(FILE* fptr){
    printf("ul(");
    char c = fgetc(fptr);
    char args1[]="abc";
    char args2[]="abc";
    char cattable1[]="a\0";
    char cattable2[]="a\0";
    strcpy(args1,"");
    strcpy(args2,"");
    //printf("error1\n");
    if(c==','){
        c=fgetc(fptr);
        return 0;
    } else {
        //printf("error13\n");
        for(int i = 0; i<4; i++){
            printf("%c",c);
            if (0!=isdigit(c) && i == 3){
                c =fgetc(fptr);
                return 0;
            } else if(0!=isdigit(c)){
                cattable1[0]=c;
                //printf("error15\n");
                strcat(args1,cattable1);
                //printf("error16\n");
                c =fgetc(fptr);
            } else if (c == ','){
                c=fgetc(fptr);
                if(c=='m'){
                    fseek(fptr, -1, SEEK_CUR);
                    return 0;
                }
                break;
            } else{
                return 0;
            }
        }
        if(c==','){
            return 0;
        }
        //%&/&&&mul(16,87mul(16,18)
        for(int i = 0; i<4; i++){
            printf("%c",c);
            if (0!=isdigit(c) && i == 3){
                c =fgetc(fptr);
                return 0;
            }else if(0!=isdigit(c)){
                cattable2[0]=c;
                strcat(args2,cattable2);
                c = fgetc(fptr);
            } else if (c == ')'){
                if(c=='m'){
                    fseek(fptr, -1, SEEK_CUR);
                }
                break;
            } else if (c == 'm'){
                
                fseek(fptr, -1, SEEK_CUR);
                return 0;
            } else {
                return 0;
            }
        }
        //mul(161,40)
    int len1 = strlen(args1);
    int len2 = strlen(args2);
    int result1=0, result2=0;
	for(int i=0; i<len1; i++){
		result1 = result1 * 10 + ( args1[i] - '0' );
	}
	for(int i=0; i<len2; i++){
		result2 = result2 * 10 + ( args2[i] - '0' );
	}
        //printf("mul(%d,%d)", result1, result2);
        return (result1*result2);
    }
    
    
}