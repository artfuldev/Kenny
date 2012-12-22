Kenny v0.1.1.0
by Kenshin Himura, governed by GNU GPL and CC-BY-NC-SA Licenses (see gpl.txt and ccbyncsa.txt)
ReadMe Version 1.1

Kenny is a Winboard/XBoard chess engine based on Winglet, an open source chess program. Winglet's full source code can be obtained from [http://www.sluijten.com/winglet/source/index.htm].

Kenny is an advanced form of Winglet which plays better at some faster time levels like blitz chess or upto 20 minute games, but almost always loses against Winglet when the time controls are 40 minutes or more for each. These tests were run by setting up various tournamennts on the free Chess GUI Arena Version 3.0

Kenny uses modified values for evaluation of various parameters, thus introducing almost an entirely new engine, because the evaluation function is the heart of a chess engine.

Visions:
->Better board representation using fully object oriented programming using proper class heirarchy
->Modification of the evaluation function to a better one (pending some neural networks analyses on my side)