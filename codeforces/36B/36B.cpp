#include <bits/stdc++.h>

using namespace std;

int a[3][3];
int b[250][250];

void getAns(int x1, int x2, int n, int k)
{
    if(k == 0) return;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j])
            {
                for(int f = x1 + (i * pow(n, k - 1)); f <= x1 + ((i + 1) * pow(n, k - 1)) - 1; f++)
                {
                    for(int g = x2 + (j * pow(n, k - 1)); g <= x2 + ((j + 1) * pow(n, k - 1)) - 1; g++)
                    {
                        b[f][g] = 1;
                    }
                }
            }
            else
            {
                getAns(x1 + (i * pow(n, k - 1)), x2 + (j * pow(n, k - 1)), n, k - 1);
            }
        }
    }
}

int main(void)
{
    #ifdef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    #endif

    int n, k;
    cin >> n >> k;

    char inp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> inp;
            a[i][j] = (inp == '*');
        }
    }

    getAns(1, 1, n, k);

    for(int i = 1; i <= pow(n, k); i++)
    {
        for(int j = 1; j <= pow(n, k); j++)
        {
            cout << (b[i][j] ? "*" : ".");
        }
        cout << endl;
    }
    return 0;
}
