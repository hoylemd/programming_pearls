SOURCE=sorter.o
OUT=sorter
TESTIN=nums.txt

all : run

clean:
	rm -f $(OUT) *.o *.out

printBytes.o: printBytes.c printBytes.h
	gcc -c printBytes.c -o printBytes.o

sorter.o: sorter.c sorter.h
	gcc -c sorter.c -o sorter.o


compile: clean $(SOURCE)
	gcc $(SOURCE) -o $(OUT)

run: compile
	./$(OUT)

test: compile $(TESTIN) test.sh
	./test.sh $(TESTIN)

debug: compile $(TESTIN)
	cat $(TESTIN) | ./$(OUT)

