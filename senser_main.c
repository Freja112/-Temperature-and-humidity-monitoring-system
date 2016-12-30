#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <linux/kdev_t.h>
#include "gpio.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <curses.h>
#include <signal.h>

#define SOUND 0
#define INFRARED 1
#define LED1 4
#define LED2 5

void *sound();
void *infrared();

void int_handler();

void *sound(){
	while(1){
        pinMode(SOUND, INPUT);
        pinMode(LED1, OUTPUT);
        
        while(1) {
            if(digitalRead(SOUND) == LOW) {
                digitalWrite(LED1, 1);
            }
            else {
                digitalWrite(LED1, 0);
            }
        }
	}
}

void *infrared(){
    pinMode(INFRARED, INPUT);
    pinMode(LED2, OUTPUT);
    
    while(1) {
        if(digitalRead(INFRARED) == LOW) {
            digitalWrite(LED2, 1);
        }
        else {
            digitalWrite(LED2, 0);
        }
    }
}

int main(void){
	pthread_t thread1, thread2;
	int status1, status2;

	signal(SIGINT, (void *)int_handler);

	if (wiringPiSetup() == -1) {
		exit(1);
	}

	pthread_create(&thread1, NULL, sound, NULL);
	pthread_create(&thread2, NULL, infrared, NULL);
	
	pthread_join(thread1, (void **)&status1);
	pthread_join(thread2, (void **)&status2);

	return 0;
}

void int_handler(){
    printf("Quit\n");
	exit(EXIT_SUCCESS);
}
