int language;

void greetuser(char *username) {
  char local_4c [4];
  undefined4 local_48;
  char local_44 [64];
  
  if (language == 1) {
    local_4c[0] = 'H';
    local_4c[1] = 'y';
    local_4c[2] = 'v';
    local_4c[3] = -0x3d;
    local_48._0_1_ = -0x5c;
    local_48._1_1_ = -0x3d;
    local_48._2_1_ = -0x5c;
    local_48._3_1_ = ' ';
    builtin_strncpy(local_44,"päivää ",0xb);
  }
  else if (language == 2) {
    builtin_strncpy(local_4c,"Goed",4);
    local_48._0_1_ = 'e';
    local_48._1_1_ = 'm';
    local_48._2_1_ = 'i';
    local_48._3_1_ = 'd';
    builtin_strncpy(local_44,"dag!",4);
    local_44[4] = ' ';
    local_44[5] = '\0';
  }
  else if (language == 0) {
    builtin_strncpy(local_4c,"Hell",4);
    local_48._0_3_ = 0x206f;
  }
  strcat(local_4c,(char *)&username); //permet un overflow car la len max de username est de 72 (40 + 32)
  puts(local_4c);
  return;
}

int main(int ac,char **av) {
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  byte bVar5;
  char *pcVar6;
  char local_60 [40];
  char acStack_38 [36];
  char *local_14;
  
  bVar5 = 0;
  if (ac == 3) {
    pcVar6 = local_60;
    for (iVar1 = 19; iVar1 != 0; iVar1 = iVar1 + -1) {
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      pcVar6[2] = '\0';
      pcVar6[3] = '\0';
      pcVar6 = pcVar6 + 4;
    }
    //si len(av[1]) >= 40 local_60 et acStack_38 sont une seule et même string
    strncpy(local_60,av[1],40);
    strncpy(acStack_38,av[2],32);
    pcVar6 = "LANG";
    pcVar2 = getenv("LANG");
    local_14 = pcVar2;
    if (pcVar2 != (char *)0x0) {
      iVar1 = memcmp(pcVar2,"fi",2);
      if (iVar1 == 0) {
        language = 1;
        pcVar6 = pcVar2;
      }
      else {
        pcVar6 = local_14;
        iVar1 = memcmp(local_14,"nl",2);
        if (iVar1 == 0) {
          language = 2;
        }
      }
    }
    iVar1 = 0x13;
    pcVar2 = local_60;
    puVar4 = (undefined4 *)&stack0xffffff50;
    for (iVar3 = 0x13; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + ((uint)bVar5 * -2 + 1) * 4;
      puVar4 = puVar4 + (uint)bVar5 * -2 + 1;
    }
    greetuser(pcVar6);
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}