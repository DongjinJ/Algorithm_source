#include <iostream>
#include <memory.h>
char space[3072][6144];		// 별을 찍을 공간 생성 k값이 최대 10까지인 것을 고려하여 배열 크기 생성)

void star(int N, int x, int y) {
	if (N == 3) {
		space[y][x] = '*';
		space[y + 1][x - 1] = '*';
		space[y + 1][x + 1] = '*';
		space[y + 2][x - 2] = '*';
		space[y + 2][x - 1] = '*';
		space[y + 2][x] = '*';
		space[y + 2][x + 1] = '*';
		space[y + 2][x + 2] = '*';
		return;
	}		// 별 한세트를 찍는 구문
	
	star(N / 2, x, y);		// 벌의 윗부분을 찍는 재귀 호출
	star(N / 2,x - (N / 2), y + (N / 2));	// 별의 좌하단 삼각형을 찍는 재귀 호출
	star(N / 2, x + (N / 2), y + (N / 2));	// 별의 우하단 삼각형을 찍는 재귀 호출
}
int main() {
	int N;
	int i, j;

	scanf("%d", &N);

	memset(space, ' ', sizeof(space));		// for문보다 memset으로 배열을 초기화 해주면 시간을 단축 할 수 있다고 한다.

	star(N, N - 1, 0);		// 입력받은 N을 넣어 함수 실행

	for (i = 0; i < N; i++) {
		for (j = 0; j < N * 2; j++) {
			printf("%c", space[i][j]);
		}
		printf("\n");
	}			// 별이 그려진 배열 출력
}