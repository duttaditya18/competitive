#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int s1, s2, cur1 = 0, cur2 = 0, an = 0;
    int r; cin >> r;

    for(int i = 0; i < r; i++)
    {
        cin >> s1 >> s2;
        cur1 += s1; cur2 += s2;
        if(abs(cur1 - cur2) > abs(an)) an = cur1 - cur2;
    }
    if(an > 0) cout << 1 << " " << an;
    else cout << 2 << " " << abs(an);

    cout << endl;

    return 0;
}
