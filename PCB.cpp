
#include "PCB.hpp"
//#include "constVars.hpp"


PCB::PCB()
{

}

void PCB::addFrame(const Word& pageNumber, const unsigned& frameNum) // this adds the frame in pcb
{
	PageTableEntry entry;
	entry.frameNumber = frameNum;
	entry.valid = true;
	pageTable[pageNumber.value_] = entry;
	//std::cout << "add Frame\n";
}

unsigned PCB::findFrame(const Word& pageNum) // this finds the frame
{
	PageTableEntry temp = pageTable[pageNum.value_];
	if (temp.valid)
	{
		return temp.frameNumber;
	}
	return 257;
}

std::array <PageTableEntry, PAGE_TABLE_SIZE> PCB::pageTable; // this gets the pagetable 
