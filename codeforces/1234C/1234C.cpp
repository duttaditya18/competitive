#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while(q--)
    {
        int n;
        cin >> n;
        char a;
        int x[2][n];
        for(int i = 0; i < n; i++)
        {
            cin >> a;
            if(a == '1' || a == '2') x[0][i] = 0;
            else x[0][i] = 1;
        }
        for(int i = 0; i < n; i++)
        {
            cin >> a;
            if(a == '1' || a == '2') x[1][i] = 0;
            else x[1][i] = 1;
        }

        //for(int i = 0; i < n; i++) cout << x[0][i] << " " << x[1][i] << endl;

        int cur = 0;
        int ans = true;
        for(int i = 0; i < n; i++)
        {
            if(x[cur][i] == 1)
            {
                if(x[!cur][i] == 1) cur = !cur;
                else
                {
                    ans = false;
                    break;
                }
            }
        }

        cout << (ans && cur ? "YES\n" : "NO\n");
    }
    return 0;
}
