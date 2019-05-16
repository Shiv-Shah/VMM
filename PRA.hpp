//
//  PRA.hpp
//  crap
//
//  Created by OrderInChaos on 5/8/19.
//  Copyright © 2019 OrderInChaos. All rights reserved.
//

#ifndef PRA_hpp
#define PRA_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include "BackingStore.hpp"
#include "Word.hpp"
#include "constVars.hpp"


class PRA {
public:
	PRA();
	virtual unsigned select_frame(int) = 0;
	virtual void update_usage(uint32_t, int) = 0;
	virtual void replace(uint32_t, int) = 0;
	~PRA();
};

#endif /* PRA_hpp */
