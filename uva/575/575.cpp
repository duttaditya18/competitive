#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s;

    while(cin >> s)
    {
        if(s == "0") break;
        int n = s.size();
        long long a = 0;
        for(int i = n - 1; i >= 0; i--) a += (s[i] - '0') * ((1 << n - i) - 1);
        cout << a << "\n";
    }
    return 0;
}
