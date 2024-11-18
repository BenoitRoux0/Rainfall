#include <time.h>
#include <stdio.h>

struct astruct {
    int field0_0x0;
    char * field1_0x4;
};

char token[80];

void m(void *param_1,int param_2,char *param_3,int param_4,int param_5) {
  time_t current_time;
  
  current_time = time((time_t *)0);
  printf("%s - %d\n",token,current_time);
  return;
}


int main(int ac,char **av) {
  struct astruct *puVar1;
  char *tmp_str;
  struct astruct *puVar2;
  FILE *token_file;
  
  puVar1 = (struct astruct *)malloc(8);
  puVar1->field0_0x0 = 1;
  tmp_str = (char *)malloc(8);
  puVar1->field1_0x4 = tmp_str;
  puVar2 = (struct astruct *)malloc(8);
  puVar2->field0_0x0 = 2;
  tmp_str = (char *)malloc(8);
  puVar2->field1_0x4 = tmp_str;
  strcpy(puVar1->field1_0x4,av[1]);
  strcpy(puVar2->field1_0x4,av[2]);
  token_file = fopen("/home/user/level8/.pass","r");
  fgets(token,68,token_file);
  puts("~~");
  return 0;
}
