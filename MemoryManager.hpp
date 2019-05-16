//
//  MemoryManager.hpp
//  VMM
//
//  Created by Matthew Mikulka on 4/28/19.
//  Copyright ? 2019 Matthew Mikulka. All rights reserved.
//

#ifndef MemoryManager_hpp
#define MemoryManager_hpp

#include <stdio.h>
#include <queue>
#include "Word.hpp"
#include "BackingStore.hpp"
#include "RAM.hpp"
#include "PCB.hpp"
#include "MMU.hpp"
#include "FIFO.hpp"
#include "LRU.hpp"
#include "constVars.hpp"

class MemoryManager
{
public:
	MemoryManager();
	void pageIn(Word& addr);
	//void pageIn(Address & item);
	unsigned char read(Address& pageNumber);
private:
	static std::queue<unsigned> freeFrames;
};

#endif /* MemoryManager_hpp */
