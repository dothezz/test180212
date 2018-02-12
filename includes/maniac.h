#pragma once

#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>

namespace maniac {

class NativeEngine {
 public:
  NativeEngine(const std::string& name);
  NativeEngine(uintptr_t address);

  void AddSymbolHook(const std::string& id, const std::string& symbol,
                     uintptr_t new_function_ptr);
  void AddRelativeHook(const std::string& id, uintptr_t relative_address,
                       uintptr_t new_function_ptr);
  void AddAbsoluteHook(const std::string& id, uintptr_t absolute_address,
                       uintptr_t new_function_ptr);
  void AddSymbolPatch(const std::string& id, const std::string& symbol,
                      const std::vector<uint8_t>& new_bytes);
  void AddRelativePatch(const std::string& id, uintptr_t relative_address,
                        const std::vector<uint8_t>& new_bytes);
  void AddAbsolutePatch(const std::string& id, uintptr_t absolute_address,
                        const std::vector<uint8_t>& new_bytes);

  ssize_t ApplyAll();
  ssize_t ApplyAllHooks();
  ssize_t ApplyAllPatches();
  ssize_t ApplyHook(const std::string& id);
  ssize_t ApplyPatch(const std::string& id);

  ssize_t ResetAll();
  ssize_t ResetAllHooks();
  ssize_t ResetAllPatches();
  ssize_t ResetHook(const std::string& id);
  ssize_t ResetPatch(const std::string& id);
};

}  // namespace maniac