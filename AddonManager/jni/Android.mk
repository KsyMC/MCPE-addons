LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := com.ksymc.addonmanager
LOCAL_LDLIBS    := -L$(LOCAL_PATH) -ldl -llog -lstdc++ -lminecraftpe -lmcpelauncher_tinysubstrate

LOCAL_SRC_FILES :=                                   \
    glm/detail/glm.cpp                               \
    main.cpp                                         \
    Addon.cpp                                        \
    AddonManager.cpp                                 \
    AddonManagerAddon.cpp                            \
    AddonManager/client/gui/AddonManagerScreen.cpp   \
    AddonManager/client/gui/AddonListItemElement.cpp \

TARGET_NO_UNDEFINED_LDFLAGS :=

include $(BUILD_SHARED_LIBRARY)