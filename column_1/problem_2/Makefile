SOURCE=sorter.c
OUT=sorter

all : run

clean:
	rm $(OUT)

compile: clean $(SOURCE)
	gcc $(SOURCE) -o $(OUT)

run: compile
	./$(OUT)


