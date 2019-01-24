#include <iostream>

using namespace std;

int main()
{
    int T;

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);
        int *pro = new int[N];

        for (int j = 0; j < N; j++)
            scanf("%d", &pro[j]);

        int count = 0;
        int cost = 0;
        for (int j = 0; j < N; j++)
        {
            if (j == N - 1)
            {
                cost += count * pro[j];
            }
            else
            {
                if (pro[j + 1] < pro[j])
                {
                    cost += count * pro[j];
                    count = 0;
                }
                else
                {
                    cost -= pro[j];
                    count++;
                }
            }
            printf("%d: %d\n", j, cost);
        }
        printf("#%d %d\n", i + 1, cost);
        delete[] pro;
    }
}