#include <iostream>
#include <string.h>

#define num_MAX 10001

using namespace std;


int main(){
    int N;
    scanf("%d", &N);

    int count[num_MAX];
    memset(count, 0, sizeof(count));

    for(int i = 0;i < N;i++){
        int temp;
        scanf("%d", &temp);
        count[temp]++;
    }
    
    for(int i = 0;i < num_MAX;i++){
        if(count[i] != 0){
            for(int j = 0;j < count[i];j++)
                printf("%d\n", i);
        }
    }

    return 0;

}