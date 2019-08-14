// Rounding Error

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int n, l;
    cin >> n >> l;

    long double a[n];

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);


    for(int i=0; i<n; i++)
    {
        //cout << a[i] << " ";
    }
    //cout << endl;

    long double diff[n + 1];
    // diff[0] and diff[n] store the space between (start and first) and (last and end) respectively
    diff[0] = a[0];
    diff[n] = l - a[n - 1];

    for(int i = 1; i < n; i++)
    {
        diff[i] = (a[i] - a[i - 1])/2;
    }
    for(int i = 0; i < n + 1; i++)
    {
        //cout << diff[i] << " ";
    }
    sort(diff, diff + n + 1);
    cout << diff[n];


    return 0;
}
