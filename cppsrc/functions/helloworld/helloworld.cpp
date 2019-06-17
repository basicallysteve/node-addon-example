#include "helloworld.h"

std::string helloworld::hello(){
    return "Hello World";
}

Napi::String helloworld::HelloWrapped(const Napi::CallbackInfo& info){
    Napi::Env env = info.Env();
    Napi::String returnValue = Napi::String::New(env, helloworld::hello());

    return returnValue;
}

Napi::Object helloworld::Init(Napi::Env env, Napi::Object exports){
    exports.Set(
        "hello", Napi::Function::New(env, helloworld::HelloWrapped)
    );
    return exports;
}