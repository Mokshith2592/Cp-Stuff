#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    // This is to cal powers of 5 in binary form

    unordered_set<string> power5;
    for (ll x = 1; x <= 1e9; x *= 5)
    {
        long long y = x;
        string bin = "";

        while (y > 0)
        {
            bin = char((y % 2) + '0') + bin;
            y /= 2;
        }
        power5.insert(bin);
    }

    while (!power5.empty())
    {
        cout << *power5.begin() << endl;
        power5.erase(*power5.begin());
    }

    return 0;
}