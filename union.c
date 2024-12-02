#include <stdio.h>
int main(){
    typedef union drim{
        int n;
        unsigned char x[4];  // as each integer is of 4 bytes
    }pajn;
    
    pajn t;
    t.n = 56785394;
    printf("Original number in decimal : %d \n In hexadecimal : %X\n", t.n, t.n);
    printf("Now, Each bit in hexa:\n");
    printf("%X\n", t.x[0]);
    printf("%X\n", t.x[1]);
    printf("%X\n", t.x[2]);
    printf("%X\n", t.x[3]);



}