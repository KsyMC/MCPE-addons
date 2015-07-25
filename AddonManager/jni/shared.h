#pragma once

#include <android/log.h>

#define LOG_TAG 	"AddonManager"
#define LOGE(...) 	__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGI(...) 	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#define VERSION_CODE	0
#define VERSION_NAME	"1.0"

extern std::vector<Addon *> addons;
