#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * take_string (int n){
    char *temp = malloc(n * sizeof(char));
    return temp;
}

void reverseWords(char *a, char *t){
    int n = strlen(a);

    int word = 0, k = 0, start =  n - 1, end = n - 1;
    for(int i = n - 1; i >= -1 ; i--){
        if(a[i] == ' ' || i == -1){
            if(start != end){
                if(word != 0){
                    *(t+k) =' ';
                    k++;
                }
                word++; 
                for(int j = 1; j <= end - start; j++){
                    *(t+k) = *(a + start + j);
                    k++;
                }
                
            }
            end = start - 1;
            start = end;

        }
        else {
            start--;
        }
    }
    *(t + k) ='\0';

}
int main(){
    char *a, *t;
    a = take_string(1000);
    t = take_string(1000);
    scanf("%[^\n]s", a);
    reverseWords(a, t);
    free(a);
    printf("%s", t);
    free(t);

}