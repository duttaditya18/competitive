#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s;
    cin >> s;

    int n = s.size();
    int x = 0, y = 0;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'z') x++;
        else y++;
    }
    if(2*x == y) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
