APP_ABI := armeabi-v7a arm64-v8a x86 x86_64
APP_PLATFORM := android-21
APP_STL := c++_static
APP_CPPFLAGS := -std=c++1z
APP_LDFLAGS += -L$(SYSROOT)/usr/lib -landroid -llog -latomic -ldl

NDK_TOOLCHAIN_VERSION = clang