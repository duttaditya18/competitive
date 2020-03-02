#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;
    int an = ((1 << int(log10(n))) - 1);
    // cout << an << endl;

    for(int i = (1 << int(log10(n))); i < (1 << (int(log10(n)) + 1)); i++)
    {
        int j = 1;
        int x = 0;
        int k = i;
        while(k > 0)
        {
            x += j * (k % 2);
            k /= 2;
            j *= 10;
        }
        if(n >= x) an++;
        // cout << i << " " << x << "\n";
    }
    cout << an << "\n";
    return 0;
}
