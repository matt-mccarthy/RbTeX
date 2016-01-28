module Tex
	RB_AUX_FILE = 'fd_tmp.rtx.aux'
	RB_TMP_LINE_DELIM = '##--!!'
	LATEX_TMP_LINE_DELIM = '%%--!!'

	def Tex.print (latex)
		writeToAuxFile(latex)
	end

	def writeToAuxFile (content)
		File.open(RB_AUX_FILE,'a') do |file|
			file.puts content
		end
	end
end
