#include <node.h>
#include <v8.h>

#if defined(__APPLE__)

#include <sys/sysctl.h>
size_t CacheLineSize() {
	size_t lineSize = 0;
	size_t sizeOfLineSize = sizeof(lineSize);
	// https://opensource.apple.com/source/xnu/xnu-792.12.6/libkern/libkern/sysctl.h
	sysctlbyname("hw.cachelinesize", &lineSize, &sizeOfLineSize, 0, 0);

	return lineSize;
}

#elif defined(__linux__)

#include <stdio.h>
size_t CacheLineSize() {
	FILE * p = 0;

	p = fopen("/sys/devices/system/cpu/cpu0/cache/index0/coherency_line_size", "r");
	unsigned int lineSize = 0;

	if (p) {
		fscanf(p, "%d", &lineSize);
		fclose(p);
	}

	return lineSize;
}

#else
#error Unrecognized platform
#endif

void Method(const v8::FunctionCallbackInfo<v8::Value>& args) {
    v8::Isolate* isolate = args.GetIsolate();
    v8::HandleScope scope(isolate);
    args.GetReturnValue().Set(v8::Integer::NewFromUnsigned(isolate, (unsigned int)CacheLineSize()));
}

void init(v8::Local<v8::Object> exports) {
    NODE_SET_METHOD(exports, "cacheLineSize", Method);
}

NODE_MODULE(binding, init)