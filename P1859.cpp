#include <iostream>

using namespace std;

int main()
{
    long long T;

    scanf("%lld", &T);

    for (long long i = 0; i < T; i++)
    {
        long long N;
        scanf("%lld", &N);
        long long *pro = new long long[N];
        long long max = 0;
        long long index = 0;
        for (long long j = 0; j < N; j++)
        {
            scanf("%lld", &pro[j]);
            if (max < pro[j])
            {
                max = pro[j];
                index = j;
            }
        }
        cout << index << endl;

        long long count = 0;
        long long cost = 0;
        if (index + 1 == N)
            cost = pro[index] * (N - 1);
        else
        {
            for (long long j = 0; j < N; j++)
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
        }
        printf("#%d %ld\n", i + 1, cost);
        delete[] pro;
    }
}