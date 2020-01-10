#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;

    int l = 0, r = 0;
    char x;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        if(x == 'L') l++;
        if(x == 'R') r++;
    }
    cout << l + r + 1 << endl;
}
