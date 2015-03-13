SOURCE=rando.c
HEADER=rando.h
OBJECT=rando.o
ALLBITS=$(OBJECT)
ALLHEADERS=$(HEADER)
OUT=rando
TESTIN=test.txt
TESTOUT=test.out

all : run

clean:
	rm -f $(OUT) *.o *.out

printBytes.o: printBytes.c printBytes.h
	gcc -c printBytes.c -o printBytes.o

$(OBJECT): $(SOURCE) $(HEADER)
	gcc -c $(SOURCE) -o $(OBJECT)


compile: clean $(ALLBITS)
	gcc $(ALLBITS) -o $(OUT)

run: compile
	./$(OUT)

$(TESTOUT):
	cat "" > $(TESTOUT)

test: compile $(TESTIN)
	cat $(TESTIN) | ./$(OUT) | diff $(TESTOUT) -

debug: compile $(TESTIN)
	cat $(TESTIN) | ./$(OUT)

