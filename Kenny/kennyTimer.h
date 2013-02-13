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

#ifndef KENNY_TIMER_H
#define KENNY_TIMER_H
 
#include <sys/timeb.h>
#include "kennyDefs.h"
 
struct Timer
{
	U64   startTime;   
	U64   stopTime;    
	U64   currentTime;
	U64   stopTimeDelta;
	timeb startBuffer;   
	timeb stopBuffer;   
	timeb currentBuffer;
	BOOLTYPE running;  
 
	void init();               // start the timer
	void stop();               // stop the timer
	void reset();              // reset the timer
	void display();                   // display time in seconds with 2 decimals
	void displayhms();         // display time in hh:mm:ss.dd
	U64 getms();               // return time in milliseconds
	U64 getsysms();         // return system time
	Timer();
};
 
 
#endif