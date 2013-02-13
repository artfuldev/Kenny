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

U64 perft(int ply, int depth)
{
 
       // Raw node count, up to depth, doing a full tree search.
       // perft is very similar to the search algorithm - instead of evaluating the leaves, we count them.
       //
       // Be carefull when calling this function with depths > 7, because it can take a very long
       // time before the result is returned: the average branching factor in chess is 35, so every
       // increment in depth will require 35x more computer time.
       //
       // perft is a good way of verifying correctness of the movegenerator and (un)makeMove,
       // because you can compare the results with published results for certain test positions.
       //
       // perft is also used to measure the performance of the move generator and (un)makeMove in terms
       // of speed, and to compare different implementations of generating, storing and (un)making moves.
 
       U64 retVal = 0;     
       int i;
 
       // count this node
       if (depth == 0)
       {
              #ifdef KENNY_DEBUG_EVAL
                     int before = board.eval();
                     board.mirror();
                     int after = board.eval();
                     board.mirror();
                     if (before != after)
                     {
                           std::cout << "evaluation is not symmetrical! " << before << std::endl;
                           for (int j = 0 ; j < board.endOfSearch ; j++)
                     {
                                  std::cout << j+1 << ". ";
                                  displayMove(board.gameLine[j].move);
                                  std::cout <<std::endl;
                           }
                           board.display();
                     }
              #endif
              return 1;
       }
 
       // generate moves from this position
       board.moveBufLen[ply+1] = movegen(board.moveBufLen[ply]);
 
       // loop over moves:
       for (i = board.moveBufLen[ply]; i < board.moveBufLen[ply+1]; i++)
       {
              makeMove(board.moveBuffer[i]);
              {
                     if (!isOtherKingAttacked())
                     {
                           // recursively call perft
                           retVal += perft(ply + 1, depth-1);
 
                           #ifdef KENNY_DEBUG_PERFT
                           if (depth == 1)
                           {
                                  if (board.moveBuffer[i].isCapture()) ICAPT++;
                                  if (board.moveBuffer[i].isEnpassant()) IEP++;
                                  if (board.moveBuffer[i].isPromotion()) IPROM++;
                                  if (board.moveBuffer[i].isCastleOO()) ICASTLOO++;
                                  if (board.moveBuffer[i].isCastleOOO()) ICASTLOOO++;
                                  if (isOwnKingAttacked()) ICHECK++;
                           }
                          #endif
                     }
              }
              unmakeMove(board.moveBuffer[i]);
       }
       return retVal;
}