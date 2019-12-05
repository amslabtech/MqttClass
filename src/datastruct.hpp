//
//
//
#ifndef _DATA_STRUCTURE_HPP_
#define _DATA_STRUCTURE_HPP_

#include <iostream>
#include <iomanip>
#include <time.h>
#include <sys/time.h>

struct DataStructure {
	int32_t id;
	struct timeval ts;
	float  gx[3];
	float  ax[3];
	float  mx[3];

	void print(){ std::cout
		<< std::setw(10) << id
		<< std::setw(16) << ts.tv_sec
		<< std::setw(10) << ts.tv_usec
		<< std::setw(10) << gx[0]
		<< std::setw(10) << gx[1]
		<< std::setw(10) << gx[2] << std::endl; }
};

#endif	// _DATA_STRUCTURE_HPP_
