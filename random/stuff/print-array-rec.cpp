#include <bits/stdc++.h>

using namespace std;

int n = 5;

void printArray(int a[], int j)
{
    if(j == n) return;

    cout << a[j];
    printArray(a, j + 1);
}

int main(void)
{
    int a[n] = {1, 2, 3, 4, 5};
    printArray(a, 0);
}
