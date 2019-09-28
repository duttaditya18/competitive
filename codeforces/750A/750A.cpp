#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int time = 240 - k;
    int tuse = 0;
    int c = 0;


    for(int i = 1; i <= n; i++)
    {
        //cout << tuse << endl;
        tuse += 5 * i;
        if(tuse > time) break;
        c++;
    }
    cout << c;
}
