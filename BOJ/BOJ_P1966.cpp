#include <iostream>
#include <queue>

using namespace std;

const int MAX = 101;

int main(){
    int T;
    scanf("%d", &T);
    
    for(int i = 0;i < T;i++){
        priority_queue<int> priority;
        queue<pair<int, int>> wait;
        int answer = 0;
        int index = 0;

        int N, M;
        scanf("%d %d", &N, &M);

        for(int j = 0;j < N;j++){
            int temp;
            scanf("%d", &temp);
            wait.push({temp, j});
            priority.push(temp);
        }
        while(!wait.empty()){
            int temp = wait.front().first;
            int index = wait.front().second;
            wait.pop();
            if(temp == priority.top()){
                priority.pop();
                answer++;
                if(index == M){
                    printf("%d\n", answer);
                    break;
                }
            }
            else{
                wait.push({temp, index});
            }
        }
    }
    return 0;
}