#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;

    int a[n + 1] = {};
    multiset<int> ms;
    multiset<int>::iterator it;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += i;
        ms.insert(a[i]);
    }

    for(int i = 1; i <= n; i++)
    {
        cout << *(ms.rbegin()) + i - 1 << " ";

        // for(auto u : ms) cout << u << " "; cout << endl;

        int x = (n - i + 1);
        ms.erase(ms.find(a[x]));
        a[x] = (a[x] - (n));
        ms.insert(a[x]);
    }
    return 0;
}
