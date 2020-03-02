#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;

    int i = 1;

    while(n > (5 * i))
    {
        n -= (5 * i);
        i *= 2;
    }

    int j = 1;
    while(n > i)
    {
        n -= i;
        j++;
    }

    if(j == 1) cout << "Sheldon";
    else if(j == 2) cout << "Leonard";
    else if(j == 3) cout << "Penny";
    else if(j == 4) cout << "Rajesh";
    else if(j == 5) cout << "Howard";
    cout << "\n";
    return 0;
}
