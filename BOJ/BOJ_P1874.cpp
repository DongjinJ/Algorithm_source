#include <iostream>

using namespace std;

int main(){
    int stack[100000];
    int index = 0;

    int n;
    scanf("%d", &n);

    int problem[100000];
    for(int i = 0;i < n;i++)
        scanf("%d", &problem[i]);
    
    int x = 1;
    int ptr = 0;
    string answer = "";
    bool possible = true;

    while(ptr < n){
        if(index == 0){
            stack[index++] = x++;
            answer += "+";
        }
        else if(stack[index - 1] != problem[ptr] && x <= problem[ptr]){
            stack[index++] = x++;
            answer += "+";
        }
        else if(stack[index - 1] == problem[ptr] && index > 0){
            stack[--index] = 0;
            answer += "-";
            
            ptr++;
        }
        else{
            possible = false;
            break;
        }
        
    }
    if(possible){
        for(int i = 0;i < answer.size();i++)
            printf("%c\n", answer[i]);
    }
    else
        printf("NO\n");

    return 0;
}