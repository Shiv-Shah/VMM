//
//  LRU.cpp
//  crap
//
//  Created by OrderInChaos on 5/8/19.
//  Copyright © 2019 OrderInChaos. All rights reserved.
//

#include "LRU.hpp"
#include "constVars.hpp"

LRU::LRU() {
	//for (int i = 0; i < RAM_SIZE; ++i)
	//{
	//	time(&replacement_ram_time_stamps[i]);
	//	replacement_ram_page_num[i] = 256;
	//}
	//for (int i = 0; i < TLB_SIZE; ++i)
	//{
	//	time(&replacement_tlb_counters[i]);
	//	replacement_tlb_index[i] = 256;
	//}
}

unsigned LRU::select_frame(int type)
{
	time_t timeStamp; // get the timestamp
	uint32_t pageNum;
	time(&timeStamp);
	if (type == 0) //replacement Ram
	{
		for (int i = 0; i < RAM_SIZE; ++i)
		{
			if (replacement_ram_time_stamps[i] <= timeStamp) // we check the timestamps
			{
				pageNum = replacement_ram_page_num[i];
				timeStamp = replacement_ram_time_stamps[i];
			}
		}
	}
	else //replacement TLB
	{
		for (int i = 0; i < TLB_SIZE; ++i)
		{
			if (replacement_tlb_counters[i] <= timeStamp) // we check the timestamps
			{
				pageNum = replacement_tlb_index[i];
			}
		}
	}

	return pageNum;
}

void LRU::replace(uint32_t frameNum, int type)
{
	if (type == 0)// this is for the RAM
	{
		//if (frameNum <256)
		//{
			time_t currentTime;
		//	replacement_ram_page_num[frameNum] = pageNum;
			time(&currentTime);
			replacement_ram_time_stamps[frameNum] = currentTime;
		//}
	}
	else // for TLB
	{
		//replacement_tlb_index[frameNum] = pageNum;
		time(&replacement_tlb_counters[frameNum]);
	}
}


void LRU::update_usage(uint32_t frameNum, int type)
{
	if (type == 0) // replacement ram
	{
		time_t currentTime;
		time(&currentTime);
		replacement_ram_time_stamps[frameNum] = currentTime; // this function updates the usage

	}
	else
	{
		time_t currentTime;
		time(&currentTime);
		replacement_tlb_counters[frameNum] = currentTime; // this function updates the usage
	}
}


LRU::~LRU()
{
	/*for (int i = 0; i < RAM_SIZE; ++i)
	{

	}*/

}


std::array<time_t, RAM_SIZE> LRU::replacement_ram_time_stamps;
std::array<time_t, TLB_SIZE> LRU::replacement_tlb_counters;
std::array<uint32_t, RAM_SIZE> LRU::replacement_ram_page_num;
std::array<uint32_t, TLB_SIZE> LRU::replacement_tlb_index;
