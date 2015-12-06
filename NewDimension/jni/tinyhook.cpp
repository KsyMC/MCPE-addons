#include <sys/mman.h>

void tiny_hook(uint32_t* addr, uint32_t hook) {
	bool thumb = (uint32_t)addr & 1;
	if(thumb)
		addr = (uint32_t*) ((uint32_t) addr - 1);
	mprotect(addr, 9, PROT_READ | PROT_WRITE);
	*addr = (uint32_t) (thumb)? 0xF000F8DF : 0xE51FF004; // LDR PC, [PC] on Thumb and LDR PC, [PC, #-4] on ARM.
	*(addr + 1) = hook;
	mprotect(addr, 9, PROT_READ | PROT_EXEC);
}
