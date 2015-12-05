#include <jni.h>
#include <dlfcn.h>
#include <string>

#include "Substrate.h"
#include "dl_internal.h"
#include "shared.h"

class RakNetInstance
{
public:
	void _startupIfNeeded(unsigned short, int);
	void host(std::string const &, int, int);
};

namespace RakNet
{
	class RakPeer;
};

static void (*RakNetInstance$_startupIfNeeded_real)(RakNetInstance *, unsigned short, int);
static void RakNetInstance$_startupIfNeeded_hook(RakNetInstance *_this, unsigned short port, int connections)
{
	RakNetInstance$_startupIfNeeded_real(_this, port, 1000);
}

static void (*RakNetInstance$host_real)(RakNet::RakPeer *, std::string const &name, int port, int connections);
static void RakNetInstance$host_hook(RakNet::RakPeer *_this, std::string const &name, int port, int connections)
{
	RakNetInstance$host_real(_this, name, port, 1000);
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
	dlerror();

	soinfo2 *handle = (soinfo2 *) dlopen("libminecraftpe.so", RTLD_LAZY);

	MSHookFunction((void *) &RakNetInstance::_startupIfNeeded,
			(void *) &RakNetInstance$_startupIfNeeded_hook,
			(void **) &RakNetInstance$_startupIfNeeded_real);

	MSHookFunction((void *) &RakNetInstance::host,
				(void *) &RakNetInstance$host_hook,
				(void **) &RakNetInstance$host_real);

	const char *error = dlerror();
	if(error)
		LOGI("Error : %s", error);

	return JNI_VERSION_1_2;
}
