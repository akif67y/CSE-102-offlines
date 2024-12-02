#include <stdio.h>


struct Example {
    double a;
    short b;
    int ara[3];
 
};
    

int main() {
    printf("size of %d\n\n\n", sizeof(short));
    printf("Size of Example: %zu bytes\n", sizeof(struct Example));
    return 0;
}
// #include<stdio.h>
// struct hey{
// 	int a;
// 	double b;
// 	int arr[101];
// 	int brr[50];
// 	};
// int main(){
// 	printf("%d",sizeof(struct hey));
// }