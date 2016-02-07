cd ruby
sudo ./build.sh
if [[ $? -ne 0 ]]
then
	echo "Failed to build ruby gem :("
	exit 2
fi

cd ../cpp
sudo ./build.sh
if [[ $? -ne 0 ]]
then
	echo "Failed to compile C++ files :("
	exit 2
else
	cp ./exec/rbtex ../tex/rbtex
fi

exit 0
