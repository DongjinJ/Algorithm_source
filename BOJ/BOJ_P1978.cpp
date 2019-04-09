#include <iostream>
#include <string.h>

#define MAX 1001

using namespace std;

bool prime_num[MAX];

int main(){
    int N;
    scanf("%d", &N);

    memset(prime_num, true, sizeof(prime_num));
    
    prime_num[1] = false;
    
    for(int i = 2;i < MAX;i++){
        if(prime_num[i]){
            for(int j = 2;j*i < MAX;j++)
                prime_num[j*i] = false;
        }
        else
            ;
    }
    int answer = 0;
    for(int i = 0;i < N;i++){
        int temp;
        scanf("%d", &temp);
        if(prime_num[temp])
            answer++;
        else
            ;
    }
    printf("%d\n", answer);

    return 0;
}