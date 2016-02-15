$out_file = ARGV[0]

OUT_DELIM = "\u00b6".encode('utf-8')

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

    def Tex.center(latex)
        return "\\begin{center}#{latex}\\end{center}"
    end

    def Tex.table(array)
        pme = "\\begin{tabular}{|"
        i = 0
        while i < array[0].length
            pme << "c|"
            i = i + 1
        end
        pme << "} "
        array.each do |row|
            pme << "\\hline "
            rc = 0
            row.each do |elem|
                pme << " #{elem} "
                if rc < row.length - 1
                    pme << "&"
                end
                rc = rc + 1
            end
            pme << "\\\\ "
        end
        pme << "\\hline \\end{tabular}"
        return pme
    end

    def Tex.printToOutFile(line, number)
        File.open($out_file, 'a') do |file|
            file.puts "#{line}#{OUT_DELIM}#{number}"
        end
    end

end
