#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int main(int argc, char* argv[]){

	
	FILE *file = fopen(argv[2], "r");
	if (file == NULL) {
		printf("my-cat: cannot open file\n");
		exit(1);
	}
		
	char buffer[SIZE];
	
	printf("lines with word %s in it:\n", argv[1]);
	
	while(fgets(buffer, SIZE-1, file) != NULL) {
		if (strstr(buffer, argv[1])){
			printf("%s", buffer);
		}
	}
	fclose(file);
}
