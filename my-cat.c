#include <stdio.h>
#include <stdlib.h>


#define SIZE 250

int main(int argc, char* argv[]){

	
	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		printf("my-cat: cannot open file\n");
		exit(1);
	}
		
	char buffer[SIZE];
	
	while(fgets(buffer, SIZE-1, file) != NULL) {
		printf("%s", buffer);
	}
	fclose(file);
}
