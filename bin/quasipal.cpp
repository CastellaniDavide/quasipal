#include <bits/stdc++.h>
using namespace std;
#define DEBUG

int N, M;
vector<string> numbers;
vector< vector<int> > poss;

bool IsPalindrome(vector <int> combinations)
{
    for (size_t i = 0; i < M / 2; ++i)
    {
        for (size_t j = 0; j < N; ++j)
        {
            if (numbers[combinations[i]][j] != numbers[combinations[(M - 1) - i]][j]
                    && numbers[combinations[i]][j] != '0'
                    && numbers[combinations[(M - 1) - i]][j] != '0')
                return false;
        }
    }
    return true;
}

void add_possibility (vector<bool> used, vector <int> last, int u)
{
    if (u == used.size())
    {
        poss.push_back(last);
    }
    else
    {
        for (size_t i = 0; i < used.size(); ++i)
        {
            if (!used[i])
            {
                used[i] = true;
                vector<int> tmp(last);
                tmp.push_back(i);

                add_possibility(used, tmp, u + 1);

                used[i] = false;
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
#ifndef DEBUG
    freopen("output.txt", "w", stdout);
#endif // DEBUG

    cin >> M >> N;
    numbers.resize(M);

    for (size_t i = 0; i < M; ++i)
    {
        cin >> numbers[i];
    }

    vector <bool> tmp (M, false);
    vector <int> tmp2;
    add_possibility(tmp, tmp2, 0);

    for (size_t i = 0; i < poss.size(); ++i)
    {
        if(IsPalindrome(poss[i]) == true)
        {
            for (size_t j = 0; j < M; ++j)
            {
                cout << numbers[poss[i][j]] << endl;
            }
            return 0;
        }
    }
}
