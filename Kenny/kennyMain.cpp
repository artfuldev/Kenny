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

// Kenny.cpp : Defines the entry point for the console application.
//
#include "kennyInclude.h"

int main(int argc, char *argv[])
{
	int i;
	
	signal(SIGINT, SIG_IGN); 
	setbuf(stdin, NULL);

	// windows only:
	SYSTEM_INFO sysinfo;

	std::cout << KENNY_PROG_VERSION << std::endl;
	#ifdef KENNY_DEBUG_PERFT
		std::cout << "KENNY_DEBUG_PERFT defined" << std::endl;
	#endif
	#ifdef KENNY_DEBUG_MOVES
		std::cout << "KENNY_DEBUG_MOVES defined" << std::endl;
	#endif
	#ifdef KENNY_VERBOSE_EVAL
		std::cout << "KENNY_VERBOSE_EVAL defined" << std::endl;
	#endif
	#ifdef KENNY_DEBUG_EVAL
		std::cout << "KENNY_DEBUG_EVAL defined" << std::endl;
	#endif
	#ifdef KENNY_VERBOSE_SEE
		std::cout << "KENNY_VERBOSE_SEE defined" << std::endl;
	#endif
	#ifdef KENNY_DEBUG_WINBOARD
		std::cout << "KENNY_DEBUG_WINBOARD defined" << std::endl;
	#endif
	#ifdef KENNY_CUSTOM_VALUES
		std::cout << "KENNY_CUSTOM_VALUES defined" << std::endl;
	#endif
	#ifdef KENNY_CUSTOM_POSVALS
		std::cout << "KENNY_CUSTOM_VALUES defined" << std::endl;
	#endif
	#ifdef KENNY_CUSTOM_PSTABLES
		std::cout << "KENNY_CUSTOM_PSTABLES defined" << std::endl;
	#endif
	#ifdef KENNY_CUSTOM_ENDGAME
		std::cout << "KENNY_CUSTOM_ENDGAME defined" << std::endl;
	#endif

	dataInit();
	board.init();

	// windows only:
	GetSystemInfo(&sysinfo);
    if (sysinfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL)
		std::cout << "Version: X86, ";
	else if (sysinfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64)
		std::cout << "Version: IA64, ";
	else if (sysinfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
		std::cout << "Version: X64, ";
	std::cout << sysinfo.dwNumberOfProcessors << " CPU's (1 CPU used)" << std::endl;
	std::cout << "Search structure = " << sizeof(board)/1024 << "kB" << std::endl;

	// read the initialization file:
	strcpy(PATHNAME, argv[0]);
	strcpy(INIFILE, "KENNYx.ini");  // default name
	// check command-line to see if we need to use another ini-file:
	// usage: "KENNYx.exe i=somefile.ini"
	for (i = 1; i < argc; i++) 
	{
		if (!strncmp(argv[i], "i=", 2)) sscanf_s(argv[i]+2,"%s", INIFILE);
	}
	readIniFile();

	std::cout <<  "'help' displays a list of commands" << std::endl;
	commands();

	return 0;
}