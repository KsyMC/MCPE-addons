LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := com.ksymc.toomanyserverslots
LOCAL_LDLIBS    := -L$(LOCAL_PATH) -ldl -llog -lstdc++ -lminecraftpe -lmcpelauncher_tinysubstrate

LOCAL_SRC_FILES :=                                   \
    main.cpp                                         \

TARGET_NO_UNDEFINED_LDFLAGS :=

include $(BUILD_SHARED_LIBRARY)