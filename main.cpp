//
//  main.cpp
//  VMM
//
//  Created by Matthew Mikulka on 4/28/19.
//  Copyright ? 2019 Matthew Mikulka. All rights reserved.
//

#include <iostream>
#include <fstream>
//#include "backingStore.h"
//#include "MemoryManager.h"
#include "MMU.hpp"
//#include "RAM.h"
//#include "Word.hpp"

using namespace std;

int main()
{

	uint32_t temp = 0;
	Address logAddr;
	MemoryManager manager;
	bool loopCheck = true;
	MMU mem_man_un;
	mem_man_un.instance();
	unsigned char data;
	int count = 0;
	while (cin >> temp) //<addresses.txt> 2|output.txt //takes int the addresses
	{
		while (loopCheck) // loopcheck to deal with while truw 
		{
			try
			{
				logAddr.value_ = temp;
				data = mem_man_un.read(logAddr); // goes to MMU
				loopCheck = false;
			}
			catch (MMU::PageFault p)
			{
				manager.pageIn(p.pageNumber_); // deals with pagefault and goes to mem man
			}
		}
		count++;
		cout << hex<< static_cast<unsigned int>(data) << endl; 
		loopCheck = true;
	}

	double TLBPrecentages = (static_cast<double>(mem_man_un.TLBHits()) / 
		static_cast<double>(mem_man_un.TLBAccesses()));
	double pagePrecentage = (static_cast<double>(mem_man_un.pageFaults()) / 
		static_cast<double>(mem_man_un.pageAccesses()));
	cout <<dec  << "TLB Hits: " <<  TLBPrecentages * 100.0 << "%" <<  endl; // print precentage of TLB hits
	cout << dec << "Page Faults: " << pagePrecentage * 100.0 << "%" <<endl; // Print precentage of Page Faults
	cout << dec << "end of program" << endl;
	cin.clear();
	cin.ignore(256, '\n');
	cin.get();


	return 0;
}
