//
//  FIFO.cpp
//  crap
//
//  Created by OrderInChaos on 5/8/19.
//  Copyright © 2019 OrderInChaos. All rights reserved.
//

#include "FIFO.hpp"


FIFO::FIFO() {
	for (int i = 0; i < RAM_SIZE; ++i)
	{
		replacement_ram.push_back(i); // pushing back into our replacement algorithm
	}
	for (int i = 0; i < TLB_SIZE; ++i)
	{
		replacement_tlb.push_back(i);
	}
}

unsigned FIFO::select_frame(int type) //1 for TLB; 0 for RAM // finding a frame for FIFO
{
	Word frame;
	if (type == 0)
	{
		frame.value_ = replacement_ram.front();
		replacement_ram.pop_front();
		replacement_ram.push_back(frame.value_); // doing the FIFO part

	}
	else
	{
		frame.value_ = replacement_tlb.front();
		replacement_tlb.pop_front();
		replacement_tlb.push_back(frame.value_);
	}
	return frame.value_;
}

void FIFO::update_usage(uint32_t frame, int type)
{
	(void)type;
	(void)frame;
	// virtual funcitons used in pra
}

void FIFO::replace (uint32_t frame, int type)
{
	(void)frame;
	(void)type;
	// virtual funcitons used in pra
}

FIFO::~FIFO() {

}
std::list<uint32_t> FIFO::replacement_ram;
std::list<uint32_t> FIFO::replacement_tlb;
