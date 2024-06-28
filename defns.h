#ifndef DEFNS_H
#define DEFNS_H

typedef unsigned long long int U64;

#define NAME "CHOCO 0.1"
#define BRD_SQ_NUM 120
#define MAX_GAME_MOVES 2048

enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK };
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };

enum { WHITE, BLACK, BOTH };

enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};//board positions with corresponding indices on 120 board

enum { FALSE, TRUE };

enum { WKCA=1, WQCA=2, BKCA=4, BQCA=8 }; /* stored in a single integer castleperm
which is used to determine the castling permissions, for example in the integer
1 0 0 1 first bit used for first enum const(indicating white king can castle) and so on */

typedef struct {
    int move;
    int castleperm;
    int ep;
    int fifty;
    U64 poskey;
} struct_undo;//to maintain history

typedef struct {

    int pieces[BRD_SQ_NUM];//120 integer array consists of complete board with borders
    U64 pawns[3];/*01000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
    pawn placed at A1*/
    int KingSq[2];//placement of kings both white and black
    int side;
    int ep;//en passant square
    int fifty;//fifty moves rule
    int ply;//how many half moves
    int catply;//total game- how many half moves(history)
    U64 poskey;//position
    int pcnum[13];//piece number, to know which piece
    int bigpc[3];//anything that isnt a pawn
    int majpc[3];//rooks and queens
    int minpc[3];//bishops and knights
    int castleperm;
    struct_undo history[MAX_GAME_MOVES];//stores every field in struct undo upto value max moves
    int plist[13][10];//piece list: plist[wK][0] plist[wK][1]... specifies which piece and how many
} struct_board ;

//MACROS
#define FRTOSQ(f,r) ( (21 + (f)) + ((r) * 10) )//returns equivalent square index from 120 int array
//GLOBALS
extern int SQ120TOSQ64[BRD_SQ_NUM];
extern int SQ64TO120[64];
//FUNCTIONS
extern void AllInit();
extern void InitSQ120TO64();
//INIT.C

#endif