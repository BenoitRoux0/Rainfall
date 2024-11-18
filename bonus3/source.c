#include <stdio.h>

int main(int param_1,char **param_2) {
  int iVar1;
  char *pcVar2;
  char bVar3;
  char local_98 [65];
  char local_57;
  char local_56 [66];
  FILE *local_14;
  
  bVar3 = 0;
  local_14 = fopen("/home/user/end/.pass","r");
  pcVar2 = local_98;
  for (iVar1 = 0x21; iVar1 != 0; iVar1 = iVar1 + -1) {
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    pcVar2 = pcVar2 + 4;
  }
  if ((local_14 == (FILE *)0x0) || (param_1 != 2)) {
    iVar1 = -1;
  }
  else {
    fread(local_98,1,0x42,local_14);
    local_57 = 0;
    iVar1 = atoi(param_2[1]);
    local_98[iVar1] = '\0'; 
    fread(local_56,1,0x41,local_14);
    fclose(local_14);
    iVar1 = strcmp(local_98,param_2[1]);
    if (iVar1 == 0) {
      execl("/bin/sh","sh",0);
    }
    else {
      puts(local_56);
    }
    iVar1 = 0;
  }
  return iVar1;
}