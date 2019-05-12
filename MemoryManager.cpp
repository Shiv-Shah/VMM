//
//  MemoryManager.cpp
//  VMM
//
//  Created by Matthew Mikulka on 4/28/19.
//  Copyright ? 2019 Matthew Mikulka. All rights reserved.
//

#include "MemoryManager.hpp"

enum PRA_decision{FIFO_, LRU_};

MemoryManager::MemoryManager()
{
	for (int i = 0; i < RAM_SIZE; ++i)
	{
		freeFrames.push(i);
	}
}

void MemoryManager::pageIn(Word & addr)
{
	Word pageNum = addr;
	BackingStore back;
	char * item;
	item = back.read(addr);

    //PRA_decision decision = FIFO_;

	unsigned frameNum = 0;
	if (freeFrames.size() > 0)
	{
		frameNum = freeFrames.front();
		freeFrames.pop();
    } else {
		PRA_decision decision = FIFO_;
		PRA* pra = nullptr;
		//PRA * pra;
        if(decision == FIFO_)
		{
            pra = new FIFO();
        }
		else

		{
            //pra = new LRU();
    }
		frameNum = pra->select_frame(0);


    }
	RAM ram;
	ram.addFrame(item, frameNum);
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

std::queue<unsigned> MemoryManager::freeFrames;

/*
TODO:

Add PRA to pageIn
*/

/*void MemoryManager::read(Address & pageNumber)
{

}*/