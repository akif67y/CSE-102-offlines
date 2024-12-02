
#include<stdio.h>
#include<string.h>

union U {
    unsigned int i;
    unsigned char x[4];
};


int main(){
    printf("Size: %d\n", sizeof(union U));
    union U u;
    u.i = 435643654;
    // BGR
    // x[0] = R
    // x[1] = G
    // x[2] = B
    // x[3] = 0
    printf("%X\n", u.i);
    printf("%X\n", u.x[0]);
    printf("%X\n", u.x[1]);
    printf("%X\n", u.x[2]);
    printf("%X\n", u.x[3]);
    return 0;
}