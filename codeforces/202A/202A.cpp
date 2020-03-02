#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s; cin >> s;

    int n = s.size();

    string a = "";

    for(int m = 1; m <= (1 << n); m++)
    {
        string c = "";
        for(int j = 0; j < n; j++)
        {
            if(m & (1 << j))
                c += s[j];
        }
        bool f = true;
        int k = c.size();
        for(int i = 0; i < k / 2; i++)
        {
            if(c[i] != c[k - i - 1])
            {
                f = false;
                break;
            }
        }
        if(f)
        {
            // cout << c << endl;
            if(c > a) a = c;
        }
    }
    cout << a << endl;
}
