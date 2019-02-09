#include <iostream>
#include <string>

using namespace std;

int main(){
    int T;

    scanf("%d", &T);

    for(int i = 0;i < T;i++){
        string problem;
        int score = 0;
        int answer = 0;

        cin >> problem;

        for(int j = 0;j < problem.size();j++){
            if(problem[j] == 'O')
                score++;
            else
                score = 0;
            answer += score;
        }

        printf("%d\n", answer);
    }

    return 0;
}