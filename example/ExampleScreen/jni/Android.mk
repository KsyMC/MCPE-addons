LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

FILE_LIST            := $(wildcard $(LOCAL_PATH)/*.cpp)
SCREEN_FILE_LIST     := $(wildcard $(LOCAL_PATH)/mcpe/gui/screen/*.cpp)

LOCAL_MODULE    := example.examplescreen
LOCAL_LDLIBS    := -L$(LOCAL_PATH) -ldl -llog -lEGL -lGLESv2 -lmcpelauncher -lminecraftpe
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(SCREEN_FILE_LIST:$(LOCAL_PATH)/%=%)

include $(BUILD_SHARED_LIBRARY)
