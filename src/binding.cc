#include <node.h>
#include <v8.h>

#include "cacheline.cc"

void Method(const v8::FunctionCallbackInfo<v8::Value>& args) {
    v8::Isolate* isolate = args.GetIsolate();
    v8::HandleScope scope(isolate);
    args.GetReturnValue().Set(v8::Integer::NewFromUnsigned(isolate, (unsigned int)CacheLineSize()));
}

void init(v8::Local<v8::Object> exports) {
    NODE_SET_METHOD(exports, "cacheLineSize", Method);
}

NODE_MODULE(binding, init)