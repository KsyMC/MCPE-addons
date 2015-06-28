LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := com.ksymc.testaddon
LOCAL_LDLIBS    := -L$(LOCAL_PATH) -ldl -llog -lstdc++ -lminecraftpe -lmcpelauncher_tinysubstrate -lcom.ksymc.addonmanager

LOCAL_SRC_FILES :=                                       \
    glm/detail/glm.cpp                                   \
    main.cpp                                             \
    TestAddon.cpp                                        \
    TestAddon/entity/passive/Horse.cpp                   \
    TestAddon/client/model/HorseModel.cpp                \
    TestAddon/client/model/WingedSteveModel.cpp          \
    TestAddon/client/renderer/entity/HorseRenderer.cpp   \
    TestAddon/client/gui/TestScreen.cpp                  \
    TestAddon/client/gui/TestListItemElement.cpp         \
    TestAddon/tile/AnywhereDoorTile.cpp                  \

TARGET_NO_UNDEFINED_LDFLAGS :=

include $(BUILD_SHARED_LIBRARY)