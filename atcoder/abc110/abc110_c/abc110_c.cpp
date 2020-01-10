#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.size();

    int mas[26] = {}, mat[26] = {};
    bool f = true;
    for(int i = 0; i < n; i++)
    {
        if(mas[s[i] - 'a'])
        {
            if(mas[s[i] - 'a'] != (t[i] - 'a'))
            {
                f = false;
                break;
            }
        }
        else if(mat[t[i] - 'a'])
        {
            if(mat[t[i] - 'a'] != (s[i] - 'a'))
            {
                f = false;
                break;
            }
        }
        else
        {
            mas[s[i] - 'a'] = t[i] - 'a';
            mat[t[i] - 'a'] = s[i] - 'a';
        }
    }

    cout << (f ? "Yes" : "No") << "\n";
}
