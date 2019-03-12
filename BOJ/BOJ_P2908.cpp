#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

int main()
{
    string A, B;

    cin >> A >> B;

    string temp;            // 뒤집은 문자열을 임시로 저장하는 변수
    for (int i = A.size() - 1; i < A.size(); i--){
        temp += A[i];
    }               // A의 맨 뒤 문자를 탐색해 임시 변수의 앞부터 저장
    A = temp;       // 임시 변수를 A에 덮어씌움
    temp = "";      // 임시 변수 초기화
    for (int i = B.size() - 1; i < B.size(); i--){
        temp += B[i];
    }               // B의 맨 뒤 문자를 탐색해 임시 변수의 앞부터 저장
    B = temp;       // 임시 변수를 B에 덮어씌움
    temp = "";      // 임시 변수 초기화

    if(atoi(A.c_str()) > atoi(B.c_str()))           // string type을 char* type으로 바꾼 뒤 int형으로 변환해 대소비교
        printf("%s\n", A.c_str());                  // A가 클 경우
    else
        printf("%s\n", B.c_str());                  // B가 클 경우

    return 0;
}