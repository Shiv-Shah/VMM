//
//  Word.hpp
//  VMM
//
//

#ifndef Word_hpp
#define Word_hpp

#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include "constVars.hpp"

struct Word // this is the value 
{
public:
	uint32_t value_; // actual address of the word
};


/*
	our structure that inherits from word it's value
*/
struct Address : Word
{
public:
	uint32_t address();						//returns the address 
	uint32_t displacement();				// returns the last 8 bits 
	Word frame();							//returns the actual frame number
	Word page();							//returns the frame # relabeled as page #
	Address& operator=(const Address& rhs);	//
	Address& operator=(const Word& rhs);
};


#endif /* Word_hpp */