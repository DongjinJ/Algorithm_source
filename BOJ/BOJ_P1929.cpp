#include <iostream>
#include <string.h>

#define MAX 1000001
using namespace std;

int main(){
    int M, N;
    scanf("%d %d", &M, &N);

    bool prime_num[MAX];
    memset(prime_num, true, sizeof(prime_num));
    prime_num[0] = false;
    prime_num[1] = false;

    for(int i = 2;i <= N;i++){
        if(prime_num[i]){
            for(int j = 2;j*i <= N;j++){
                if(prime_num[i*j])
                    prime_num[i*j] = false;
                else
                    ;
            }
        }
        else
            ;
    }
    
    for(int i = M;i <= N;i++){
        if(prime_num[i])
            printf("%d\n",i);
        else
            ;
    }

    return 0;
}