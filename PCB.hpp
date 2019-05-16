#pragma once
#ifndef PCB_h
#define PCB_h

#include <array>
#include "Word.hpp"
#include <iostream>
#include "constVars.hpp"

struct PageTableEntry
{
public:
	unsigned frameNumber = 0;
	bool valid = false;
};

class PCB
{
public:
	PCB();
	static void addFrame(const Word& pageNumber, const unsigned& FrameNumber);
	static unsigned findFrame(const Word&);
private:
	static std::array <PageTableEntry, PAGE_TABLE_SIZE> pageTable;
};

#endif