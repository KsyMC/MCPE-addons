LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := com.ksymc.servermanager
LOCAL_LDLIBS    := -L$(LOCAL_PATH) -ldl -llog -lstdc++ -lminecraftpe -lmcpelauncher_tinysubstrate

LOCAL_SRC_FILES :=                                        \
    main.cpp                                              \
    tinyhook.cpp                                          \
    servermanager/ServerManager.cpp                       \
    servermanager/SMOfflinePlayer.cpp                     \
    servermanager/SMPlayer.cpp                            \
    servermanager/SMLocalPlayer.cpp                       \
    servermanager/level/SMLevel.cpp                       \
    servermanager/command/SimpleCommandMap.cpp            \
    servermanager/command/Command.cpp                     \
    servermanager/command/defaults/GameModeCommand.cpp    \
    servermanager/command/defaults/WhitelistCommand.cpp   \
    servermanager/command/defaults/HelpCommand.cpp        \
    servermanager/command/defaults/KickCommand.cpp        \
    servermanager/command/defaults/BanCommand.cpp         \
    servermanager/command/defaults/BanIpCommand.cpp       \
    servermanager/command/defaults/BanListCommand.cpp     \
    servermanager/command/defaults/PardonCommand.cpp      \
    servermanager/command/defaults/PardonIpCommand.cpp    \
    servermanager/command/defaults/OpCommand.cpp          \
    servermanager/command/defaults/DeopCommand.cpp        \
    servermanager/command/defaults/TellCommand.cpp        \
    servermanager/command/defaults/ListCommand.cpp        \
    servermanager/command/defaults/TimeCommand.cpp        \
    servermanager/command/defaults/GiveCommand.cpp        \
    servermanager/command/defaults/TeleportCommand.cpp    \
    servermanager/event/TextContainer.cpp                 \
    servermanager/utils/SMList.cpp                        \
    servermanager/utils/SMOptions.cpp                     \

include $(BUILD_SHARED_LIBRARY)