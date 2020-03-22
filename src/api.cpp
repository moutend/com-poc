#include <windows.h>
#include <cstring>

#include "api.h"

void __stdcall DoSomething(Foo *pFoo) {
  pFoo = reinterpret_cast<Foo *>(CoTaskMemAlloc(sizeof(Foo)));
  pFoo->Name = reinterpret_cast<LPWSTR>(CoTaskMemAlloc(64));

  pFoo->Value = 1.23;
  std::wmemcpy(pFoo->Name, L"Hello, World!", 13);

  return;
}
