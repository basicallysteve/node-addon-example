// napi.h gives us access to helper macros, classes and functions
#include <napi.h>
#include "functions/helloworld/helloworld.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports){
    return helloworld::Init(env, exports);
}

//NODE_API_MODULE accepts module name and registerFunction as params
NODE_API_MODULE(addonexample, InitAll);