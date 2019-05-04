//
//  Word.cpp
//  VMM
//
//  Created by Matthew Mikulka on 4/29/19.
//  Copyright © 2019 Matthew Mikulka. All rights reserved.
//

#include "Word.h"


u_int32_t Address::address()
{
    /*
        not much is done here, this is just holding the 
        address
    */
    return value_;
}
 //a = a << 3; this bit shifts left 3 so if a was 00000001
 // not this becomes 00001000

Word Address::displacement()
{
    Word temp = {value_&255};

    temp.value_ = (value_ & 256);

    return temp;
}
Word Address::frame()
{
    Word temp={(value_>>8)&255};

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
