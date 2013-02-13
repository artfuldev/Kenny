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

int Board::qsearch(int ply, int alpha, int beta)
{
	// quiescence search 

	int i, j, val;

	if (timedout) return 0;
	triangularLength[ply] = ply;
	if (isOwnKingAttacked()) return alphabetapvs(ply, 1, alpha, beta);
	val = board.eval();
	if (val >= beta) return val;
	if (val > alpha) alpha = val;

	// generate captures & promotions:
	// captgen returns a sorted move list
	moveBufLen[ply+1] = captgen(moveBufLen[ply]);
	for (i = moveBufLen[ply]; i < moveBufLen[ply+1]; i++)
	{
		makeMove(moveBuffer[i]);
		{
			if (!isOtherKingAttacked()) 
			{
				inodes++;
				if (--countdown <=0) readClockAndInput();
				val = -qsearch(ply+1, -beta, -alpha);
				unmakeMove(moveBuffer[i]);
				if (val >= beta) return val;
				if (val > alpha)
				{
					alpha = val;
					triangularArray[ply][ply] = moveBuffer[i];
					for (j = ply + 1; j < triangularLength[ply+1]; j++) 
					{
						triangularArray[ply][j] = triangularArray[ply+1][j];
					}
					triangularLength[ply] = triangularLength[ply+1];
				}
			}
			else unmakeMove(moveBuffer[i]);
		}
	}
	return alpha;
}