#include <jni.h>

void exampleScreen();

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
	exampleScreen();

	return JNI_VERSION_1_2;
}
