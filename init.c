#include "defns.h"

int SQ120TOSQ64[BRD_SQ_NUM];
int SQ64TO120[64];

void InitSQ120TO64(){
    int i = 0;
    int file = FILE_A;
    int rank = RANK_1;
    int sq = A1;
    int sq64 = 0;
    for(i = 0; i < BRD_SQ_NUM; ++i){
        SQ120TOSQ64[i]=65;//failsafe, borders will have value 65
    }
    for(i = 0; i < 64; ++i){
        SQ64TO120[i]=120;//failsafe, 120 is not placed anywhere
    }
    for(rank = RANK_1; rank <= RANK_8; ++rank){
        for(file = FILE_A; file <= FILE_H; ++file){//stepping through each index in the array
                sq =  FRTOSQ(file,rank);
                SQ64TO120[sq64] = sq;/*placing indices of 120 board(FRTOSQ) in all 64 
                elements of the array; this will allow us to directly access the board that the
                pieces will move in*/
                SQ120TOSQ64[sq] = sq64;/*creating a 0-64 index in the 120 board
                in the actual board excluding borders to represent the chess board*/
                sq64++;
        }
    }
}

void AllInit(){
    InitSQ120TO64();
}