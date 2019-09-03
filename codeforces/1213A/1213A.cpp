#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int a[n], odd = 0, even = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] % 2)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }
    cout << min(odd, even) << endl;
    return 0;
}
