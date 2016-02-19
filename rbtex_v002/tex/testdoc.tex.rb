require './rbtex'

def printGrahm rbtexinsertedlinenumber
tstr = "3^{"

i = 0
while i < 64
tstr << "3^{"
i = i + 1
end
tstr << "3"
while i >= 0
tstr << "}"
i = i - 1
end
Tex.print Tex.cmath(tstr), rbtexinsertedlinenumber
end

printGrahm 24

