#include <strsafe.h>
#include <windows.h>

#include "api.h"

void __stdcall DoSomething(Foo **ppFoo) {
  (*ppFoo) = reinterpret_cast<Foo *>(CoTaskMemAlloc(sizeof(Foo)));
  (*ppFoo)->Name = reinterpret_cast<LPWSTR>(CoTaskMemAlloc(64));

  (*ppFoo)->Value = 1.23;
  StringCbPrintfW((*ppFoo)->Name, 28, L"Hello, World!");

  return;
}
