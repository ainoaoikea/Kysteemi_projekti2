#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decode(char* ifile, char* ofile);

int main(int argc, char* argv[]){
  //my-unzip input.z output.txt
  FILE* file;
  //FILE* filew;
  char* dest;
  size_t len = 0;
  ssize_t nread;
  char* line = NULL;
  int slen;

  
  file = fopen(argv[1], "r");
  if (file == NULL){
  	fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
  	exit(1);
  }
  
  //filew = fopen(argv[2], "w");
  
  while ((nread = getline(&line, &len, file)) != -1) {
  	 slen = strlen(line);
  	 //line[slen-1] = 0;
  	 printf("%s\n", line);
  	 //strcpy(dest, rle(line));
  	 //printf("%s\n", dest);
  	 //fwrite(dest, slen, 4, filew);
  }
  
  fclose(file);
  //fclose(filew);

  return 0;
}

void decode(char* ifile, char* ofile){
  
}
