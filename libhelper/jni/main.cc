#include <android/log.h>
#include <maniac.h>
#include <sched.h>
#include <stdarg.h>
#include <stdlib.h>

#define LOG_TAG "MANIAC_HELPER"
#define LOGD(fmt, args...) \
  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, fmt, ##args)

using namespace maniac;

static void init() __attribute__((constructor));

// entry point
void init() {
  LOGD("[!] helper loaded");

  NativeEngine native_engine = NativeEngine("libzombie-highway.so");

  native_engine.AddSymbolHook("Ammo", "_ZN14WeaponsManager14isInfiniteAmmoEv",
                              (uintptr_t) + []() { return 1; });

  native_engine.AddSymbolHook("Invincible", "_ZN9ZombieCar5crashEv",
                              (uintptr_t) + []() { return; });

  native_engine.ApplyAll();
}