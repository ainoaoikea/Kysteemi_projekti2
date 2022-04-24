#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int run_length(char* s) {
  char c = s[0];
  if (c == '\0') return 0;
  int length = 1;
  for(; s[length] == c; length++);
  return length;
}

int strlen_i(int i) {
  return snprintf(NULL, 0, "%i", i);
}

int rle_len(char* s) {
  int len = 0;
  int rl = run_length(s);
  while (rl > 0) {
    len += 1 + strlen_i(rl);
    s += rl;
    rl = run_length(s);
  }
  return len;
}

char* rle(char* s) {
  int old_len = strlen(s);
  int new_len = rle_len(s);

  if (old_len <= new_len) {
    return strdup(s); // provides free()able copy
  }

  //char* out = malloc((new_len+1) * sizeof(char));
  char* out = (char*)malloc(sizeof(char) * (old_len * 2 + 1));
  
  int out_next = 0;
  int rl = run_length(s);
  while (rl > 0) {
    out_next += sprintf(&out[out_next], "%i%c", rl, s[0]);
    s += rl;
    rl = run_length(s);
  }
  out[out_next] = '\0';

  return out;
}


int main(int argc, char* argv[]) {

  FILE* file;
  FILE* filew;
  char* dest;
  size_t len = 0;
  ssize_t nread;
  char* line = NULL;
  int slen;
  //char ifile;
  //strcpy(ifile, argv[1]);
  
  file = fopen(argv[1], "r");
  if (file == NULL){
  	fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
  	exit(1);
  }
  
  filew = fopen(argv[2], "w");
  
  while ((nread = getline(&line, &len, file)) != -1) {
  	 slen = strlen(line);
  	 line[slen-1] = 0;
  	 strcpy(dest, rle(line));
  	 printf("%s\n", dest);
  	 fwrite(dest, 4, sizeof(dest), filew);
  }
  
  fclose(file);
  fclose(filew);

  return 0;
}
