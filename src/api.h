#pragma once

#include "types.h"

#define export __declspec(dllexport)

extern "C" {
export void __stdcall DoSomething(Foo *pFoo);
}
