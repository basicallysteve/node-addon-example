#include <napi.h>

namespace addFunc{
    int add(int a, int b);
Napi::Number AddWrapped(const Napi::CallbackInfo& info);
Napi::Object Init(Napi::Env env, Napi::Object exports);
}
