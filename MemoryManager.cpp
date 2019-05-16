//
//  MemoryManager.cpp
//  VMM
//
//  Created by Matthew Mikulka on 4/28/19.
//  Copyright ? 2019 Matthew Mikulka. All rights reserved.
//

#include "MemoryManager.hpp"

enum PRA_decision { FIFO_, LRU_ };

MemoryManager::MemoryManager() // constructor
{
	for (int i = 0; i < RAM_SIZE; ++i)
	{
		freeFrames.push(i);
	}
}

void MemoryManager::pageIn(Word& addr) // puting the page in mem man
{
	Word pageNum = addr;
	BackingStore back;
	char* item;
	item = back.read(addr);

	//PRA_decision decision = FIFO_;

	PRA *pra;
	if (FIFO_ == PRA_DECISION) // this is the thing tHAT TELLS US WHAT THE DECISIONS ARE
	{
		pra = new FIFO();
	}
	else
	{
		pra = new LRU();
	}
	unsigned frameNum = 0;
	if (freeFrames.size() > 0)
	{
		frameNum = freeFrames.front(); // POP THE FREE RFAMES
		freeFrames.pop();
	}
	else {
		frameNum = pra->select_frame(0);
	}
	pra->replace(frameNum, 0); // this is where we call relpace 
	MMU mmu;
	mmu.addFrame(item, frameNum);
	PCB::addFrame(pageNum, frameNum);
}

//unsigned char MemoryManager::read(Address& addr)
//{
//	MMU memManagerUnit;
//	try
//	{
//		unsigned char data;
//		data = memManagerUnit.read(addr);
//		return data;
//	}
//	catch (MMU::PageFault p )
//	{
//		pageIn(p.pageNumber_);
//		unsigned char data;
//		data = memManagerUnit.read(addr);
//		return data;
//	}
//}

std::queue<unsigned> MemoryManager::freeFrames; // this is the free fames queue

/*
TODO:

Add PRA to pageIn
*/

/*void MemoryManager::read(Address & pageNumber)
{

}*/
