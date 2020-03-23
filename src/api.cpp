include<strsafe.h>
#include <wchar.h>
#include <windows.h>

#include "api.h"

    void __stdcall DoSomething(Foo *pFoo) {
  pFoo = reinterpret_cast<Foo *>(CoTaskMemAlloc(sizeof(Foo)));
  pFoo->Name = reinterpret_cast<LPWSTR>(CoTaskMemAlloc(64));

  pFoo->Value = 1.23;
  StringCbPrintfW(pFoo->Name, 28, L"Hello, World!");

  return;
}
