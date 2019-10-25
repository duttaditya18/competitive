#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    // ifstream cin("in.in");
    int k;
    cin >> k;

    string s;
    cin >> s;

    int n = s.size();
    int curCount = 0;
    vector<int> div;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '0') curCount++;

        if(s[i] == '1' || i == n - 1)
        {
            div.push_back(curCount);
            curCount = 0;
        }
    }

    if(s[n - 1] == '1') div.push_back(0);

    int x = div.size();

    // for(int i = 0; i < div.size(); i++) cout << div[i] << " "; cout << endl; cout << x << endl;

    long long ans = 0;

    if(k == 0)
    {
        for(int i = 0; i < x; i++)
        {
            ans += (1ll * div[i] * (div[i] + 1)) / 2;
        }
        cout << ans << "\n";
        return 0;
    }
    else if(x - 1 < k)
    {
        cout << 0 << "\n";
        return 0;
    }
    else
    {
        for(int i = 0; i < x - k; i++)
        {
            ans += 1ll * (div[i] + 1) * (div[i + k] + 1);
        }
        cout << ans << "\n";
        return 0;
    }

}
