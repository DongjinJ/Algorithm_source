#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){
    string N;

    cin >> N;

    int count[10];
    memset(count, 0, sizeof(count));

    for(int i = 0;i < N.size();i++)
        count[N[i] - '0']++;
    
    for(int i = 9;i >= 0;i--)
        for(int j = 0;j < count[i];j++)
            printf("%d", i);
    cout << endl;

    return 0;
}