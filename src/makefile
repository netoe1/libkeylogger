keyboard.o: keyboard.c keyboard.o
	gcc -c keyboard.c -o ./bin/keyboard.o
clocktime.o: clocktime.h clocktime.c
	gcc -c clocktime.c -o ./bin/clocktime.o
main.o: winvk.h
	gcc -o ./bin/main main.c ./bin/keyboard.o ./bin/clocktime.o 

all:
	make keyboard.o clocktime.o main.o
run:
	./main