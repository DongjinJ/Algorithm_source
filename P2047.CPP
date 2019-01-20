#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string problem;

    cin >> problem;

    for (int i = 0; i < problem.size(); i++)
    {
        if (problem[i] >= 'a' && problem[i] <= 'z')
            problem[i] = toupper(problem[i]);
        else
            ;
    }

    printf("%s", problem.c_str());

    return 0;
}