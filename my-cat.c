#include <stdio.h>
#include <stdlib.h>


#define SIZE 250

int main(int argc, char* argv[]){

	
	printf("number of files: %d \n", argc-1);
	for (int i=1; i <= argc-1; i++) {
		FILE *file = fopen(argv[i], "r");
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
}
