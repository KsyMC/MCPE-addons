LOCAL_PATH := $(call my-dir)

# --------------- crypto ---------------
include $(CLEAR_VARS)
LOCAL_MODULE := crypto
LOCAL_MODULE_FILENAME := crypto
LOCAL_SRC_FILES := curl/$(TARGET_ARCH_ABI)/libcrypto.a
LOCAL_EXPORT_LDLIBS := -lz
include $(PREBUILT_STATIC_LIBRARY)

# --------------- ssl ---------------
LOCAL_MODULE := ssl
LOCAL_MODULE_FILENAME := ssl
LOCAL_SRC_FILES := curl/$(TARGET_ARCH_ABI)/libssl.a
include $(PREBUILT_STATIC_LIBRARY)

# --------------- libcurl ---------------
include $(CLEAR_VARS)
LOCAL_MODULE := curl
LOCAL_MODULE_FILENAME := curl
LOCAL_SRC_FILES := curl/$(TARGET_ARCH_ABI)/libcurl.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/curl/include
LOCAL_STATIC_LIBRARIES += ssl
LOCAL_STATIC_LIBRARIES += crypto
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE           := com.ksymc.servermanager
LOCAL_LDLIBS           := -L$(LOCAL_PATH) -ldl -llog -lstdc++ -lminecraftpe -lmcpelauncher_tinysubstrate
LOCAL_STATIC_LIBRARIES := curl

FILE_LIST := $(wildcard $(LOCAL_PATH)/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/**/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/**/**/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/**/**/**/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/**/**/**/**/*.cpp)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

include $(BUILD_SHARED_LIBRARY)