make: clean main.c
	gcc main.c -o main.out

run: make
	./main.out

clean:
	rm -rf *~
	#rm -rf *#
	rm -rf make.out
