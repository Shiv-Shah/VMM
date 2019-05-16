//
//  Word.cpp
//  VMM
//
//  Created by Matthew Mikulka on 4/29/19.
//  Copyright � 2019 Matthew Mikulka. All rights reserved.
//

#include "Word.hpp"


uint32_t Address::address()
{
	/*
		not much is done here, this is just holding the
		address
	*/
	return value_;
}
//a = a << 3; this bit shifts left 3 so if a was 00000001
// not this becomes 00001000

uint32_t Address::displacement()
{
	Word temp;

	temp.value_ = (value_ & PAGE_SIZE);

	return temp.value_;
}
Word Address::frame()
{
	Word temp;
	temp.value_ = ((value_ >> 8) & PAGE_SIZE);

	return temp;
}
Word Address::page()
{
	Word temp = frame();
	/*
		this is going to be bits 15 - 8 from the pdf document
	*/
	return temp;
}

Address& Address::operator=(const Address & rhs)
{
	if (&rhs != this)
	{
		value_ = rhs.value_;
	}
	else
	{
		std::cerr << "Attempted assignment to itself.";
	}
	return *this;
}
Address& Address::operator=(const Word & rhs)
{
	if (&rhs != this)
	{
		value_ = rhs.value_;
	}
	else
	{
		std::cerr << "Attempted assignment to itself.";
	}
	return *this;
}