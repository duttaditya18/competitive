#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    if(n == 1)
    {
        cout << 1 << "\n";
        return 0;
    }

    long long a = 2, b = 1, c;

    for(int i = 0; i < n - 1; i++)
    {
        c = b + a;
        // cout << c << "\n";
        a = b;
        b = c;
    }
    cout << c << "\n";
    return 0;
}
