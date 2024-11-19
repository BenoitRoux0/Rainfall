int main(void) {
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar7;
  bool bVar8;
  undefined uVar9;
  undefined uVar10;
  bool bVar11;
  undefined uVar12;
  byte bVar13;
  byte local_90 [5];
  char local_8b [2];
  char acStack_89 [125];
  char *pbVar6;
  
  bVar13 = 0;
  do {
    printf("%p, %p \n",auth,service);
    pcVar2 = fgets((char *)local_90,0x80,stdin);
    bVar8 = false;
    bVar11 = pcVar2 == (char *)0x0;
    if (bVar11) {
      return 0;
    }
    iVar3 = 5;
    pbVar5 = local_90;
    pbVar7 = (byte *)"auth ";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar8 = *pbVar5 < *pbVar7;
      bVar11 = *pbVar5 == *pbVar7;
      pbVar5 = pbVar5 + (uint)bVar13 * -2 + 1;
      pbVar7 = pbVar7 + (uint)bVar13 * -2 + 1;
    } while (bVar11);
    uVar9 = 0;
    uVar12 = (!bVar8 && !bVar11) == bVar8;
    if ((bool)uVar12) {
      auth = (char *)malloc(4);
      *(undefined4 *)auth = L'\0';
      uVar4 = 0xffffffff;
      pcVar2 = local_8b;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + (uint)bVar13 * -2 + 1;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4 - 1;
      uVar9 = uVar4 < 0x1e;
      uVar12 = uVar4 == 0x1e;
      if (uVar4 < 31) {
        strcpy(auth,local_8b);
      }
    }
    iVar3 = 5;
    pbVar5 = local_90;
    pbVar7 = (byte *)"reset";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      uVar9 = *pbVar5 < *pbVar7;
      uVar12 = *pbVar5 == *pbVar7;
      pbVar5 = pbVar5 + (uint)bVar13 * -2 + 1;
      pbVar7 = pbVar7 + (uint)bVar13 * -2 + 1;
    } while ((bool)uVar12);
    uVar10 = 0;
    uVar9 = (!(bool)uVar9 && !(bool)uVar12) == (bool)uVar9;
    if ((bool)uVar9) {
      free(auth);
    }
    iVar3 = 6;
    pbVar5 = local_90;
    pbVar6 = (byte *)"service";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      uVar10 = *pbVar5 < *pbVar6;
      uVar9 = *pbVar5 == *pbVar6;
      pbVar5 = pbVar5 + (uint)bVar13 * -2 + 1;
      pbVar6 = pbVar6 + (uint)bVar13 * -2 + 1;
    } while ((bool)uVar9);
    uVar12 = 0;
    uVar9 = (!(bool)uVar10 && !(bool)uVar9) == (bool)uVar10;
    if ((bool)uVar9) {
      uVar12 = (byte *)0xfffffff8 < local_90;
      uVar9 = acStack_89 == (char *)0x0;
      service = strdup(acStack_89);
    }
    iVar3 = 5;
    pbVar5 = local_90;
    pbVar7 = (byte *)"login";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      uVar12 = *pbVar5 < *pbVar7;
      uVar9 = *pbVar5 == *pbVar7;
      pbVar5 = pbVar5 + (uint)bVar13 * -2 + 1;
      pbVar7 = pbVar7 + (uint)bVar13 * -2 + 1;
    } while ((bool)uVar9);
    if ((!(bool)uVar12 && !(bool)uVar9) == (bool)uVar12) {
      if (*(int *)(auth + 32) == L'\0') {
        fwrite("Password:\n",1,10,stdout);
      }
      else {
        system("/bin/sh");
      }
    }
  } while( true );
} 