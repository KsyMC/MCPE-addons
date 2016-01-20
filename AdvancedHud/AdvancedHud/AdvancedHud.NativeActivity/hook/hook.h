#pragma once

typedef struct
{
  char name[128];
  const void* phdr;
  int phnum;
  unsigned entry;
  unsigned base;
  unsigned size;
} soinfo2;

void **GetVtable(const char *vtableSym);
int GetVtableIndex(void **vtable, const char *functionSym, int size);
void VirtualHook(void **vtable, int index, void *hook, void **real);
void VirtualHook(void **vtable, const char *functionSym, void *hook, void **real);
void tiny_hook(uint32_t*, uint32_t);
