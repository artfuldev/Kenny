/*
Kenny is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Kenny is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Kenny.  If not, see <http://www.gnu.org/licenses/>.
*/

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