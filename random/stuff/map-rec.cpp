#include <bits/stdc++.h>

using namespace std;

int n = 5;
int *a = new int[n];

void mapx(int x, int n)
{
    if(n == 0) return;

    a[n - 1] = (x * a[n - 1]);
    mapx(x, n - 1);
}

int main(void)
{
    for(int i = 0; i < n; i++) a[i] = i;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    mapx(2, n);
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}
