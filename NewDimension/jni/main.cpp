#include <jni.h>
#include <dlfcn.h>

#include "Substrate.h"
#include "dl_internal.h"
#include "tinyhook.h"
#include "shared.h"

#include "minecraftpe/Dimension.h"

#include "newdimension/NewDimension.h"

static std::unique_ptr<Dimension> (*Dimension$createNew_real)(DimensionId, Level &);
static std::unique_ptr<Dimension> Dimension$createNew_hook(DimensionId id, Level &level)
{
	if(id == DimensionId::DIMENSION_NEW)
		return std::unique_ptr<Dimension>(new NewDimension(level));

	return Dimension$createNew_real(id, level);
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
	soinfo2 *handle = (soinfo2 *) dlopen("libminecraftpe.so", RTLD_LAZY);

	MSHookFunction((void *) &Dimension::createNew, (void *) &Dimension$createNew_hook, (void **) &Dimension$createNew_real);

	return JNI_VERSION_1_2;
}
