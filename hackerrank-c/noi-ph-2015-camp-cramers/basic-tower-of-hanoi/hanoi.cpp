#include <bits/stdc++.h>

using namespace std;

void f(int n, int x, int y)
{
    int z = 3 - x - y;
    if(n >= 2) f(n-1, x, z);
    cout << "Move from "<<char(x+'A')<<" to "<<char(y+'A')<<".\n";
    if(n >= 2) f(n-1, z, y);
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    int q, n, x, y; cin >> q;
    char c, d;

    while(q--)
    {
        cin >> n >> c >> d;
        x=(c-'A');
        y=(d-'A');
        f(n, x, y);
        cout << "Done!" << "\n";
    }
    return 0;
}
