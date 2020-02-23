#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    int n; cin >> n;
    int a, b, c;
    bool f = true;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if(i != 0)
        {
            if(max(a, b) <= c)
            {
                c = max(a, b);
                continue;
            }
            else if(min(a, b) <= c)
            {
                c = min(a, b);
                continue;
            }
            else
            {
                f = false;
                break;
            }
        }
        else
        {
            c = max(a, b);
        }
    }
    cout << (f ? "YES" : "NO") << "\n";
}
