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

void test(char *filename)
{
	// runs a testsuite with current depth and time search parameters

	int i, file;
	U64 inodestotal;
	U64 timetotal;
	Timer totaltime;
	std::string logfile (filename);

	totaltime.init();
	inodestotal = 0;
	std::cout << "START OF TEST:" << std::endl;
	std::cout << "MAX SEARCH DEPTH = " << board.searchDepth << std::endl;
	std::cout << "MAX SEARCH TIME = " << board.maxTime/1000 << "s" << std::endl;

	// construct logfile name
	logfile.replace(logfile.find("."),logfile.length(),".log");   

	// redirect stdout to the log file
	TOCONSOLE = 0;
	file = _dup(_fileno(stdout));    // create a file descriptor for stdout
	freopen(logfile.c_str(),"w",stdout);  

	std::cout << std::endl << std::endl << "+++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "START OF TEST:" << std::endl;
	std::cout << "MAX SEARCH DEPTH = " << board.searchDepth << std::endl;
	std::cout << "MAX SEARCH TIME = " << board.maxTime/1000 << "s" << std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++++++++" << std::endl;

	i = 1;
	while (readFen(filename, i))
	{

		// write progress to console:
	    _dup2(file ,_fileno(stdout));   
		_close(file);
		printf("KENNY> position #%d\n", i);
		file = _dup(_fileno(stdout));
		freopen(logfile.c_str(),"a",stdout);  

		board.display();
		board.think();
		inodestotal += board.inodes;
		i++;
	}

	timetotal = totaltime.getms();
	std::cout << std::endl << std::endl << "+++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "SUMMARY:" << std::endl;
	std::cout << "TOTAL TIME SEARCHED  = " << timetotal << " ms" << std::endl;
	std::cout << "TOTAL NODES SEARCHED = " << inodestotal << std::endl;
	std::cout << "AVG SEARCH SPEED     = " << inodestotal/timetotal << " knps" << std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++++++++" << std::endl;

    _dup2(file ,_fileno(stdout));   // reassign file descriptor
	_close(file);
	TOCONSOLE = 1;

	return; 
}