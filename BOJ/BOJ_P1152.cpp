#include <iostream>
#include <stdio.h>

#define MAX 1000001     // 입력받을 수 있는 문자열의 최대 크기
using namespace std;

int main() {
	char str[MAX];      // 입력 받은 문자열을 저장하는 변수
	int index = 0;         // 배열을 탐색할 위치 변수
	int answer = 0;         // 단어의 개수
	bool flag = false;      // 띄어쓰기 구분을 위한 flag

	gets(str);      // 문자열을 입력

	while (str[index] != '\0') {
		if (str[index] != ' ')
			flag = true;        // 처음에 띄어쓰기로 시작한 부분때문에 문장이 시작한 것을 알기 위한 장치
		else if(str[index] == ' ' && flag ) {
			flag = false;
			answer++;
		}       // 띄어쓰기를 기준으로 단어의 개수를 세도록 설정
		index++;
	}
	if(flag)
		answer++;       // 띄어쓰기를 기준으로 했기 때문에 마지막 단어를 세기 위한 작업

	printf("%d\n", answer);

}