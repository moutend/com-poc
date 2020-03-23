package main

import (
	"fmt"
	"syscall"
	"unsafe"

	"github.com/go-ole/go-ole"
	"github.com/moutend/com-poc/internal/dll"
	"github.com/moutend/com-poc/internal/types"
)

func main() {
	var foo types.RawFoo

	dll.ProcDoSomething.Call(uintptr(unsafe.Pointer(&foo)))

	us := []uint16{}

	fmt.Printf("@@@foo %+v\n", foo)

	for i := 0; i < 1024; i += 2 {
		u := *(*uint16)(unsafe.Pointer(foo.Name + uintptr(i)))

		if u == 0 {
			break
		}

		us = append(us, u)
	}

	result := types.Foo{
		Name:  syscall.UTF16ToString(us),
		Value: foo.Value,
	}

	fmt.Printf("Result: %+v\n", result)

	defer ole.CoTaskMemFree(foo.Name)
	defer ole.CoTaskMemFree(uintptr(unsafe.Pointer(&foo)))
}
