#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s;
    cin >> s;
    int n = s.size();

    for(int i = 0; i < n - 1; i++)
    {
        if(s[i] == 'A' and s[i + 1] == 'C')
        {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
