#include <iostream>
#include <string>

using namespace std;

int main()
{
    string problem;

    cin >> problem;
    // scanf("%s", &problem);

    int *answer = new int[problem.length()];

    for (int i = 0; i < problem.length(); i++)
    {
        answer[i] = problem[i] - 'A' + 1;
    }

    for (int i = 0; i < problem.length(); i++)
    {
        printf("%d ", answer[i]);
    }
    printf("\n");
    return 0;
}