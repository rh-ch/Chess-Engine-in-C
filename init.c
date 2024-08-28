#include "defns.h"
#include "stdlib.h"

#define rand_6((U64)rand() + \
               (U64)rand() << 15+\
               (U64)rand() << 30+\
               (U64)rand() << 45+\
               (U64)rand() & 0xf ) << 60;

int SQ120TOSQ64[BRD_SQ_NUM];
int SQ64TO120[64];

U64 SetMask[64];
U64 ClearMask[64];

U64 PieceKeys[13][120];
U64 SideKey;
U64 castleKeys[16];

void initbitmask(){
    int index = 0;
    for(index = 0; index < 64; index++){
        SetMask[index] = 0ULL;
        ClearMask[index] = 0ULL;
    }
    for(index = 0; index < 64; index++){
        SetMask[index] |= (1ULL << index);
        ClearMask[index] = ~SetMask[index];
    }
}

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
                elements of the array*/
                SQ120TOSQ64[sq] = sq64;/*creating a 0-64 index in the 120 board
                in the actual board excluding borders to represent the chess board*/
                sq64++;//using this to place the values of 0-64 in the places of array using sq64 vals
        }
    }
}

void AllInit(){
    InitSQ120TO64();
}