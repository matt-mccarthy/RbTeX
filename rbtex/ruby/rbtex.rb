require 'ffi'

module RbTex
	extend FFI::Library
	ffi_lib 'c'
	ffi_lib '../cpp/exec/texer.so'
end
