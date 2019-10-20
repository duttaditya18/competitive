#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int f = (3 * n);
    int a[f];
    for(int i = 0; i < f; i++) cin >> a[i];
    sort(a, a + f);

    // for(int i = 0; i < f; i++) cout << a[i] << " ";
    // cout << endl;



    int x = 0;
    long long sum = 0;
    for(int i = f - 2; i >= 0; i -= 2)
    {
        x++;
        if(x > n) break;
        sum += 1ll*a[i];
    }
    cout << sum << "\n";
}
