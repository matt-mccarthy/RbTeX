require './rbtex'

def printGrahm num, rbtexinsertedlinenumber
tstr = "#{num}^{"

i = 0
while i < 64
tstr << "#{num}^{"
i = i + 1
end
tstr << "#{num}"
while i >= 0
tstr << "}"
i = i - 1
end
Tex.print Tex.cmath(tstr), rbtexinsertedlinenumber
end

module TM

def TM.hw rbtexinsertedlinenumber
Tex.print ('hello, world!'), rbtexinsertedlinenumber
end

class TestClass

def initialize rbtexinsertedlinenumber
Tex.print 'class initialized!', rbtexinsertedlinenumber
end

def doThing((arg0),rbtexinsertedlinenumber)
Tex.print 'doing thing...', rbtexinsertedlinenumber
Tex.print "Here's arg0 #{arg0}", rbtexinsertedlinenumber
end

end

end

TM.hw 51
puts 'hello, world!'
mtm = TM::TestClass.new(58)
mtm.doThing "afhalkdjfhaslkdj", 59
