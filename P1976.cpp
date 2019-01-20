#include <iostream>

using namespace std;

int main(){
    int T;

    scanf("%d", &T);

    int hour1, minute1, hour2, minute2;

    for(int i = 0;i < T;i++){
        scanf("%d %d %d %d", &hour1, &minute1, &hour2, &minute2);
        minute1 += minute2;
        if(minute1 > 59){
            hour1++;
            minute1 -= 60;
        }
        hour1 += hour2;
        if(hour1 > 12)
            hour1 -= 12;
        printf("#%d %d %d\n", i+1, hour1, minute1);
        
    }

    return 0;
}