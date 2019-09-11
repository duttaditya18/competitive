#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, p;
    cin >> n;
    while(n--)
    {
        cin >> p;
        if(p)
        {
            cout << "HARD\n";
            return 0;
        }
    }
    cout << "EASY\n";
    return 0;
}
