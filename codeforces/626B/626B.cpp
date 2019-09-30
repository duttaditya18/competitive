#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    int r = 0, g = 0, b = 0;
    bool ry = true, gy = true, by = true;
    cin >> n;

    char c;
    for(int i = 0; i < n; i++)
    {
        cin >> c;
        if(c == 'R') r++;
        if(c == 'G') g++;
        if(c == 'B') b++;
    }
    //cout << r << " " << g << " " << b << endl;

    if(r == n) gy = false, by = false;
    if(g == n) ry = false, by = false;
    if(b == n) ry = false, gy = false;

    if(r == n - 1) ry = false;
    if(g == n - 1) gy = false;
    if(b == n - 1) by = false;

    if(by) cout << "B";
    if(gy) cout << "G";
    if(ry) cout << "R";

    return 0;
}
