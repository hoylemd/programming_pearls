SOURCE=sorter.c
OUT=sorter
TESTIN=nums.txt

all : run

clean:
	rm -f $(OUT)

compile: clean $(SOURCE)
	gcc $(SOURCE) -o $(OUT)

run: compile
	./$(OUT)

test: compile $(TESTIN)
	cat $(TESTIN) | ./$(OUT)

