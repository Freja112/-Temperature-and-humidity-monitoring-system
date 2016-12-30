#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

void main(){
	int i=0;
	FILE *fd;
	char buffer[7][20];
	fd = fopen("dht_info.txt", "r");

	while(fgets(buffer[i], 20, fd)){
		i++;
	}

	printf("Content-type:text/html\n\n");

	int j;	
	for(j=0; j<7; j++) {
		if(j != 0) {
			printf(",");
		}
		printf("%s", buffer[j]);
	}

	fclose(fd);
}
