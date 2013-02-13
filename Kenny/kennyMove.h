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

#ifndef KENNY_MOVE_H_
#define KENNY_MOVE_H_
 
#include "kennyDefs.h"
 
 
//  There are at least 3 different ways to store a move in max 32 bits
//  1) using shift & rank in an unsigned int                
//  2) using 4 unsigned chars, union-ed with an unsigned int
//  3) using C++ bitfields, union-ed with an unsigned int   
 
//  this is 1) using shift & rank in an unsigned int (32 bit):
struct Move                                  
{
	// from (6 bits)
	// tosq (6 bits)
	// piec (4 bits)
	// capt (4 bits)
	// prom (4 bits)
	int moveInt;
 
	void clear();
	void setFrom(unsigned int from);  
	void setTosq(unsigned int tosq);  
	void setPiec(unsigned int piec);  
	void setCapt(unsigned int capt);  
	void setProm(unsigned int prom); 
	unsigned int getFrom();  
	unsigned int getTosq();  
	unsigned int getPiec();  
	unsigned int getCapt();
	unsigned int getProm();  
	BOOLTYPE isWhitemove();
	BOOLTYPE isBlackmove();
	BOOLTYPE isCapture();
	BOOLTYPE isKingcaptured();
	BOOLTYPE isRookmove();
	BOOLTYPE isRookcaptured();
	BOOLTYPE isKingmove();
	BOOLTYPE isPawnmove();
	BOOLTYPE isPawnDoublemove();
	BOOLTYPE isEnpassant();
	BOOLTYPE isPromotion();
	BOOLTYPE isCastle();
	BOOLTYPE isCastleOO();
	BOOLTYPE isCastleOOO();
};
 
#endif