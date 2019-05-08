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

MMU::MMU()
{
	pageAccessCounts_ = 0;
	pageInFaults_ = 0;
	tlbAccessCount_ = 0;
	tlbFaults_ = 0;
	tlb_.pageNum.fill(-1);
	tlb_.FrameNum.fill(-1);
}

void MMU::clearTLB()
{
	tlb_.pageNum.fill(-1);
	tlb_.FrameNum.fill(-1);
}

int MMU::pageAccesses()
{
	return pageAccessCounts_;
}

int MMU::pageFaults()
{
	return pageInFaults_;
}

int MMU::TLBAccesses()
{
	return tlbAccessCount_;
}

int MMU::TLBFaults()
{
	return tlbFaults_;
}

unsigned char MMU::read(Address &addr) // translate address to info
{
	Word pageNum = addr.page();
	unsigned char data;
	unsigned frameNum = PCB::findFrame(pageNum);
	if (frameNum <= 255)
	{
		data = RAM::read(frameNum, addr);
		++pageAccessCounts_;
	}
	else
	{
		MemoryManager mM;
		mM.pageIn(addr);
		frameNum = PCB::findFrame(pageNum);
		data = RAM::read(frameNum, addr);
		++pageInFaults_;
	}
	return data;
}
/*
TODO:

implement TLB
*/
