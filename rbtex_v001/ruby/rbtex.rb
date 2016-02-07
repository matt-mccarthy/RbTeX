require 'rubygems'
require 'ffi'

module Tex
	extend FFI::Library
	ffi_lib FFI::Library::LIBC
	attach_function :postprocess

	RB_AUX_FILE = '_rbtex.out.aux'

	def Tex.print (latex)
		writeToAuxFile(latex)
	end

	def Tex.return_control()
		Tex.postprocess()
	end

	def writeToAuxFile (content)
		File.open(RB_AUX_FILE,'a') do |file|
			file.puts content
		end
	end
end
