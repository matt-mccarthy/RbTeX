cd source

for O_FILE in *.o
do
	rm -f $O_FILE
done

cd ../exec

if [[ -e rbtex ]]
then
	rm -f rbtex
fi

if [[ -e texer.so ]]
then
	rm -f texer.so
fi
