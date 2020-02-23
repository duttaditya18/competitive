#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m; cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        if(!(i % 2)) for(int j = 0; j < m; j++) cout << '#';
        else
        {
            if((i % 4) == 3) cout << '#';
            for(int j = 0; j < m - 1; j++) cout << '.';
            if((i % 4) == 1) cout << '#';
        }
        cout << "\n";
    }
    return 0;
}
