#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n = 999;
    long long val = (3 * ((n / 3) * (n / 3 + 1)/2)) + (5 * ((n / 5) * (n / 5 + 1)/2)) - (15 * ((n / 15) * (n / 15 + 1)/2));
    cout << val;
}
