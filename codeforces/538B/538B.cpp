#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int cnt = 0;
    vector<int> v;

    string s = to_string(n);

    while(s != "0")
    {
        int x = s.size();

        for(int i = x - 1; i >= 0; i--)
        {
            if(s[i] == '0') continue;
            else if(s[i] == '1') continue;
            else
            {
                for(int j = i; j < x; j++)
                {
                    s[i] = '1';
                }
            }
        }
        cnt++;
        int cur = stoi(s);
        v.push_back(cur);
        n -= cur;
        s = to_string(n);
    }
    cout << cnt << endl;

    for(auto u : v) cout << u << " "; cout << endl;
}
