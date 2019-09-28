#include <bits/stdc++.h>

using namespace std;

int a[200000];

int main(void)
{
    int n, h;
    cin >> n >> h;
    for(int i = 0; i < n; i++) cin >> a[i];

    int x = 1, curpos = 0, hasbx = 0;
    while(x != 0)
    {
        cin >> x;
        // move left
        if(x == 1)
        {
            if(curpos == 0) continue;
            else curpos--;
        }
        // move right
        if(x == 2)
        {
            if(curpos == n - 1) continue;
            else curpos++;
        }
        // pickup box
        if(x == 3)
        {
            if(a[curpos] == 0 || hasbx == 1) continue;
            else a[curpos]--, hasbx = 1;
        }
        // drop box
        if(x == 4)
        {
            if(a[curpos] == h || hasbx == 0) continue;
            else a[curpos]++, hasbx = 0;
        }
    }

    for(int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
