extern "C" {
	void mcpelauncher_hook(void *orig_fcn, void *new_fcn, void **orig_fcn_ptr);
	void *dobby_dlsym(void *handle, const char *symbol);
}
