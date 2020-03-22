package dll

import (
	"syscall"
)

var (
	dll = syscall.NewLazyDLL("poc.dll")

	ProcDoSomething = dll.NewProc("DoSomething")
)
