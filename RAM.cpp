//
//  RAM.cpp
//  VMM
//
//  Created by Matthew Mikulka on 4/28/19.
//  Copyright � 2019 Matthew Mikulka. All rights reserved.
//

#include "RAM.hpp"

RAM::RAM()
{

}


unsigned char RAM::read(unsigned frameNum, Address& addr) // reads the value
{
	unsigned char data;
	statuses[frameNum].accessed = true;
	uint32_t displacement = addr.displacement();
	char pageData = frames[frameNum][displacement];
	data = static_cast<unsigned char>(pageData);
	return data;
}

void RAM::addFrame(char* item, unsigned frameNum) // this adds the frames
{
//	if (frameNum < 256)
//	{
		frames[frameNum] = item;
		statuses[frameNum].accessed = false;
		statuses[frameNum].dirty = false;
//	}
}

/*void RAM::deleteFrame(unsigned FrameNum)
{
	frames[FrameNum] = NULL;
}*/

std::array<char*, RAM_SIZE> RAM::frames;
std::array<Status, RAM_SIZE> RAM::statuses;
