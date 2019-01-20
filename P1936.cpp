#include <iostream>

using namespace std;

int main(){
    int A, B;

    scanf("%d %d", &A, &B);

    if(A == 1){
        if(B == 2)
            printf("B\n");
        else   
            printf("A\n");
    }
    else if(A == 2){
        if(B == 1)
            printf("A\n");
        else   
            printf("B\n");
    }
    else{
        if(B == 1)
            printf("B\n");
        else
            printf("A\n");
    }

    return 0;
}