#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Stack{
private:
    int data[10000];
    int index;
public:
    Stack(){
        index = 0;
        memset(data, 0, sizeof(data));
    }

    void push(int X){
        data[index++] = X;
    }

    void pop(){
        if(index != 0)
            printf("%d\n", data[--index]);
        else
            printf("-1\n");
    }

    void size(){
        printf("%d\n", index);
    }

    void empty(){
        if(index == 0)
            printf("1\n");
        else
            printf("0\n");
    }

    void top(){
        if(index == 0)
            printf("-1\n");
        else
            printf("%d\n", data[index - 1]);
    }
};

int main(){
    int N;
    scanf("%d\n", &N);
    Stack ST;

    for(int i = 0;i < N;i++){
        string instruct;
        getline(cin, instruct);
        
        string order = "";
        string num = "";
        bool cut = false;
        for(int i = 0;i < instruct.size();i++){
            if(!cut){
                if(instruct[i] != ' ')
                    order += instruct[i];
                else
                    cut = true;
            }
            else{
                num += instruct[i];
               
            }
        }
  
        int data = atoi(num.c_str());
        
        if(order.compare("push") == 0)
            ST.push(data);
        else if(order.compare("pop") == 0)
            ST.pop();
        else if(order.compare("size") == 0)
            ST.size();
        else if(order.compare("empty") == 0)
            ST.empty();
        else if(order.compare("top") == 0)
            ST.top();
        else
            ;
        
    }
    
    return 0;
}