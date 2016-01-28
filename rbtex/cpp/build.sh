check() {
	if [[ $? -ne 0 ]]
	then
		echo "Failed on $1"
		cd -
		./clean.sh
		exit -1
	fi
}

cd source
shopt -s nullglob

for CPP_FILE in *.cpp
do
	if [[ "$CPP_FILE" != "main.cpp" ]]
	then
		echo "Compiling $CPP_FILE"
		g++ -c "$CPP_FILE"
		check "compile $CPP_FILE"
	fi
done

OBJS=""

for O_FILE in *.o
do
	OBJS+="$O_FILE "
done

echo "Compiling texer shared object file..."
cd ..
cd ./exec
g++ -c -fPIC ../source/texer.cpp -o texer.o
check "compile texer.cpp"
g++ -shared -o texer.so texer.o
check "create texer shared file"
rm -f texer.o

cd ..
cd ./source

echo "Compiling main.cpp..."
g++ -o ../exec/rbtex ${OBJS::-1} main.cpp
cp ../exec/rbtex ../../product/	
check "compile main.cpp"
echo "DONE!"

exit 0
