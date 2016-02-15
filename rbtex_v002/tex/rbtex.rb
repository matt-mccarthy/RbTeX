$out_file = ARGV[0]

if $out_file
    File.new($out_file,"w").close
end

module Tex

    def Tex.print(latex, number)
        printToOutFile latex, number
    end

    def Tex.imath(math, number)
        printToOutFile "$#{math}$", number
    end

    def Tex.cmath(math, number)
        printToOutFile "\\[#{math}\\]", number
    end

    def Tex.printToOutFile(line, number)
        File.open($out_file, 'a') do |file|
            file.puts "#{line},#{number}"
        end
    end

end
