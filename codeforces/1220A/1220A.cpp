#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int z = 0, o = 0;
    char c;
    while(n--)
    {
        cin >> c;
        if(c == 'z') z++;
        if(c == 'n') o++;
    }
    while(o--) cout << 1 << " ";
    while(z--) cout << 0 << " ";
}
