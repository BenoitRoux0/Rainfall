int main(int param_1,char **param_2) {
  int iVar1;
  char local_3c [40];
  
  iVar1 = atoi(param_2[1]);
  if (iVar1 < 10) {
    memcpy(local_3c,param_2[2],iVar1 * 4);
    if (iVar1 == 0x574f4c46) {
      execl("/bin/sh","sh",0);
    }
    iVar1 = 0;
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}
