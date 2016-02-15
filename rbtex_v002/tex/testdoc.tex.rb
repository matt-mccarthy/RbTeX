require './rbtex'
string = "Hello Steven"
Tex.print "#{string}", 8
Tex.print "\\[\\frac{\\nabla F}{9}\\]", 9
Tex.imath "{\\nabla^{2}u}", 10
