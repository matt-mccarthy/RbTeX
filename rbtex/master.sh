cd ruby
./build.sh
if [[ $? -ne 0 ]]
then
	echo "Failed to build ruby gem :("
	exit 2
fi

cd ../cpp
./build.sh
if [[ $? -ne 0 ]]
then
	echo "Failed to compile C++ files :("
	exit 2
fi

return 0
