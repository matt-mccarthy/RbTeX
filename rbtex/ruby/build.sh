gem build rbtex.gemspec
if [[ $? == 0 ]]
then
	gem install ./rbtex-0.0.1.gem
	cp rbtex-0.0.1.gem ../product/
	exit 0
else
	exit 2
fi
