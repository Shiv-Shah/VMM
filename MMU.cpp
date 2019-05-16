//
//  MMU.cpp
//
//

#include "MMU.hpp"
#include "PCB.hpp"
#include "RAM.hpp"
/*MMU MMU::instance()
{
	pageAccessCounts_ = 0;
	pageInFaults_ = 0;
	tlbAccessCount_ = 0;
	tlbFaults_ = 0;
	return *this; // dummy return
}*/

enum PRA_decision { FIFO_, LRU_ };

MMU::MMU()
{

}

void MMU::instance() // this is the instance of it
{
	/*pageAccessCounts_ = 0;
	pageInFaults_ = 0;
	tlbAccessCount_ = 0;
	tlbHits_ = 0;*/
	tlb_.pageNum.fill(-1);
	tlb_.FrameNum.fill(-1);
	//tlbCounter = 0;
}

void MMU::clearTLB() // this clears the tlb
{
	tlb_.pageNum.fill(-1);
	tlb_.FrameNum.fill(-1);
}

int MMU::pageAccesses() // this accesses the pages
{
	return pageAccessCounts_;
}

int MMU::pageFaults() // this prints the number of page faults
{
	return pageInFaults_;
}

int MMU::TLBAccesses() // this tells us the tlb accesss number
{
	return tlbAccessCount_;
}

int MMU::TLBHits() // tells us the number of tlb hits
{
	return tlbHits_;
}

unsigned char MMU::read(Address & addr) // translate address to info
{
	Word pageNum = addr.page(); // extract page number from address.
	unsigned char data = 0;
	unsigned frameNum;
	//see if pageNum is in TLB
	frameNum = tlb_search(pageNum);

	if (frameNum > RAM_CHECK_SIZE)
	{

		frameNum = PCB::findFrame(pageNum);
	}
	else
	{
		++tlbHits_;
	}
	if (frameNum > RAM_CHECK_SIZE)
		throw PageFault(pageNum);
	else if (frameNum <= RAM_CHECK_SIZE)
	{
		data = RAM::read(frameNum, addr);
		tlb_add(frameNum, pageNum.value_);//need frame number and pagenumber
		if (LRU_ == PRA_DECISION)
		{
			LRU lru;
			lru.update_usage(frameNum, 0); //update ram LRU array
		}
		++pageAccessCounts_;

	}
	return data;
}


void MMU::addFrame(char* item, uint32_t frameNum) // this affs the frame
	{
		RAM ram;
		ram.addFrame(item, frameNum);
	}

unsigned MMU::tlb_search(Word & pageNum) // does tlb search
{
	for (int i = 0; i < TLB_SIZE; ++i)
	{
		if (pageNum.value_ == tlb_.pageNum[i])
		{

			if (LRU_ == PRA_DECISION)
			{
				LRU lru;
				lru.update_usage(i, 101);
			}

			return tlb_.FrameNum[i];
		}
		++tlbAccessCount_;
		//stlbAccessCount_ = 0;
	}

	return 257;
}

void MMU::tlb_add(uint32_t frameNum, uint32_t pageNum) //
{
	uint32_t entry = tlbCounter;

	PRA * pra;
	//PRA_decision decision = FIFO_;

	if (FIFO_ == PRA_DECISION)
	{
		pra = new FIFO();
	}
	else
	{
		pra = new LRU();
	}
	if (tlbCounter >= 16)
	{
		entry = pra->select_frame(101);
	}

	tlb_.FrameNum[entry] = frameNum;
	tlb_.pageNum[entry] = pageNum;

	if (LRU_ == PRA_DECISION)
	{
		pra->replace(entry, 101);
	}
}

MMU::PageFault::PageFault(const Word & pn)
{
	++pageInFaults_;
	pageNumber_ = pn;
}

int MMU::pageAccessCounts_ = 0;
int MMU::pageInFaults_ = 0;
int MMU::tlbAccessCount_ = 0;
int MMU::tlbHits_ = 0;
TLB MMU::tlb_;
uint32_t MMU::tlbCounter = 0;
