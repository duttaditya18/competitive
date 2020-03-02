#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    ll n;

    while(cin >> n)
    {
        cout << (n) * (n + 1) * (2*n + 1) / 6 << " ";
        cout << (((n + 1) * (n) / 2)*((n + 1) * (n) / 2)) - ((n) * (n + 1) * (2*n + 1) / 6) << " ";
        cout << ((n + 1) * (n + 1) * n * n / 4) << " ";
        cout << (((n) * (n + 1) / 2) * ((n) * (n + 1) / 2) * ((n) * (n + 1) / 2)) - ((n + 1) * (n + 1) * n * n / 4) << " ";
        cout << n * (n + 1) * (2 * n + 1) * (3 * n * n + 3 * n - 1) / 30 << " ";
        cout << (((n) * (n + 1) / 2) * ((n) * (n + 1) / 2) * ((n) * (n + 1) / 2) * ((n) * (n + 1) / 2)) - (n * (n + 1) * (2 * n + 1) * (3 * n * n + 3 * n - 1) / 30);
        cout << "\n";
    }
}
