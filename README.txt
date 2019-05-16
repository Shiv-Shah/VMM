


Team 1: Aedan Valle, Shiv shah, Mathew Mikulka



In order to choose the correct page replacement algorithm, 
In the constVars.hpp file, there’s a preprocessor directive 
Named PRA_DECISION. Chose the value from the following choices
To pick a page replacement algorithm, set PRA_DECISION to:
FIFO_
LRU_

Commands used to run:

g++ -g3 -o0 -std=c++17 -pedantic -Wall -Wold-style-cast -Wextra -Woverloaded-virtual -I./ -o VMManager main.cpp MMU.cpp BackingStore.cpp MemoryManager.cpp RAM.cpp Word.cpp PCB.cpp PRA.cpp FIFO.cpp LRU.cpp


	
./VMManager <addresses.txt 2>&1 |tee output.txt 
