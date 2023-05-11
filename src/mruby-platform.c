#include "mruby.h"

mrb_value mrb_get_platform_symbol(mrb_state *mrb, mrb_value)
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#ifdef _WIN64
  return mrb_intern_lit(mrb, "windows_64");
#else
  return mrb_intern_lit(mrb, "windows_32");
#endif
#elif __APPLE__
#include <TargetConditionals.h>
#if TARGET_OS_IPHONE
  return mrb_intern_lit(mrb, "ios");
#elif TARGET_OS_MAC
  return mrb_intern_lit(mrb, "macos");
#else
  return mrb_intern_lit(mrb, "apple");
#endif
#elif __EMSCRIPTEN__
  return mrb_intern_lit(mrb, "web");
#elif __ANDROID__
  return mrb_intern_lit(mrb, "android");
#elif __linux__
  return mrb_intern_lit(mrb, "linux");
#elif __unix__
  return mrb_intern_lit(mrb, "unix");
#elif defined(_POSIX_VERSION)
  return mrb_intern_lit(mrb, "posix");
#else
  return mrb_intern_lit(mrb, "unknown");
#endif
}

void mrb_mruby_platform_gem_init(mrb_state *mrb)
{
  struct RClass *Mruby_platform_module;
  Mruby_platform_module = mrb_define_module(mrb, "Platform");
  mrb_define_module_function(mrb, Mruby_platform_module, "get_platform", mrb_get_platform_symbol, MRB_ARGS_NONE());
}

void mrb_mruby_platform_gem_final(mrb_state *mrb)
{
  /* finalizer */
}