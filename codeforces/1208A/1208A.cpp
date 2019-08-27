#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        if((n % 3) == 0)
        {
            cout << a;
        }
        else if((n % 3) == 1)
        {
            cout << b;
        }
        else if((n % 3) == 2)
        {
            cout << (a^b);
        }
        cout << endl;
    }
    return 0;
}
