#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int a[n];
    vector<int> m(1, 0), temp;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++)
    {
        temp.clear();
        for(int j = 0, l = m.size(); j < l; j++)
        {
            temp.push_back(m[j] + a[i]);
            temp.push_back(m[j] - a[i]);
        }
        m = temp;
    }

    for(int i = 0, l = m.size(); i < l; i++)
    {
        if((m[i] % 360) == 0)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
