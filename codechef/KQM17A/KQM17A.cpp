#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    string s;
    map<int, int> f1, f2;

    for(int i = 0; i < n; i++)
    {
        cin >> s;
        sort(s.begin(), s.end());
        f1[stoi(s)]++;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        sort(s.begin(), s.end());
        f2[stoi(s)]++;
    }

    if(f1 != f2)
    {
        cout << 0 << "\n";
        return 0;
    }

    int ans = 1;

    for(auto u : f1)
    {
        for(int i = 2; i <= u.second; i++)
        {
            ans *= i;
        }
    }
    cout << ans << "\n";
}
