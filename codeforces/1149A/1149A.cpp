#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, sum = 0, one = 0, two = 0;
    cin >> n;
    int t;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        sum += t;
        if(t % 2) one++;
        else two++;
    }

    if(two > 0)
    {
        cout << 2 << " ";
        two--;
    }

    if(one > 0)
    {
        cout << 1 << " ";
        one--;
    }
    for(int i = two; i > 0; i--) cout << 2 << " ";
    for(int i = one; i > 0; i--) cout << 1 << " ";

    cout << endl;

    //cout << one << endl << two << endl << sum;
}
