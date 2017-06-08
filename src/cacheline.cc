#include "cacheline.h"

#if defined(__APPLE__)

#include <sys/sysctl.h>
size_t CacheLineSize() {
	size_t lineSize = 0;
	size_t sizeOfLineSize = sizeof(lineSize);
	// https://opensource.apple.com/source/xnu/xnu-792.12.6/libkern/libkern/sysctl.h
	sysctlbyname("hw.cachelinesize", &lineSize, &sizeOfLineSize, 0, 0);

	return lineSize;
}

#elif defined(__linux__)

#include <stdio.h>
size_t CacheLineSize() {
	FILE * f = 0;

	f = fopen("/sys/devices/system/cpu/cpu0/cache/index0/coherency_line_size", "r");
	unsigned int lineSize = 0;

	if (f) {
		fscanf(f, "%d", &lineSize);
		fclose(f);
	}

	return lineSize;
}

#else
#error Unrecognized platform
#endif
