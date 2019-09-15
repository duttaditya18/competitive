#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int h[n];
    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    int a[n] = {};
    a[1] = abs(h[1] - h[0]);
    for(int i = 2; i < n; i++)
    {
        a[i] = min((a[i - 1] + abs(h[i] - h[i - 1])), (a[i - 2] + abs(h[i] - h[i - 2])));
    }
    cout << a[n - 1] << endl;
    return 0;
}
