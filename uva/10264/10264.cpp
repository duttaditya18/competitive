#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, x;
    while(cin >> n)
    {
        int a[1 << n];
        for(int i = 0; i < (1 << n); i++) cin >> a[i];
        int s[1 << n] = {};
        for(int i = 0; i < (1 << n); i++)
            for(int j = 0; j < n; j++)
                s[i] += a[i ^ (1 << j)];

        int ma = INT_MIN;
        for(int i = 0; i < (1 << n); i++)
            for(int j = 0; j < n; j++)
                ma = max(ma, s[i] + s[i ^ (1 << j)]);

        // for(int i = 0; i < (1 << n); i++) cout << bitset<5>(i) << " : " << a[i] << "\n";
        // for(int i = 0; i < (1 << n); i++) cout << bitset<5>(i) << " : " << s[i] << "\n";
        cout << ma << "\n";
    }
    return 0;
}
