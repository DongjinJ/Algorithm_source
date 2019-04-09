#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string problem;
    cin >> problem;

    stack<string> stk;
    bool wrong = false;
    int index = 0;
    int answer = 0;
    for(int i = 0;i < problem.size();i++){
        if(problem[i] == '(')
            stk.push("(");
        else if(problem[i] == '[')
            stk.push("[");
        else if(!stk.empty() && (problem[i] == ')' || problem[i] == ']')){       
            if(problem[i] == ')'){
                int temp = 0;
                if(stk.top() == "["){
                    wrong = true;
                    break;
                }
                while(!stk.empty() && stk.top() != "[" && stk.top() != "("){
                    string num;
                    num = stk.top();
                    temp += atoi(num.c_str());
                    stk.pop();
                }
                if(!stk.empty() && stk.top() == "("){
                    if(temp != 0)
                        temp *= 2;
                    else
                        temp = 2;
                    stk.pop();
                    stk.push(to_string(temp));
                }
                else{
                    wrong = true;
                    break;
                }
            }
            else if(problem[i] == ']'){
                int temp = 0;
                if(stk.top() == "("){
                    wrong = true;
                    break;
                }
                while(!stk.empty() && stk.top() != "(" && stk.top() != "["){
                    string num;
                    num = stk.top();
                    temp += atoi(num.c_str());
                    stk.pop();
                }
                if(!stk.empty() && stk.top() == "["){
                    if(temp != 0)
                        temp *= 3;
                    else
                        temp = 3;
                    stk.pop();
                    stk.push(to_string(temp));
                }
                else{
                    wrong = true;
                    break;
                }
            }
            else{
                wrong = true;
                break;
            }
        }
        else{
            wrong = true;
            break;
        }
    }
    if(!wrong && (stk.top() == "(" || stk.top() == "["))
        wrong = true;
    else{
        while(!stk.empty()){
            if(stk.top() == "(" || stk.top() == "["){
                wrong = true;
                break;
            }
            string tmp = stk.top();
            answer += atoi(tmp.c_str());
            stk.pop();
        }
    }

    if(wrong)
        printf("0\n");
    else
        printf("%d\n", answer);

    return 0;
}