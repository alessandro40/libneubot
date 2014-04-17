LIBNEUBOT_LOCAL_PATH := $(call my-dir)

include $(call all-subdir-makefiles)

LOCAL_PATH := $(LIBNEUBOT_LOCAL_PATH)
include $(CLEAR_VARS)

LOCAL_STATIC_LIBRARIES :=\
	event2\
	lua

LOCAL_MODULE:= neubot
LOCAL_MODULE_TAGS:= optional

LOCAL_CFLAGS := -DNEUBOT_ANDROID

LOCAL_SRC_FILES := \
    echo.c \
    log.c \
    libneubot.cpp \
    pollable.cpp \
    poller.c \
    strtonum.c \
    utils.c

include $(BUILD_STATIC_LIBRARY)
