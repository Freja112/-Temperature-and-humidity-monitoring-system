#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

void main(){
	int i=0, j;
	FILE *fd;
	char buffer[512][512];
	fd = fopen("static_view.html", "r");

	while(fgets(buffer[i], 512, fd)){
		i++;
	}

	printf("Content-type:text/html\n\n");

	for(j=0; j<i; j++){
		printf("%s" ,buffer[j]);
	}
	fclose(fd);
}
