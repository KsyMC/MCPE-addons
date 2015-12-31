#include <dlfcn.h>
#include <cstring>
#include <sys/mman.h>

void **GetVtable(const char *vtableSym)
{
	return (void **) ((int) dlsym(RTLD_DEFAULT, vtableSym) + 8);
}

int GetVtableIndex(void **vtable, const char *functionSym, int size)
{
	for(int i = 0; i < size; i++)
	{
		Dl_info info;
		dladdr(vtable[i], &info);
		if(!strcmp(info.dli_sname, functionSym))
			return i;
	}
	return -1;
}

void VirtualHook(void **vtable, int index, void *hook, void **real)
{
	*real = vtable[index];
	vtable[index] = hook;
}

void VirtualHook(void **vtable, const char *functionSym, void *hook, void **real)
{
	int index = GetVtableIndex(vtable, functionSym, 80);

	*real = vtable[index];
	vtable[index] = hook;
}

void tiny_hook(uint32_t* addr, uint32_t hook) {
	bool thumb = (uint32_t)addr & 1;
	if(thumb)
		addr = (uint32_t*) ((uint32_t) addr - 1);
	mprotect(addr, 9, PROT_READ | PROT_WRITE);
	*addr = (uint32_t) (thumb)? 0xF000F8DF : 0xE51FF004; // LDR PC, [PC] on Thumb and LDR PC, [PC, #-4] on ARM.
	*(addr + 1) = hook;
	mprotect(addr, 9, PROT_READ | PROT_EXEC);
}
