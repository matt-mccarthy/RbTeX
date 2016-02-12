$out_file = ARGV[0]

if $out_file
    File.new($out_file,"w").close
end

module Tex

    def Tex.print(latex)
        printToOutFile latex
    end

    def printToOutFile(line)
        File.open($out_file, 'a') do |file|
            file.puts line
        end
    end

end
