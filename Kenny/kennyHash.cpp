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

void HashKeys::init()
{
	// initialize all random 64-bit numbers

	int i,j;
	time_t now;

	// use current time (in seconds) as random seed:
	srand((unsigned int)time(&now));

	for (i = 0; i < 64; i++)
	{
		ep[i] = rand64();
		for (j=0; j < 16; j++) keys[i][j] = rand64();
	}
	side = rand64();
	wk = rand64();
	wq = rand64();
	bk = rand64();
	bq = rand64();

	return;
}

U64 HashKeys::rand64()
{
	return rand()^((U64)rand()<<15)^((U64)rand()<<30)^((U64)rand()<<45)^((U64)rand()<<60);
}