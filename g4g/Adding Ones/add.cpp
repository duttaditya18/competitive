#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n] = {};
        int temp;
        for(int i = 0; i < k; i++)
        {
            cin >> temp;
            a[temp - 1]++;
        }
        cout << a[0] << " ";
        for(int i = 1; i < n; i++)
        {
            a[i] += a[i - 1];
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
