#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    if(n % 4 == 1 || n % 4 == 2)
    {
        cout << "NO\n";
        return 0;
    }

    cout << "YES" << endl;
    int x = n / 2;

    if(n % 4 == 3)
    {
        cout << x << endl;
        for(int i = 1; i <= x; i++)
        {
            if(!(i % 2))
            {
                cout << i << " " << (n - i) << " ";
            }
        }
        cout << n << endl;
        cout << x + 1 << endl;
        for(int i = 1; i <= x; i++)
        {
            if(i % 2) cout << i << " " << (n - i) << " ";
        }
        cout << endl;
        return 0;
    }

    if(n % 4 == 0)
    {
        cout << x << endl;
        for(int i = 1; i <= x; i++)
        {
            if(i % 2) cout << i << " " << (n - i + 1) << " ";
        }
        cout << endl;
        cout << x << endl;
        for(int i = 1; i <= x; i++)
        {
            if(!(i % 2)) cout << i << " " << (n - i + 1) << " ";
        }
        cout << endl;
        return 0;
    }

}
