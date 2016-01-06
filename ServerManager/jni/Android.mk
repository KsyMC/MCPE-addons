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
LOCAL_SRC_FILES :=                                         \
    main.cpp                                               \
    hook/hook.cpp                                          \
    servermanager/ServerManager.cpp                        \
    servermanager/Server.cpp                               \
    servermanager/client/CustomMinecraftClient.cpp         \
    servermanager/client/gui/CustomChatScreen.cpp          \
    servermanager/client/resources/SMList.cpp              \
    servermanager/client/resources/BanList.cpp             \
    servermanager/client/resources/BanEntry.cpp            \
    servermanager/client/settings/SMOptions.cpp            \
    servermanager/command/CommandMap.cpp                   \
    servermanager/command/Command.cpp                      \
    servermanager/command/PluginCommand.cpp                \
    servermanager/command/defaults/VanillaCommand.cpp      \
    servermanager/command/defaults/GameModeCommand.cpp     \
    servermanager/command/defaults/WhitelistCommand.cpp    \
    servermanager/command/defaults/HelpCommand.cpp         \
    servermanager/command/defaults/KickCommand.cpp         \
    servermanager/command/defaults/BanCommand.cpp          \
    servermanager/command/defaults/BanIpCommand.cpp        \
    servermanager/command/defaults/BanListCommand.cpp      \
    servermanager/command/defaults/PardonCommand.cpp       \
    servermanager/command/defaults/PardonIpCommand.cpp     \
    servermanager/command/defaults/OpCommand.cpp           \
    servermanager/command/defaults/DeopCommand.cpp         \
    servermanager/command/defaults/TellCommand.cpp         \
    servermanager/command/defaults/ListCommand.cpp         \
    servermanager/command/defaults/TimeCommand.cpp         \
    servermanager/command/defaults/GiveCommand.cpp         \
    servermanager/command/defaults/TeleportCommand.cpp     \
    servermanager/command/defaults/MeCommand.cpp           \
    servermanager/command/defaults/KillCommand.cpp         \
    servermanager/entity/CustomLocalPlayer.cpp             \
    servermanager/entity/SMEntity.cpp                      \
    servermanager/entity/SMLocalPlayer.cpp                 \
    servermanager/entity/SMMob.cpp                         \
    servermanager/entity/SMPlayer.cpp                      \
    servermanager/event/Cancellable.cpp                    \
    servermanager/event/Event.cpp                          \
    servermanager/event/HandlerList.cpp                    \
    servermanager/event/player/PlayerEvent.cpp             \
    servermanager/event/player/PlayerJoinEvent.cpp         \
    servermanager/event/player/PlayerQuitEvent.cpp         \
    servermanager/event/server/PluginDisableEvent.cpp      \
    servermanager/event/server/PluginEnableEvent.cpp       \
    servermanager/event/server/PluginEvent.cpp             \
    servermanager/level/SMBlockSource.cpp                  \
    servermanager/level/SMLevel.cpp                        \
    servermanager/network/CustomRakNetInstance.cpp         \
    servermanager/network/CustomServerNetworkHandler.cpp   \
    servermanager/plugin/PluginBase.cpp                    \
    servermanager/plugin/PluginDescriptionFile.cpp         \
    servermanager/plugin/PluginManager.cpp                 \
    servermanager/plugin/RegisteredListener.cpp            \
    servermanager/util/SMUtil.cpp

include $(BUILD_SHARED_LIBRARY)