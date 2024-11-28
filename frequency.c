#include <stdio.h>
#include <stdlib.h>

int* takearray(){
    int *temp = (int *) malloc(10001 * sizeof(int));
    return temp;
}
int main(){
    int n;
    scanf("%d", &n);
    int *freq;
    freq = takearray();
    for(int i = 0; i < 10001; i++){
        *(freq + i) = 0;
    }
    for(int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        *(freq + t) =  *(freq + t) + 1;
    }
    int max = 0;
    for(int i = 0; i < 10001; i++ ){
        if(*(freq + i) > max){
            max = *(freq+i);
        }
    }
      for(int i = 0; i < 10001; i++ ){
        if(*(freq + i) == max){
            printf("%d ", i);
        }
    }
    free(freq);

}