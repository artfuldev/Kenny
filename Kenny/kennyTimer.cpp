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

#include "kennyExtInclude.h"
 
#pragma warning (disable: 4244)
 
Timer::Timer()
{
       running       = false;
       startTime     = 0;
       stopTime      = 0;
       stopTimeDelta = 0;
}
 
void Timer::init()
{
       if (!running)
       {
              running = true;
              ftime(&startBuffer);
              startTime = startBuffer.time * 1000 + startBuffer.millitm + stopTimeDelta;
       }
       return;
}
 
void Timer::stop()
{
       if (running)
       {
              running = false;
              ftime(&stopBuffer);
              stopTime = stopBuffer.time * 1000 + stopBuffer.millitm;
              stopTimeDelta = startTime - stopTime;
       }
       return;
}
 
void Timer::reset()
{
       if (running)
       {
              ftime(&startBuffer);
              startTime = startBuffer.time * 1000 + startBuffer.millitm;
       }
       else
       {
              startTime = stopTime;
              stopTimeDelta = 0;
       }
       return;
}
 
void Timer::display()
{
       if (running)
       {
              ftime(&currentBuffer);
              currentTime = currentBuffer.time * 1000 + currentBuffer.millitm;
              printf("%6.2f", (currentTime - startTime)/1000.0);
       }
       else
              printf("%6.2f", (stopTime - startTime)/1000.0);
       return;
}
 
void Timer::displayhms()
{
       int hh, mm, ss;
       if (running)
       {
              ftime(&currentBuffer);
              currentTime = currentBuffer.time * 1000 + currentBuffer.millitm;
              hh = (currentTime - startTime)/1000/3600;
              mm = ((currentTime - startTime)-hh*3600000)/1000/60;
              ss = ((currentTime - startTime)-hh*3600000-mm*60000)/1000;
              printf("%02d:%02d:%02d", hh, mm, ss);
       }
       else
       {
              hh = (stopTime - startTime)/1000/3600;
              mm = ((stopTime - startTime)-hh*3600000)/1000/60;
              ss = ((stopTime - startTime)-hh*3600000-mm*60000)/1000;
              printf("%02d:%02d:%02d", hh, mm, ss);
       }
       return;
}
 
U64 Timer::getms()
{
       if (running)
       {
              ftime(&currentBuffer);
              currentTime = currentBuffer.time * 1000 + currentBuffer.millitm;
              return (currentTime - startTime) ;
       }
       else
              return (stopTime - startTime);
}
 
U64 Timer::getsysms()
{
       ftime(&currentBuffer);
       return (currentBuffer.time * 1000 + currentBuffer.millitm);
}