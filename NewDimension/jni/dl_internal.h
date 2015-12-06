typedef struct {
  char name[128];
  const void* phdr;
  int phnum;
  unsigned entry;
  unsigned base;
  unsigned size;
} soinfo2;
