#include <iostream>
#include <string.h>

#define MAX 246913
using namespace std;

int main(){
    int n;
    bool prime_num[MAX];
    memset(prime_num, true, sizeof(prime_num));
    prime_num[0] = false;
    prime_num[1] = false;

    for(int i = 2;i < MAX;i++){
        if(prime_num[i]){
            for(int j = 2;j*i < MAX;j++){
                if(prime_num[i*j])
                    prime_num[i*j] = false;
                else
                    ;
            }
        }
        else
            ;
    }
    while(true){
        scanf("%d", &n);
        if(n == 0)
            break;
        int answer = 0;
        for(int i = n + 1;i <= 2*n;i++){
            if(prime_num[i])
                answer++;
            else
                ;
        }

        printf("%d\n", answer);
    }

    return 0;
}