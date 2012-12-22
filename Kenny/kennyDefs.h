#ifndef KENNY_DEFS_H

#define KENNY_DEFS_H

//Definitions
#define KENNY_PROG_VERSION "Kenny v0.1.1, by Kenshin Himura, Copyright 2012" //String Definition
//#define KENNY_DEBUG_PERFT
//#define KENNY_DEBUG_MOVES
//#define KENNY_VERBOSE_EVAL
//#define KENNY_VERBOSE_SEE
//#define KENNY_DEBUG_EVAL
//#define KENNY_DEBUG_WINBOARD
#define KENNY_CUSTOM_VALUES
//#define KENNY_CUSTOM_POSVALS
//#define KENNY_CUSTOM_PSTABLES
//#define KENNY_CUSTOM_ENDGAME

#define MAX_CMD_BUFF     256   // Console command input buffer
#define MAX_MOV_BUFF    4096   // Max number of moves that we can store (all plies)
#define MAX_PLY           64   // Max search depth
#define MAX_GAME_LINE   1024   // Max number of moves in the (game + search) line that we can store

typedef unsigned long long U64;
typedef unsigned long long BitMap;
typedef short SHORTINT;
typedef unsigned short USHORTINT;
typedef int BOOLTYPE;
 
#endif