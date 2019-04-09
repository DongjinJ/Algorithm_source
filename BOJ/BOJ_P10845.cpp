#include <iostream>
#include <string>

using namespace std;

class queue{
    int data[10000];
    int front_ptr = 0;
    int rear_ptr = 0;
public:
    queue(){
        front_ptr = 0;
        rear_ptr = 0;
    }
    void push(int X){
        data[rear_ptr++] = X;
    }
    void pop(){
        if(front_ptr == rear_ptr)
            printf("-1\n");
        else
            printf("%d\n", data[front_ptr++]);
    }
    void size(){
        printf("%d\n", rear_ptr - front_ptr);    
    }
    void empty(){
        if(front_ptr == rear_ptr)
            printf("1\n");
        else
            printf("0\n");
    }
    void front(){
        if(front_ptr == rear_ptr)
            printf("-1\n");
        else   
            printf("%d\n", data[front_ptr]);
    }
    void back(){
        if(front_ptr == rear_ptr)
            printf("-1\n");
        else
            printf("%d\n", data[rear_ptr - 1]);
    }
};
int main(){
    int N;
    scanf("%d\n", &N);

    queue q;
    for(int j = 0;j < N;j++){
        string instruct;
        getline(cin, instruct);

        string oper = "";
        string num = "";
        bool div = false;
        for(int i = 0;i < instruct.size();i++){
            if(!div && instruct[i] != ' ')
                oper += instruct[i];
            else if(instruct[i] == ' ')
                div = true;
            else
                num += instruct[i];        
        }
        int data = atoi(num.c_str());
        if(oper == "push")
            q.push(data);
        else if(oper == "pop")
            q.pop();
        else if(oper == "size")
            q.size();
        else if(oper == "empty")
            q.empty();
        else if(oper == "front")
            q.front();
        else if(oper == "back")
            q.back();
        else
            ;
    }
    
    return 0;
}