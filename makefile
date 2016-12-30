senser_main: senser_main.o dht11.o display.o writer.o
	gcc -o senser_main senser_main.o dht11.o display.o writer.o -lpthread -lwiringPi -lcurses
senser_main.o: senser_main.c
	gcc -c senser_main.c -lpthread
dht11.o: dht11.c
	gcc -c dht11.c -lwiringPi
display.o: display.c
	gcc -c display.c -lcurses
writer.o: writer.c
	gcc -c writer.c
