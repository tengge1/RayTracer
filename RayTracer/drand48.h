#pragma once

#ifndef DRAND48_H
#define DRAND48_H

#include <stdlib.h>

#define m1 0x100000000LL
#define c1 0xB16
#define a1 0x5DEECE66DLL

static unsigned long long seed = 1;

double drand48(void)
{
	seed = (a1 * seed + c1) & 0xFFFFFFFFFFFFLL;
	unsigned int x = seed >> 16;
	return 	((double)x / (double)m1);

}

void srand48(unsigned int i)
{
	seed = (((long long int)i) << 16) | rand();
}

#endif