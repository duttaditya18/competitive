#include <bits/stdc++.h>

using namespace std;

int getAns()
{
    int wl, dl, wr, dr;
    cin >> wl >> dl >> wr >> dr;

    if(!wl) wl = getAns();
    if(!wr) wr = getAns();

    if(!wl) return 0;
    if(!wr) return 0;

    if(wl*dl != wr*dr) return 0;

    return wl + wr;
}

int main(void)
{
    int q;
    cin >> q;

    while(q--)
    {
        int ans = getAns();
        cout << (!ans ? "NO" : "YES") << "\n";
        if(q != 0) cout << "\n";
    }
    return 0;
}
