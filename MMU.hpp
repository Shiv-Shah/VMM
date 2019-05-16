//
//  MMU.hpp
//
//
//

#ifndef MMU_h
#define MMU_h

#include <stdio.h>
#include "Word.hpp"
#include "MemoryManager.hpp"
#include <array>
#include "PCB.hpp"
#include "constVars.hpp"
#include "LRU.hpp"
struct TLB
{
	std::array<uint32_t, 16> pageNum;
	std::array<uint32_t, 16> FrameNum;
};


class MMU
{
public:
	MMU();//=delete;
	//MMU(MMU&); // = delete;
	//MMU instance();
	void instance();
	void clearTLB();
	void addFrame(char* item, uint32_t frameNum);
	int pageAccesses();
	int pageFaults();
	int TLBAccesses();
	int TLBHits();

	unsigned char read(Address& addr);

	struct PageFault
	{
		PageFault();
		PageFault(const Word&);
		Word pageNumber_;
	};

	//u_int32_t return_test();

private:
	unsigned tlb_search(Word& pageNum);
	void tlb_add(uint32_t framenum, uint32_t pageNum);

	static int pageAccessCounts_;
	static int pageInFaults_;
	static int tlbAccessCount_;
	static int tlbHits_;
	static TLB tlb_;
	static uint32_t tlbCounter;
};



#endif /* MMU_h */
