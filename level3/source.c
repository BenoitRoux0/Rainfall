#include <stdio.h>

int m;

void v(void) {
  char local_20c [520];
  
  fgets(local_20c,512,stdin);
  printf(local_20c);
  if (m == 64) {
    fwrite("Wait what?!\n",1,0xc,stdout);
    system("/bin/sh");
  }
  return;
}

void main(void) {
  v();
  return;
}
