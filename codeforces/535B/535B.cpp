#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s;
    cin >> s;

    int n = s.size();
    int ans = 0;
    int x = 1;
    for(int i = 0; i < n - 1; i++)
    {
        x *= 2;
        ans += x;
    }

    x = 1;
    for(int i = n - 1; i >= 0; i--)
    {
        ans += x * (s[i] == '7');
        x *= 2;
    }
    ans += 1;
    cout << ans << endl;
}
