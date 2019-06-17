#include "add.h"

int addFunc::add(int a, int b){
    return a + b;
}

Napi::Number addFunc::AddWrapped(const Napi::CallbackInfo& info){
    Napi::Env env = info.Env();

    if(info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()){
        Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    }

    Napi::Number first = info[0].As<Napi::Number>();
    Napi::Number second = info[1].As<Napi::Number>();

    int returnValue = addFunc::add(first.Int32Value(), second.Int32Value());

    return Napi::Number::New(env, returnValue);
}

Napi::Object addFunc::Init(Napi::Env env, Napi::Object exports){
    exports.Set("add", Napi::Function::New(env, addFunc::AddWrapped));
    return exports;
}