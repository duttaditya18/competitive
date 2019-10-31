#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s1, s2;

    while(getline(cin, s1))
    {
        getline(cin, s2);

        int n1 = s1.size(), n2 = s2.size();

        int a[n1 + 1][n2 + 1] = {};

        for(int i = 1; i <= n1; i++)
        {
            for(int j = 1; j <= n2; j++)
            {
                if(s1[i - 1] == s2[j - 1]) a[i][j] = a[i - 1][j - 1] + 1;
                else a[i][j] = max(a[i - 1][j], a[i][j - 1]);
            }
        }
        cout << a[n1][n2] << endl;
    }
}

