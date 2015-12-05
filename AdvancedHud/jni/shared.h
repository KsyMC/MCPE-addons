#pragma once

#include <android/log.h>

#define LOG_TAG 	"AdvancedHud"
#define LOGE(...) 	__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGI(...) 	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
