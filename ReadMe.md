#Kenny
* Author: Kenshin Himura *(Sudarsan Balaji)*
* License: *GNU GPL v3 and CC-BY-NC-SA Licenses* (see gpl.txt and ccbyncsa.txt)
* Application Version: 0.1.1.0
* ReadMe Version: 1.4

##Description
Kenny is a Winboard/XBoard chess engine based on Winglet, an open source chess program. Winglet's full source code can be obtained from [Winglet](http://www.sluijten.com/winglet/source/index.htm).

Kenny is an advanced form of Winglet which plays better at some faster time levels like blitz chess or upto 20 minute games, but almost always loses against Winglet when the time controls are 40 minutes or more for each. These tests were run by setting up various tournamennts on the free Chess GUI Arena Version 3.0.
Kenny uses modified values for evaluation of various parameters, thus introducing almost an entirely new engine, because the evaluation function is the heart of a chess engine.

##Updates
* Now, Kenny can be downloaded from [sourceforge](https://www.sourceforge.net/p/kenny)!

##Visions
* Better board representation using fully object oriented programming using proper class heirarchy (probably in an entirely new repo)
* Modification of the evaluation function to a better one (pending some neural networks analyses on my side)
* History pruning implementation
* Killer Moves implementation
* Better Move-ordering and pruning of serach tree