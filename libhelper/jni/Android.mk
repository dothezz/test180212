LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := maniac_core
LOCAL_SRC_FILES := ../../libcore/obj/local/$(TARGET_ARCH_ABI)/libmaniac_core.so

include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MULTILIB := both
LOCAL_MODULE := libmaniac_helper
LOCAL_SRC_FILES := $(wildcard $(LOCAL_PATH)/*.cc) $(wildcard $(LOCAL_PATH)/**/*.cc)
LOCAL_CFLAGS := -I$(LOCAL_PATH)/../../includes/
LOCAL_SHARED_LIBRARIES := maniac_core

include $(BUILD_SHARED_LIBRARY)