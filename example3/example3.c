#include <stdio.h>
#include <string.h>

void sketchy(int a, int b, int c) {
    char buffer1[5];

    // Stack
    // [0       ...      16][0 ... 16][0 ... 16]
    // [  pad   ][ buffer1 ][  sfp   ][  ret   ]

    // buffer1 is aligned to the end of the stack entry, so 5 bytes to reach sfp
    // sfp is 16 bytes
    // so ret's address = (buffer1 + 5) + sfp = (buffer1 + 5) + 16
    int *returnAddr = buffer1 + 21;

    // Skip the x = 1 instruction below. subsequent printf is BA - B3 = 7 bytes 
    // (1 8-byte word) away from the original return address per gdb disas main.
    (*returnAddr) += 8;
}

int main(int argc, char *argv[]) {
    int x = 0;

    sketchy(1, 2, 3);
    x = 1;  // This will be skipped
    printf("successful overflow will be zero\n");
    printf("result: %d\n", x);

    return 0;
}
