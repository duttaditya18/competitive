#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int q;
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l >> r;

        int x = (r - l) / 2;
        if((l % 2) && (r % 2)) x -= (r);
        else if((l % 2) && !(r % 2)) x += 1;
        else if(!(l % 2) && (r % 2)) x = x - r + l;
        else if(!(l % 2) && !(r % 2)) x += l;
        cout << x << endl;
    }

    return 0;
}
