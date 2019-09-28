#include <bits/stdc++.h>

using namespace std;

bitset<200000> all;

int main(void)
{
    int n, sum = 0;
    cin >> n;

    int x[n];
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
        sum += x[i];
    }

    all[0] = 1;

    int c = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = sum; j >= x[i]; j--)
        {
            all[j] = all[j] | all[j - x[i]];
        }
    }

    //for(int i = 0; i <= sum; i++) cout << i << " " << all[i] << endl;

    cout << all.count() - 1 << endl;
    for(int i = 1; i <= sum; i++)
    {
        if(all[i] == 1) cout << i << " ";
    }
    cout << endl;
    return 0;
}
