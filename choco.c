#include "stdio.h"
#include "defns.h"
int main(){

    AllInit();
    int i = 0;
    for(i = 0; i < BRD_SQ_NUM; ++i){
        if(i%10==0) printf("\n");
        printf("%5d",SQ120TOSQ64[i]);
    }

    printf("\n");
    printf("\n");

    for(i = 0; i < 64; ++i){
        if(i%8==0) printf("\n");
        printf("%5d",SQ64TO120[i]);
    }

    return 0;
}