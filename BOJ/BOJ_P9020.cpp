#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>

#define MAX 10001
using namespace std;

int main(){
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

    int T;
    scanf("%d", &T);
    
    for(int i = 0;i < T;i++){
        int n;
        scanf("%d", &n);

        int min = 10000;
        int answer[2];
        bool find = false;
        for(int j = n/2;j >= 2;j--){
            if(prime_num[j]){
                for(int k = j;k < n;k++){
                    if(prime_num[k]){
                        if(j + k == n){
                            printf("%d %d\n", j, k);
                            find = true;
                            break;
                        }
                            
                    }
                    else    
                        ;
                }
            }
            else
                ;
            if(find)
                break;
        }
    }

    return 0;
}