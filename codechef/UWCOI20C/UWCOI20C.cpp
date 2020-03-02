#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t; cin >> t;

    while(t--)
    {
        int h, w, q, x, y, z; cin >> h >> w >> q;
        int k;
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                cin >> k;

        while(q--)
        {
            cin >> x >> y >> z;
            if(z > k) cout << (1ll* h * w);
            else cout << 0;
            cout << "\n";
        }
    }
    return 0;
}
