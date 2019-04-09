#include <iostream>
#include <string.h>

#define MAX 10001

using namespace std;

int main(){
    bool prime_num[MAX];
    memset(prime_num, true, sizeof(prime_num));

    prime_num[0] = false;
    prime_num[1] = false;

    int M, N;
    scanf("%d\n%d", &M, &N);

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

    int sum = 0;
    int min = N;
    for(int i = M;i <= N;i++){
        if(prime_num[i]){
            sum += i;
            if(min > i)
                min = i;
        }
        else
            ;
        
    }
    if(sum == 0)
        printf("-1\n");
    else
        printf("%d\n%d", sum, min);

    return 0;
}