#include <iostream>
#include <string>

using namespace std;

void solution(int sum) {
	string str;
	int num[10] = { 0, };       // 0 ~ 9까지 각 자리수의 개수를 기록하는 변수

	str = to_string(sum);       // int type의 변수를 string type으로 바꿔주는 변수

	for (int i = 0; i < str.length(); i++)
		num[str[i] - '0']++;    // 곱셈 결과 값을 맨 앞자리부터 탐색하면서 개수를 세는 과정
	
	for (int i = 0; i < 10; i++)
		printf("%d\n", num[i]);     // 결과 값 출력

}
int main() {
	int A, B, C;
	int sum;

	scanf("%d %d %d", &A, &B, &C);

	sum = A * B * C;

	solution(sum);
}