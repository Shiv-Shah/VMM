//
//  LRU.hpp
//  crap
//
//  Created by OrderInChaos on 5/8/19.
//  Copyright © 2019 OrderInChaos. All rights reserved.
//

#ifndef LRU_hpp
#define LRU_hpp

#include <stdio.h>
#include "PRA.hpp"
#include <array>
#include "constVars.hpp"
#include <time.h>

/*
struct LRU_Stat
{
	time_t timestamp;
	uint32_t pageNum;
};*/


class LRU : public PRA {
public:
	LRU();
	unsigned select_frame(int type);
	void remove_frame();
	void update_usage(uint32_t, int type);
    void replace (uint32_t, int);
	~LRU();

private:


	static std::array<time_t, RAM_SIZE> replacement_ram_time_stamps;
    static std::array<uint32_t, RAM_SIZE> replacement_ram_page_num;
	static std::array<time_t, TLB_SIZE> replacement_tlb_counters;
    static std::array<uint32_t, TLB_SIZE> replacement_tlb_index;
};

#endif /* LRU_hpp */
