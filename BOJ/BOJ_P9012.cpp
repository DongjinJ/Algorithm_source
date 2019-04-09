#include <iostream>
#include <string>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);

    for(int i = 0;i < T;i++){
        string parenthesis;
        cin >> parenthesis;
        int open = 0;
        for(int j = 0;j < parenthesis.size();j++){
            if(parenthesis[j] == '(')
                open++;
            else if(parenthesis[j] == ')')
                open--;
            
            if(open < 0)
                break;
        }
        if(open == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}