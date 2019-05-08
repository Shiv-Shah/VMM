//
//  BackingStore.cpp
//  VMM
//
//  Created by Matthew Mikulka on 4/28/19.
//  Copyright � 2019 Matthew Mikulka. All rights reserved.
//

#include "BackingStore.hpp"


BackingStore::BackingStore()
{
	file.open("backingstore.bin");
}

Word BackingStore::read(Address & addr)
{
	Word item;

	Word pageNum = addr.page();

	file.seekg(pageNum.value_ * sizeof(uint32_t));

	file >> item.value_;

	return item;
}

BackingStore::~BackingStore()
{
	file.close();
}
