gem build rbtex.gemspec
if [[ $? == 0 ]]
then
	gem install ./rbtex-0.0.1.gem
fi

return 0
