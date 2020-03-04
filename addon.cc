#include <napi.h>

Napi::Value Add(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() != 2) {
    throw Napi::TypeError::New(env, "Two arguments expected.");
  }
  if (!info[0].IsNumber() || !info[1].IsNumber()) {
    throw Napi::TypeError::New(env, "Expected two numbers as arguments.");
  }
  int64_t a = info[0].As<Napi::Number>();
  int64_t b = info[1].As<Napi::Number>();
  int64_t sum = a + b;
  Napi::Number jsValue = Napi::Number::New(env, sum);
  return jsValue;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports["add"] = Napi::Function::New(env, Add);
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
