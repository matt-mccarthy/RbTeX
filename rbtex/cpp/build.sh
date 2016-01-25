cd source
shopt -s nullglob

for CPP_FILE in *.cpp
do
	if [[ "$CPP_FILE" != "main.cpp" ]]
	then
		echo "Compiling $CPP_FILE"
		g++ -c "$CPP_FILE"
	fi
done

OBJS=""

for O_FILE in *.o
do
	OBJS+="$O_FILE "
done

echo "Compiling main.cpp"
g++ -o ../exec/rbtex ${OBJS::-1} main.cpp
