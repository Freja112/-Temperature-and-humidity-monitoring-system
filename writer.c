#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void writer(float *fValue, int sen_num){
	FILE *fd;
	int i=0, len;
	char buffer[7][20];
	char sValue[2][20];
	time_t timer;
	struct tm *timeinfo;

	time(&timer);
	timeinfo = localtime(&timer);

	snprintf(sValue[0], 20, "%.2f", fValue[0]);
	snprintf(sValue[1], 20, "%.2f", fValue[1]);
	len = strlen(sValue[0]);
	sValue[0][len-1] = '\n';
	sValue[0][len] = '\0';
	len = strlen(sValue[1]);
	sValue[1][len-1] = '\n';
	sValue[1][len] = '\0';

	fd = fopen("/usr/lib/cgi-bin/dht_info.txt", "r");
	while(fgets(buffer[i++], 20, fd)){}
	fclose(fd);

	sleep(1);
	switch(sen_num){
		case 0:
			strcpy(buffer[0], sValue[0]);
			strcpy(buffer[1], sValue[1]);
			break;
		case 1:
			strcpy(buffer[2], sValue[0]);
			strcpy(buffer[3], sValue[1]);
			break;
	}

	strftime(buffer[6], 20, "%m.%d&nbsp;%H:%M:%S", timeinfo);

	fd = fopen("/usr/lib/cgi-bin/dht_info.txt", "w");
	for(i=0; i<7; i++){
		fputs(buffer[i], fd);
	}
	fclose(fd);
}

void writer_Pow(char *sPowValue, int sen_num){
	FILE *fd;
	int i=0, len;
	char buffer[7][20];

	fd = fopen("/usr/lib/cgi-bin/dht_info.txt", "r");
	while(fgets(buffer[i++], 20, fd)){}
	fclose(fd);

	sleep(1);
	switch(sen_num){
		case 0:
			strcpy(buffer[4], sPowValue);
			break;
		case 1:
			strcpy(buffer[5], sPowValue);
			break;
	}

	fd = fopen("/usr/lib/cgi-bin/dht_info.txt", "w");
	for(i=0; i<7; i++){
		fputs(buffer[i], fd);
	}
	fclose(fd);
}