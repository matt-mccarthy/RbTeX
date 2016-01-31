gem build rbtex.gemspec
if [[ $? == 0 ]]
then
	gem install ./rbtex-0.0.1.gem
	exit 0
else
	exit 2
fi
