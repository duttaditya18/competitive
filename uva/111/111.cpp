#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int a[n] = {}, x;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    int b[n] = {};

    while(1)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            b[x - 1] = a[i];
            if(cin.eof()) return 0;
        }
        // for(int i = 0; i < n; i++) cout << b[i] << " "; cout << endl;

        vector<int> v;
        vector<int>::iterator it;

        v.push_back(b[0]);

        for(int i = 1; i < n; i++)
        {
            if(v[v.size() - 1] < b[i]) v.push_back(b[i]);
            else
            {
                *lower_bound(v.begin(), v.end(), b[i]) = b[i];
            }
        }

        cout << v.size() << endl;
    }

    return 0;
}
