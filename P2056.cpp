#include <iostream>

using namespace std;

int main()
{
    int T;

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int yyyymmdd = 0;
        scanf("%d", &yyyymmdd);

        int yyyy = 0;
        int temp = yyyymmdd % 10000000;
        yyyy += (yyyymmdd / 10000000) * 1000;
        yyyy += (temp / 1000000) * 100;
        temp = temp % 1000000;
        yyyy += (temp / 100000) * 10;
        temp = temp % 100000;
        yyyy += temp / 10000;
        temp = temp % 10000;

        int mm = 0;
        mm += (temp / 1000) * 10;
        temp = temp % 1000;
        mm += (temp / 100);
        temp = temp % 100;

        int dd = temp;

        if ((mm == 1) || (mm == 3) || (mm == 5) || (mm == 7) || (mm == 8) || (mm == 10) || (mm == 12))
        {
            if (dd > 31)
                printf("#%d -1\n", i + 1);
            else
                printf("#%d %04d/%02d/%02d\n", i + 1, yyyy, mm, dd);
        }
        else if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
        {
            if (dd > 30)
                printf("#%d -1\n", i + 1);
            else
                printf("#%d %04d/%02d/%02d\n", i + 1, yyyy, mm, dd);
        }
        else if(mm > 12 || mm < 1)
            printf("#%d -1\n", i + 1);
        else
        {
            if (dd > 28)
                printf("#%d -1\n", i + 1);
            else
                printf("#%d %04d/%02d/%02d\n", i + 1, yyyy, mm, dd);
        }
    }

    return 0;
}