cat $1 | sort -n > test.out
cat $1 | ./sorter | diff test.out -
