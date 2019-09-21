#include <bits/stdc++.h>

using namespace std;

int subarraysDivByK(vector<int>& A, int K)
{
    int n = A.size();
    int k = K;

    int pref[n] = {};
    pref[0] = ((A[0] % k) + k) % k;
    for(int i = 1; i < n; i++)
    {
        pref[i] = (A[i] % k);
        pref[i] += pref[i - 1];
        pref[i] = ((pref[i] % k) + k) % k;
    }

    /*for(int i = 0; i < n; i++)
        cout << pref[i] << endl;*/

    map<int, int> mp;
    mp[0]++;
    for(int i = 0; i < n; i++)
    {
        mp[pref[i]]++;
    }

    int ans = 0;

    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        ans += (it->second)*(it->second - 1)/2;
    }
    return ans;
}

vector<int> A{4, 5, 0, -2, -3, 1};

int main(void)
{
    int K = 5;
    cout << subarraysDivByK(A, K);
    return 0;
}
