gem build rbtex.gemspec
if [[ $? == 0 ]]
then
	gem install ./rbtex-0.0.1.gem
	# gem push rbtex-0.0.1.gem
	# gem install rbtex
	exit 0
else
	exit 2
fi
